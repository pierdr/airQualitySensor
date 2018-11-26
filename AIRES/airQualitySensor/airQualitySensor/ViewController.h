//
//  ViewController.h
//  airQualitySensor
//
//  Created by local on 11/23/18.
//  Copyright © 2018 local. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <DBChooser/DBChooser.h>
#import "CHCSVParser.h"


@interface ViewController : UIViewController<CHCSVParserDelegate>
@property (strong,nonatomic) NSMutableArray*    lines;
@property (strong,nonatomic) NSMutableArray*    currentLine;
@property (strong,nonatomic) CHCSVParser*       parser;
@property (strong,nonatomic) NSMutableData*     fileData;

@property (strong,nonatomic) IBOutlet UIImageView*       backgroundView;
@property (strong,nonatomic) IBOutlet UILabel* valueLabel;
@property (strong,nonatomic) IBOutlet UILabel* timeStampHoursLabel;
@property (strong,nonatomic) IBOutlet UILabel* timeStampDayLabel;

@property (assign) int PPM2_5;
@property (strong,nonatomic) NSString* timeStamp;

- (IBAction)didPressChoose:(id)sender;

@end

