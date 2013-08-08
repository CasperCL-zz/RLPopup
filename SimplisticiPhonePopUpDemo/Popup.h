//
//  Popup.h
//  AH Plaza
//
//  Created by Casper Eekhof on 08-08-13.
//  Copyright (c) 2013 JTC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Popup : NSObject

@property UIView *displayView;

@property UIView *popUpView;
@property UIView *background;
@property UIView *dialog;
@property UIActivityIndicatorView * activityIndicator;
@property UILabel *dialogLabel;
@property UIButton *button1;
@property UIButton *button2;

typedef enum {
    OKAY = 1,
    CANCELED = !OKAY
} RESULT;

- (id) initWithView: (UIView*) view;

- (void) hidePopupWithAnimationDuration:(float) duration;

- (void) showPopupWithAnimationDuration:(float) duration withText: (NSString*) text;
- (void) showPopupWithAnimationDuration:(float) duration withActivityIndicatorAndText: (NSString*) text;
- (RESULT) showPopupWithAnimationDuration:(float) duration withText: (NSString*) text withButtonText: (NSString*) buttonText;
- (RESULT) showPopupWithAnimationDuration:(float) duration withText: (NSString*) text withButton1Text: (NSString*) button1Text withButton2Text: (NSString*) button2Text;

@end
