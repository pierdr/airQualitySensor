//
//  ViewController.m
//  ledPanelDeamon
//
//  Created by Pierluigi Dalla Rosa on 4/16/17.
//  Copyright © 2017 pierdr. All rights reserved.
//

#import "ViewController.h"


@implementation ViewController
{
    int dataToDraw[32][32][3];
}

@synthesize serial;

- (void)viewDidLoad {
    [super viewDidLoad];
    [self availablePorts];
    [self connectSerialPort];
    _stopped = NO;
   
    _bufferString = [[NSMutableString alloc] initWithString:@""];
    if([[NSUserDefaults standardUserDefaults] objectForKey:@"pathName"]!=nil)
    {
        _savePath= [[NSUserDefaults standardUserDefaults]valueForKey:@"pathName"];
    }
    else{
        _savePath = [NSHomeDirectory() stringByAppendingPathComponent:@"Downloads"]; //get tmp path
    }
    _pathControl.URL=[[NSURL alloc] initWithString:_savePath];
    _pathControl.delegate = self;
    
     _autoconnect = YES;
    
    _endingSequence = @"F";
    
    //BAUDRATES
    _baudRate = 115200;
    NSMenu* menuTmp = [NSApp mainMenu];
    NSMenu* mi = [menuTmp.itemArray objectAtIndex:3].submenu;
    [mi removeAllItems];
   
    for(int i=0;i<BAUDRATES.count;i++)
    {
        [mi addItemWithTitle:[NSString stringWithFormat:@"%d",[BAUDRATES[i] intValue]] action:@selector(changeBaudRate:) keyEquivalent:@""];
        [mi itemAtIndex:i].tag = i;
        [[mi itemAtIndex:i] setState:(_baudRate == [BAUDRATES[i] intValue])?NSOnState:NSOffState];
    }
    [mi update];
    [self routineUpdateSerial];
    //DISCONNECT
    mi = [menuTmp.itemArray objectAtIndex:1].submenu;
    
    //_disconnectItem = [ mi insertItemWithTitle:@"Disconnect" action:@selector(disconnect:)  keyEquivalent:@"" atIndex:0];
}
- (IBAction)showPathOpenPanel:(id)sender
{
    // Create the File Open Dialog class.
    NSOpenPanel* openDlg = [NSOpenPanel openPanel];
    
    // Enable the selection of files in the dialog.
    [openDlg setCanChooseFiles:NO];
    
    // Enable the selection of directories in the dialog.
    [openDlg setCanChooseDirectories:YES];
    [openDlg setAllowsMultipleSelection:NO];
    if(![_savePath isEqualToString:@""])
    {
        [openDlg setDirectoryURL:[NSURL URLWithString:_savePath]];
    }
    // Display the dialog.  If the OK button was pressed,
    // process the files.
    NSArray* files;
    if ( [openDlg runModal] == NSModalResponseOK )
    {
        // Get an array containing the full filenames of all
        // files and directories selected.
        files= [openDlg filenames];
    }
    
    _savePath = [[openDlg filenames] objectAtIndex:0];
     [[NSUserDefaults standardUserDefaults] setValue:_savePath forKey:@"pathName"];
    
}
- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}

#pragma mark INTERFACE METHODS
-(void)printInfo:(NSString*)message{
    [_infoLabel setStringValue:message];
}
-(IBAction)changeBaudRate:(id)sender{
    [self setBaud:(int)((NSMenuItem*)sender).tag];
}
-(void)updateSerialPorts{
    NSMenu* menuTmp = [NSApp mainMenu];
    NSMenu* mi = [menuTmp.itemArray objectAtIndex:2].submenu;

    [mi removeAllItems];
    NSArray* avPortsTmp = [self availablePorts];
    for(int i=0;i<avPortsTmp.count;i++)
    {
        [mi addItemWithTitle:[NSString stringWithFormat:@"%@",[[avPortsTmp objectAtIndex:i] name]] action:@selector(changePort:) keyEquivalent:@""];
        [mi itemAtIndex:i].tag = i;
    }
    if([serial isOpen])
    {
        [self setSerialPortSelectedInMenu];
    }
    [mi update];
    
}
-(void)routineUpdateSerial{
    [self updateSerialPorts];
    [self performSelector:@selector(routineUpdateSerial) withObject:nil afterDelay:2.0];
}
-(void)changePort:(id)sender
{
    NSLog(@"new stuff");
    _autoconnect = false;
    NSArray* avPortsTmp = [self availablePorts];
    _portName=[[avPortsTmp objectAtIndex:((NSMenuItem*)sender).tag] name];
    
    if([serial isOpen])
    {
        [serial close];
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 2 * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
            [self connectSerialPort];
        });
        
    }
}
-(void)setSerialPortSelectedInMenu:(int)tag{
    NSMenu* menuTmp = [NSApp mainMenu];
    NSMenu* mi = [menuTmp.itemArray objectAtIndex:3].submenu;
    mi = [menuTmp.itemArray objectAtIndex:2].submenu;
    
    for(int i=0;i<[mi itemArray].count;i++)
    {
        if(i==tag)
        {
            [[mi itemAtIndex:i] setState:NSOnState];
        }
        else
        {
             [[mi itemAtIndex:i] setState:NSOffState];
        }
    }
    
    [mi update];
}
-(void)setSerialPortSelectedInMenu{
    NSMenu* menuTmp = [NSApp mainMenu];
    NSMenu* mi = [menuTmp.itemArray objectAtIndex:3].submenu;
    mi = [menuTmp.itemArray objectAtIndex:2].submenu;
    
    for(int i=0;i<[mi itemArray].count;i++)
    {
        if([[[mi itemAtIndex:i] title] isEqualToString:_portName])
        {
            [[mi itemAtIndex:i] setState:NSOnState];
        }
        else
        {
            [[mi itemAtIndex:i] setState:NSOffState];
        }
    }
    
    [mi update];

}
#pragma mark SERIAL
-(void)disconnect:(id)sender{
    [serial close];
    [self setAutoConnect:NO];
    _stopped = YES;
}

-(void)setAutoConnect:(BOOL)autoconnect{
    _autoconnect = autoconnect;
}
-(void)setBaud:(int)baudIndex{
    if(_baudRate == [BAUDRATES[baudIndex] intValue])
    {
        return;
    }
    _baudRate = [BAUDRATES[baudIndex] intValue];
    
    NSMenu* menuTmp = [NSApp mainMenu];
    NSMenu* mi = [menuTmp.itemArray objectAtIndex:3].submenu;
    
    for(int i=0;i<BAUDRATES.count;i++)
    {
        [[mi itemAtIndex:i] setState:(_baudRate == [BAUDRATES[i] intValue])?NSOnState:NSOffState];
    }
    if([serial isOpen])
    {
        [serial close];
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 2 * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
            [self connectSerialPort];
        });
       
    }
}
-(void)setPortName:(NSString*)portAddress{
    
}
-(void)connectSerialPort{
    
    if(_stopped)
    {
        _stopped = NO;
        return;
    }
    if(![serial isOpen])
    {
        [self updateSerialPorts];
        NSArray* avPortsTmp = [self availablePorts];
        for(int i=0; i< [avPortsTmp count]; i++)
        {
           
            if(_autoconnect && [[[avPortsTmp objectAtIndex:i] description] containsString:@"usbmodem"])
            {
                [self setupSerial:i withBaud:_baudRate];
                _portName = [[avPortsTmp objectAtIndex:i] name];
                [self setSerialPortSelectedInMenu:i];
                break;
            }
            if(!_autoconnect && [[[avPortsTmp objectAtIndex:i] name] isEqualToString:_portName])
            {
                [self setupSerial:i withBaud:_baudRate];
                [self setSerialPortSelectedInMenu:i];
            }
        }
        
        [self performSelector:@selector(connectSerialPort) withObject:nil afterDelay:2.0];
    }
    else{
        
    }
}

-(void)serialPortWasRemovedFromSystem:(ORSSerialPort *)serialPort{
        [self printInfo:[NSString stringWithFormat:@"serial port %@ removed from system",[serialPort description]]];
    
}
- (void)serialPortWasOpened:(ORSSerialPort *)serialPort{
    [self printInfo:[NSString stringWithFormat:@"serial port %@ opened",[serialPort description]]];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"statusUpdate" object:nil];
//    [_disconnectItem setState:NSOffState];
//    [_disconnectItem setEnabled:YES];
    NSLog(@"opened");
}
- (void)serialPortWasClosed:(ORSSerialPort *)serialPort{
    [self printInfo:[NSString stringWithFormat:@"serial port %@ closed",[serialPort description]]];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 2 * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
        [self connectSerialPort];
    });
    
    [[NSNotificationCenter defaultCenter] postNotificationName:@"statusUpdate" object:nil];
    [_disconnectItem setEnabled:NO];
     NSLog(@"closeds");
}

-(void) setupSerial:(int) address withBaud:(int) baud{
    //serial = [ORSSerialPort serialPortWithPath:address];
    serial=[[ORSSerialPortManager sharedSerialPortManager] availablePorts][address];
    serial.baudRate = [NSNumber numberWithInt:baud];
    serial.parity = ORSSerialPortParityNone;
    serial.numberOfStopBits = 1;
    serial.usesRTSCTSFlowControl = YES;
    serial.delegate=self;
    [serial open];
}
-(NSArray*)availablePorts{
    //NSLog(@"%@",[[ORSSerialPortManager sharedSerialPortManager] availablePorts]);
    return   [[ORSSerialPortManager sharedSerialPortManager] availablePorts];
}
-(void)send:(NSString*)message{
    NSData *dataToSend = [message dataUsingEncoding:NSUTF8StringEncoding];
    [serial sendData:dataToSend];
}
- (void)serialPort:(ORSSerialPort *)serialPort didReceiveData:(NSData *)data
{

    NSMutableString *string = [[NSMutableString alloc] initWithData:data encoding:NSUTF8StringEncoding];
     NSError *error;
    NSLog(@"%@",_bufferString );
    if([string containsString:_endingSequence])
    {
        if([string isEqualToString:_endingSequence])
        {
            _bufferString = [[NSMutableString alloc] initWithString:@""];
            return;
        }
        [_dataLabel setStringValue:string];
        [_bufferString appendString:string];
        NSLog(@"%@",_bufferString);
        
        
       // _pathControl.URL=[[NSURL alloc] initWithString:_savePath];
        NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
        
        NSTimeZone *timeZone = [NSTimeZone timeZoneWithName:@"US/Pacific"];
        
        [dateFormatter setTimeZone:timeZone];
        
        [dateFormatter setDateFormat:@"MM/dd/YYYY HH:mm:ss,"];
        
        NSString *dateString = [dateFormatter stringFromDate:[NSDate date]];
        [dateFormatter setDateFormat:@"MMddyy"];
        NSString *ddmmyyString = [dateFormatter stringFromDate:[NSDate date]];
        
        NSString *filePath = [_savePath stringByAppendingPathComponent:[NSString stringWithFormat:@"%@.csv",ddmmyyString]];
        
        _bufferString = (NSMutableString*)[_bufferString stringByReplacingOccurrencesOfString:@"\n" withString:@""];
        _bufferString = (NSMutableString*)[_bufferString stringByReplacingOccurrencesOfString:_endingSequence withString:@""];
        
        string = [NSMutableString stringWithFormat:@"%@%@%@%@",[NSString stringWithContentsOfFile:filePath encoding:NSUTF8StringEncoding error:&error],([string containsString:_endingSequence])?@"\n":@"",([string containsString:_endingSequence])?dateString:@"",_bufferString];
        
        [string writeToFile:filePath atomically:YES encoding:NSUTF8StringEncoding error:&error];
        _bufferString = [[NSMutableString alloc] initWithString:@""];
        if(error!=nil)
        {
            NSLog(@"%@",error);
        }
    }
    else
    {
        if(![string isEqualToString:@""] && ![string isEqualToString:@"\n`"])
        {
            [_bufferString appendString:string];
        }
    }
}


@end
