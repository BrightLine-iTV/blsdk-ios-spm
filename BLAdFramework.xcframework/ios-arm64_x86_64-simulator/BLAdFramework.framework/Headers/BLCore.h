/*************************************************************************
 * BRIGHTLINE CONFIDENTIAL
 * ___________________
 *
 *  Copyright 2015 Brightline Partners LLC
 *  All Rights Reserved.
 *
 * NOTICE:  All information contained herein is, and remains
 * the property of Brightline Partners LLC and its suppliers,
 * if any.  The intellectual and technical concepts contained
 * herein are proprietary to Brightline Partners LLC and its
 * suppliers and are protected by all applicable intellectual property
 * laws, including trade secret and copyright laws.
 * Dissemination of this information or reproduction of this material
 * is strictly forbidden unless prior written permission is obtained
 * from Brightline Partners LLC.
 **************************************************************************/

#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>

#import "BLCoreEvents.h"

/*
 
   * class: BLCore
 
   * description:  The BLCore represents a singleton class that is used to initialize the SDK and render the BrightLine Ad experience

 */

@interface BLCore : NSObject {
    
}

/* 
 
    * method: sharedManager
 
    * description: represents single instance of the BLCore class
 
 */
+ (id)sharedManager;

/* 
 
    * method: initFramework
 
    * description: represents the initialization for the sdk after configuration manifest is retrieved
 
    * params
            - configurfationURL: sets the configuration URL for the publisher
 
            - analyticsURL: sets the tracking URL for application and ad events
 
 */
-(void)initFramework:(NSString *)configurationURL withAnalytics:(NSString*)analyticsURL withDelegate:(id)delegate;


-(void)initFramework:(NSString *)configurationURL withAnalytics:(NSString*)analyticsURL withDelegate:(id)delegate disableAnalytics:(BOOL)disableAnalytics;


/* 
 
    * method: showAd:withDefintion
 
    * description: represents showing the overlay/microsite for server-side
     
    * params
 
            -viewController: the primary viewController(AVPlayerViewController) of the hosting application in which the overlay/microiste should be displayed
 
            - adDefinition: represents the transpose JSON data from the VAST data
                            schema for loading the ad
 
 
 */
-(void)showAd:(UIView *)uiView withDefinition:(NSString*)adDefinition;


/*
 
 * method: showAd:withVastURL:hostApplicationOwnsVideoController
 
 * description: represents showing the overlay/microsite client-side
 
 * params
 
    -viewController: the primary viewController (AVPlayerViewController) of the hosting application in which the overlay/microiste should be displayed
 
    - vastURL: represents the BrightLine VAST tag
 
 
 */
-(void)showAd:(UIViewController*)viewController withVASTURL:(NSString*)vastURL;

/*  
 
    * method: hideAd
 
    * description: represents removing the entire ad from memory and (overlay/microsite) from display
 
 */
-(void)hideAd;

//this should be removed
    
    
    
-(void)updateAdViewFrame:(CGRect)frame;

//UIView/UIViewController -- showAd

-(void)updateClientPlayerPosition:(float)currentTime;

@end
