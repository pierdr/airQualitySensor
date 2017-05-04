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


@interface ViewController : NSViewController<ORSSerialPortDelegate>


@property (strong,nonatomic) ORSSerialPort* serial;

@property (strong,nonatomic)IBOutlet NSTextField*               infoLabel;
@property (strong,nonatomic)IBOutlet NSTextField*               dataLabel;


#pragma mark INTERFACE METHODS
-(void)printInfo:(NSString*)message;

#pragma mark SERIAL
-(void)connectSerialPort;
-(void)serialPortWasRemovedFromSystem:(ORSSerialPort *)serialPort;
- (void)serialPortWasOpened:(ORSSerialPort *)serialPort;
- (void)serialPortWasClosed:(ORSSerialPort *)serialPort;
-(void) setupSerial:(int) address withBaud:(int) baud;
-(NSArray*)availablePorts;
-(void)send:(NSString*)message;
- (void)serialPort:(ORSSerialPort *)serialPort didReceiveData:(NSData *)data;








@end

