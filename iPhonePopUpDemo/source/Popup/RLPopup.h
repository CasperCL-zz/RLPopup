//
//  Popup.h
//  AH Plaza
//
//  Created by Casper Eekhof on 08-08-13.
//  Copyright (c) 2013 Redlake. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RLPopup;

typedef enum {
    OKAY = 1,
    CANCELED = !OKAY
} RESULT;

typedef void(^RLPopupResult)(RESULT);
typedef void(^onCompletion)(BOOL finished);

/**
 * The RLPopup provides an open customizable interface to create dynamic popups to the user.
 * The RLPopup can provide the following popups:
 * 1. Text only
 * 2. Loading indicator and message
 * 3. Confirm message
 * 4. Yes/No questions
 */
@interface RLPopup : NSObject  {
    
    // The root view containing the background and the dialog view.
    UIView *popUpView;
    // The background behind the dialog.
    UIView *background;
    // The dialog view
    UIView *dialog;
    // The activity indicator
    UIActivityIndicatorView * activityIndicator;
    // The text label of the dialog
    UILabel *dialogLabel;
    // The most left button
    UIButton *button1;
    // The most right button (only available when Yes/No)
    UIButton *button2;
    //
    RLPopupResult resultCallback;
    
    float backgroundAlpha;
}

- (void) setButton1BackgroundImage: (UIImage*) image forState:(UIControlState) controlState;
- (void) setButton2BackgroundImage: (UIImage*) image forState:(UIControlState) controlState;

- (void) hidePopupWithAnimationDuration:(float) duration onCompletion:(onCompletion) completion;

- (void) showPopupWithAnimationDuration:(float) duration withText: (NSString*) text onCompletion:(onCompletion) completion;
- (void) showPopupWithAnimationDuration:(float) duration withActivityIndicatorAndText: (NSString*) text onCompletion:(onCompletion) completion;
- (void) showPopupWithAnimationDuration:(float) duration withText: (NSString*) text withButtonText: (NSString*) buttonText withResult: (RLPopupResult) result onCompletion:(onCompletion) completion;
- (void) showPopupWithAnimationDuration:(float) duration withText: (NSString*) text withButton1Text: (NSString*) button1Text withButton2Text: (NSString*) button2Text withResult: (RLPopupResult) result onCompletion:(onCompletion) completion;

- (void) setFont:(NSString*) fontName;
- (void) setTextColor:(UIColor*) color;

@end
