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

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    Popup *popup = [[Popup alloc] initWithView: self.view];
//    [popup showPopupWithAnimationDuration:1.0 withText:@"test"];
//    [popup showPopupWithAnimationDuration: 1.0 withActivityIndicatorAndText:@"Je gegevens worden geladen"];
    [popup showPopupWithAnimationDuration: 1.0 withText:@"Je inloggegevens zijn incorrect. Of je wachtwoord is onjuist of je gebruikersnaam is onjuist. " withButtonText: @"OK"];
    [popup showPopupWithAnimationDuration:1.0 withText:@"Je inloggegevens zijn incorrect. Of je wachtwoord is onjuist of je gebruikersnaam is onjuist. Wil je deze aanpassen?" withButton1Text:@"Ja" withButton2Text:@"Nee"];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
