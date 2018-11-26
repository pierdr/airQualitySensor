//
//  ViewController.m
//  airQualitySensor
//
//  Created by local on 11/23/18.
//  Copyright © 2018 local. All rights reserved.
//

#import "ViewController.h"
#include <sys/types.h>
#include <sys/sysctl.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self updateData];
    //NSLog(@"IPHONE %f,%f",[UIScreen mainScreen].bounds.size.width,[UIScreen mainScreen].bounds.size.height);
    UIImage* bg;
    if([UIScreen mainScreen].bounds.size.width<=320)
    {
         bg = [UIImage imageNamed:@"background_iphoneSE.png" inBundle:nil compatibleWithTraitCollection:nil];
    }
    else
    {
        bg = [UIImage imageNamed:@"background_iphone7.png" inBundle:nil compatibleWithTraitCollection:nil];
    }
    [_backgroundView setFrame:CGRectMake(0, 0, bg.size.width, bg.size.height)];
    [_backgroundView setClipsToBounds:NO];
    [_backgroundView setContentScaleFactor:UIViewContentModeScaleAspectFill];
    [_backgroundView setImage:bg];
    [_backgroundView setContentScaleFactor:UIViewContentModeScaleAspectFit];
    [_backgroundView setBackgroundColor:[UIColor cyanColor]];
}
- (NSString *) platform
{
    size_t size;
    sysctlbyname("hw.machine", NULL, &size, NULL, 0);
    char *machine = malloc(size);
    sysctlbyname("hw.machine", machine, &size, NULL, 0);
    NSString *platform = [NSString stringWithCString:machine encoding:NSUTF8StringEncoding];
    free(machine);
    return platform;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
-(void) updateData{
    if([[NSUserDefaults standardUserDefaults] objectForKey:@"link"])
    {
        [self loadCSVWithURL:[NSURL URLWithString:[[NSUserDefaults standardUserDefaults] objectForKey:@"link"]]];
    }
    [self performSelector:@selector(updateData) withObject:nil afterDelay:30.0];
}
- (IBAction)didPressChoose:(id)sender
{
    
    [[DBChooser defaultChooser] openChooserForLinkType:DBChooserLinkTypeDirect
                                    fromViewController:self completion:^(NSArray *results)
     {
         if ([results count]>0) {
             for(int i=0;i<[results count];i++)
             {
                 NSLog(@"results: url for %@:%@ ",[[results objectAtIndex:i] name],[[results objectAtIndex:i] link]);
                 
             }
             [[NSUserDefaults standardUserDefaults] setObject:[[[results objectAtIndex:0] link] absoluteString] forKey:@"link"];
             [self loadCSVWithURL:[[results objectAtIndex:0] link]];

         } else {

         }
     }];
}

-(BOOL)loadCSVWithURL:(NSURL*)url
{
    NSURLSessionDataTask *downloadTask = [[NSURLSession sharedSession]
                                          dataTaskWithURL:url completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
                                              
                                              NSHTTPURLResponse* rpsTmp = (NSHTTPURLResponse*)response;
                                              NSLog(@"status: %ld",(long)rpsTmp.statusCode);
                                              if(rpsTmp.statusCode==200)
                                              {
                                                  NSStringEncoding encoding = 0;
                                                  NSString* string = [[NSString alloc] initWithData:data encoding:encoding];
                                              
                                                  [self loadCSVWithString:string];
                                              }
                                              else
                                              {
                                                  UIAlertController * alert = [UIAlertController
                                                                               alertControllerWithTitle:@"Broken Link"
                                                                               message:@"Please reconnect your AIRES file."
                                                                               preferredStyle:UIAlertControllerStyleAlert];
                                                  
                                                  //Add Buttons
                                                  
                                                
                                                  
                                                  UIAlertAction* okButton = [UIAlertAction
                                                                             actionWithTitle:@"OK"
                                                                             style:UIAlertActionStyleDefault
                                                                             handler:^(UIAlertAction * action) {
                                                                                 //Handle no, thanks button
                                                                             }];
                                                  
                                                  //Add your buttons to alert controller
                                                  
                                                  
                                                  [alert addAction:okButton];
                                                  
                                                  [self presentViewController:alert animated:YES completion:nil];
                                                  
                                                  [[NSUserDefaults standardUserDefaults] removeObjectForKey:@"link"];
                                              }
                                          }];
 
    [downloadTask resume];
    return YES;
}
-(void)loadCSVWithString:(NSString*)string{
    _parser = [[CHCSVParser alloc] initWithDelimitedString:string delimiter:'-'];
    
    [_parser setRecognizesBackslashesAsEscapes:YES];
    
    [_parser setSanitizesFields:YES];
    
    NSStringEncoding encoding = 0;
   // NSLog(@"encoding: %@", CFStringGetNameOfEncoding(CFStringConvertNSStringEncodingToEncoding(encoding)));
    [_parser setDelegate:self];
    
    NSTimeInterval start = [NSDate timeIntervalSinceReferenceDate];
    [_parser parse];
    NSTimeInterval end = [NSDate timeIntervalSinceReferenceDate];
    
  //  NSLog(@"raw difference: %f", (end-start));
    
  //  NSLog(@"%lu", (unsigned long)[[self lines] count]);
    
   // NSLog(@"value: %@,%d", [[self lines] objectAtIndex:[[self lines] count]-1][0],[[[self lines] objectAtIndex:[[self lines] count]-1][1] intValue]);
    _PPM2_5 = [[[self lines] objectAtIndex:[[self lines] count]-1][1] intValue];
               _timeStamp = [[self lines] objectAtIndex:[[self lines] count]-1][0];
    dispatch_async(dispatch_get_main_queue(), ^{
//        [self->_valueLabel setText:[[self lines] objectAtIndex:[[self lines] count]-1][1]];
//        [self->_timeStampLabel setText:[[self lines] objectAtIndex:[[self lines] count]-1][0]];
        [self updateUI];
    });
    
}
-(void)updateUI{
    
    [self->_valueLabel setText:[NSString stringWithFormat:@"%d",_PPM2_5]];
    NSArray *myWords = [_timeStamp componentsSeparatedByCharactersInSet:
                        [NSCharacterSet characterSetWithCharactersInString:@", at "]];
    
    _timeStamp = myWords[7];
    
    [self->_timeStampHoursLabel setText:_timeStamp];
    [self->_timeStampDayLabel setText: [NSString stringWithFormat:@"%@ %@",myWords[1],myWords[0]]];
    
    //
    [UIView animateWithDuration:0.5 animations:^{
        [_backgroundView setFrame:CGRectMake(0, map(_PPM2_5,0,500,-(_backgroundView.bounds.size.height-[UIScreen mainScreen].bounds.size.height),0), _backgroundView.bounds.size.width, _backgroundView.bounds.size.height)];
    } completion:^(BOOL finished) {
        
    }];
    
}
#pragma mark CSV PARSER
- (void)parserDidBeginDocument:(CHCSVParser *)parser {
    _lines = [[NSMutableArray alloc] init];
}
- (void)parser:(CHCSVParser *)parser didBeginLine:(NSUInteger)recordNumber {
    _currentLine = [[NSMutableArray alloc] init];
}
- (void)parser:(CHCSVParser *)parser didReadField:(NSString *)field atIndex:(NSInteger)fieldIndex {
    //NSLog(@"%@", field);
    [_currentLine addObject:field];
}
- (void)parser:(CHCSVParser *)parser didEndLine:(NSUInteger)recordNumber {
    [_lines addObject:_currentLine];
    _currentLine = nil;
}
- (void)parserDidEndDocument:(CHCSVParser *)parser {
    //    NSLog(@"parser ended: %@", csvFile);
}
- (void)parser:(CHCSVParser *)parser didFailWithError:(NSError *)error {
    NSLog(@"ERROR: %@", error);
    _lines = nil;
}

#pragma mark utils
float map(long x, long in_min, long in_max, long out_min, long out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

@end
