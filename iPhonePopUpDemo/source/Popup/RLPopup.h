//
//  Popup.h
//  AH Plaza
//
//  Created by Casper Eekhof on 08-08-13.
//  Copyright (c) 2013 Redlake. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RLPopup;

/** An enum indicating the result of an RLPopup **/
typedef enum {
    OKAY = 1,
    CANCELED = !OKAY
} RESULT;

/** A RLPopupResult indicating the result of an RLPopup **/
typedef void(^RLPopupResult)(RESULT);
/** A UIView animation block **/
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

/**
 * Hides the dialog in a specified amount of time.
 * @param duration of the hide animation.
 * @param completion block that is excuted after the animation.
 */
- (void) hidePopupWithAnimationDuration:(float) duration onCompletion:(onCompletion) completion;

/**
 * Builds and shows a popup with text.
 * @param duration of the show animation.
 * @param text the text to display.
 * @param completion block that is excuted after the animation.
 */
- (void) showPopupWithAnimationDuration:(float) duration withText: (NSString*) text onCompletion:(onCompletion) completion;

/**
 * Builds and shows a popup with a loading indicator and text.
 * @param duration of the show animation.
 * @param text the text to display.
 * @param completion block that is excuted after the animation.
 */
- (void) showPopupWithAnimationDuration:(float) duration withActivityIndicatorAndText: (NSString*) text onCompletion:(onCompletion) completion;

/**
 * Builds and shows a popup with a confirm message and text.
 * @param duration of the show animation.
 * @param text the text to display.
 * @param buttonText the text on the button
 * @param result a block returing a value indicating a button is pressed.
 * @param completion block that is excuted after the animation.
 */
- (void) showPopupWithAnimationDuration:(float) duration withText: (NSString*) text withButtonText: (NSString*) buttonText withResult: (RLPopupResult) result onCompletion:(onCompletion) completion;

/**
 * Builds and shows a popup with a YES/NO message and text.
 * @param duration of the show animation.
 * @param text the text to display.
 * @param button1Text the text on the left button
 * @param button2Text the text on the right button
 * @param result a block returing a value indicating a button is pressed.
 * @param completion block that is excuted after the animation.
 */
- (void) showPopupWithAnimationDuration:(float) duration withText: (NSString*) text withButton1Text: (NSString*) button1Text withButton2Text: (NSString*) button2Text withResult: (RLPopupResult) result onCompletion:(onCompletion) completion;


/**
 *************************************************
 *Customize methods. Used to customize the dialog*
 *************************************************
 */

/**
 * Sets the background image for the most left button.
 * @param color to set.
 * @param controlState of the button with the image.
 */
- (void) setButton1BackgroundColor: (UIColor*) color;

/**
 * Sets the background image for the most right button.
 * @param color to set.
 * @param controlState of the button with the image.
 */
- (void) setButton2BackgroundColor: (UIColor*) color;

/**
 * Sets the background image for the most left button.
 * @param image to set.
 * @param controlState of the button with the image.
 */
- (void) setButton1BackgroundImage: (UIImage*) image forState:(UIControlState) controlState;

/**
 * Sets the background image for the most right button.
 * @param image to set.
 * @param controlState of the button with the image.
 */
- (void) setButton2BackgroundImage: (UIImage*) image forState:(UIControlState) controlState;

/**
 * Sets the font of the dialog
 * @param the font name to set.
 */
- (void) setFont:(NSString*) fontName;

/**
 * Sets the color of the message.
 * @param color to set to the text.
 */
- (void) setTextColor:(UIColor*) color;

@end
