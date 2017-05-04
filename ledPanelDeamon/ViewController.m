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
   
    _bufferString = [[NSMutableString alloc] initWithString:@""];
    
   
}

- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}

#pragma mark INTERFACE METHODS
-(void)printInfo:(NSString*)message{
    [_infoLabel setStringValue:message];
}

#pragma mark SERIAL
-(void)connectSerialPort{
    if(![serial isOpen])
    {
        NSArray* avPortsTmp = [self availablePorts];
        for(int i=0; i< [avPortsTmp count]; i++)
        {
           
            if([[[avPortsTmp objectAtIndex:i] description] containsString:@"usbmodem"])
            {
                [self setupSerial:i withBaud:115200];
                break;
            };
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
}
- (void)serialPortWasClosed:(ORSSerialPort *)serialPort{
    [self printInfo:[NSString stringWithFormat:@"serial port %@ closed",[serialPort description]]];
    [self connectSerialPort];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"statusUpdate" object:nil];
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
    
    if([string containsString:@"F"])
    {
        [_dataLabel setStringValue:string];
        [_bufferString appendString:string];
        NSLog(@"%@",_bufferString);
        
        NSString *path = [NSHomeDirectory() stringByAppendingPathComponent:@"tmp"]; //get tmp path
        NSString *filePath = [path stringByAppendingPathComponent:@"data1.txt"];
        NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
        
        NSTimeZone *timeZone = [NSTimeZone timeZoneWithName:@"US/Pacific"];
        
        [dateFormatter setTimeZone:timeZone];
        
        [dateFormatter setDateFormat:@"[MMdd_HHmmss]"];
        
        NSString *dateString = [dateFormatter stringFromDate:[NSDate date]];
        string = [NSMutableString stringWithFormat:@"%@%@%@%@",[NSString stringWithContentsOfFile:filePath encoding:NSUTF8StringEncoding error:&error],([string containsString:@"F"])?@"\n":@"",([string containsString:@"F"])?dateString:@"",_bufferString];
        
        [string writeToFile:filePath atomically:YES encoding:NSUTF8StringEncoding error:&error];
        _bufferString = [[NSMutableString alloc] initWithString:@""];
    }
    else
    {
        [_bufferString appendString:string];
    }
}


@end
