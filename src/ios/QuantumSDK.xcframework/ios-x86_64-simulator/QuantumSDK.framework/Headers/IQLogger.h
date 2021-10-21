//
//  IQLogger.h
//  QuantumSDK
//
//  Copyright © 2020 Infinite Peripherals. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IQLogger : NSObject

+ (instancetype)shared;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 This message log will be saved into IQ log file
 @param message The log message
 */
- (void)logMessage:(NSString *)message;

@end
