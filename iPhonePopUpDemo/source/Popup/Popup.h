//
//  Popup.h
//  AH Plaza
//
//  Created by Casper Eekhof on 08-08-13.
//  Copyright (c) 2013 JTC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Popup;
typedef enum {
    OKAY = 1,
    CANCELED = !OKAY
} RESULT;

typedef void(^result)(RESULT);
typedef void(^onCompletion)(BOOL finished);

@interface Popup : NSObject  {
    UIView *displayView;
    
    UIView *popUpView;
    UIView *background;
    UIView *dialog;
    UIActivityIndicatorView * activityIndicator;
    UILabel *dialogLabel;
    UIButton *button1;
    UIButton *button2;
    result resultCallback;
    
    float backgroundAlpha;
}


- (id) initWithView: (UIView*) view;

- (void) setButton1BackgroundImage: (UIImage*) image forState:(UIControlState) controlState;
- (void) setButton2BackgroundImage: (UIImage*) image forState:(UIControlState) controlState;

- (void) hidePopupWithAnimationDuration:(float) duration onCompletion:(onCompletion) completion;

- (void) showPopupWithAnimationDuration:(float) duration withText: (NSString*) text onCompletion:(onCompletion) completion;
- (void) showPopupWithAnimationDuration:(float) duration withActivityIndicatorAndText: (NSString*) text onCompletion:(onCompletion) completion;
- (void) showPopupWithAnimationDuration:(float) duration withText: (NSString*) text withButtonText: (NSString*) buttonText withResult: (result) result onCompletion:(onCompletion) completion;
- (void) showPopupWithAnimationDuration:(float) duration withText: (NSString*) text withButton1Text: (NSString*) button1Text withButton2Text: (NSString*) button2Text withResult: (result) result onCompletion:(onCompletion) completion;

- (void) setFont:(NSString*) fontName;
- (void) setTextColor:(UIColor*) color;

@end
