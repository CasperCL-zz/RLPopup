//
//  ViewController.m
//  test
//
//  Created by Casper Eekhof on 08-08-13.
//  Copyright (c) 2013 JTC. All rights reserved.
//

#import "ViewController.h"
#import "Popup.h"

@interface ViewController ()

@end

@implementation ViewController
Popup *popup;

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    popup = [[Popup alloc] initWithView: self.view];
    [self showAllPopups];
}

- (void) showAllPopups {
    [popup showPopupWithAnimationDuration:1.0 withText:@"Sample message" onCompletion:^(BOOL finished) {
        [popup hidePopupWithAnimationDuration:1.0 onCompletion:^(BOOL finished) {
            [popup showPopupWithAnimationDuration: 1.0 withActivityIndicatorAndText:@"Loading your data"onCompletion:^(BOOL finished) {
                [popup hidePopupWithAnimationDuration:1.0 onCompletion:^(BOOL finished) {
                    [popup showPopupWithAnimationDuration: 1.0 withText:@"Your credentials are incorrect. Either your username or your password is incorrect. " withButtonText: @"OK"withResult:^(RESULT r) {
                        switch (r) {
                            case OKAY:
                                NSLog(@"Okay");
                                break;
                            case CANCELED:
                            default:
                                NSLog(@"Canceled action");
                                break;
                        }
                    } onCompletion:^(BOOL finished) {
                        [popup hidePopupWithAnimationDuration:1.0 onCompletion:^(BOOL finished) {
                            [popup showPopupWithAnimationDuration:1.0 withText:@"Are you sure?" withButton1Text:@"Yes" withButton2Text:@"No" withResult:^(RESULT r) {
                                switch (r) {
                                    case OKAY:
                                        NSLog(@"Okay");
                                        break;
                                    case CANCELED:
                                    default:
                                        NSLog(@"Canceled action");
                                        break;
                                }
                            } onCompletion:^(BOOL finished) {}];
                        }];
                    }];
                }];
            }];
        }];
    }];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
