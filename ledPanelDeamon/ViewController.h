//
//  ViewController.h
//  ledPanelDeamon
//
//  Created by Pierluigi Dalla Rosa on 4/16/17.
//  Copyright © 2017 pierdr. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "ORSSerialPort.h"
#import "ORSSerialPortManager.h"

#define SENDING 1
#define IDLE    0
#define WAIT    2

#define BAUDRATES @[@4800,@9600,@14400,@19200,@28800,@57600,@115200]

@interface ViewController : NSViewController<ORSSerialPortDelegate,NSPathControlDelegate>


@property (strong,nonatomic) ORSSerialPort* serial;

@property (strong,nonatomic)IBOutlet NSTextField*               infoLabel;
@property (strong,nonatomic)IBOutlet NSTextField*               dataLabel;

@property (strong,nonatomic)NSMutableString*                    bufferString;

@property (strong,nonatomic) IBOutlet NSPathControl*             pathControl;
@property (strong,nonatomic) NSString*                           savePath;

@property (strong,nonatomic) NSString*                          endingSequence;

@property (strong,nonatomic) NSMenuItem*                        disconnectItem;

@property (assign) BOOL stopped;

#pragma mark INTERFACE METHODS
- (void)printInfo:(NSString*)message;
- (IBAction)showPathOpenPanel:(id)sender;


#pragma mark SERIAL

@property (strong,nonatomic) NSString*  portName;
@property (assign) BOOL                 autoconnect;
@property (assign) int                  baudRate;



-(void)disconnect:(id)sender;
-(void)setAutoConnect:(BOOL)autoconnect;
-(IBAction)changeBaudRate:(id)sender;
-(void)setBaud:(int)baudIndex;
-(void)setPortName:(NSString*)portAddress;

-(void)setSerialPortSelectedInMenu:(int)tag;
-(void)connectSerialPort;
-(void)serialPortWasRemovedFromSystem:(ORSSerialPort *)serialPort;
- (void)serialPortWasOpened:(ORSSerialPort *)serialPort;
- (void)serialPortWasClosed:(ORSSerialPort *)serialPort;
-(void) setupSerial:(int) address withBaud:(int) baud;
-(NSArray*)availablePorts;
-(void)send:(NSString*)message;
- (void)serialPort:(ORSSerialPort *)serialPort didReceiveData:(NSData *)data;








@end

