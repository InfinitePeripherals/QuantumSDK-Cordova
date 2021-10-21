//
//  IQMetrics.h
//  QuantumSDK
//
//  Copyright © 2020 Infinite Peripherals. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IQMetrics : NSObject

/// Name of the metric set on initialization
@property (readonly) NSString *name;

/// Category of the metric set on initialization
@property (readonly) NSString *category;

/// Current numerator count. This can be reset to a new count.
@property (nonatomic) NSInteger numeratorCount;

/// Current denominator count. This can be reset to a new count.
@property (nonatomic) NSInteger denominatorCount;

/**
 Instantiate a new metric with name and category. Example we create a metric with name = "Amount over $100" and category = "Invoice". 
 @param name The name that will show in IQ portal
 @param category The category for this metric.
 */
- (instancetype)initWithName:(NSString *)name category:(NSString *)category;

/**
 This count will be added on top of the current numerator count
 @param count The count to be added to current count
 */
- (void)addNumeratorCount:(NSInteger)count;

/**
This count will be added on top of the current denominator count
@param count The count to be added to current count
*/
- (void)addDenominatorCount:(NSInteger)count;

/**
 Reset both numerator and denominator counts to 0
 */
- (void)resetAll;

/**
 Reset numerator count to 0
 */
- (void)resetNumerator;

/**
 Reset denominator count to 0
 */
- (void)resetDenominator;

/**
 Use -initWithName:category: instead.
 */
- (instancetype)init NS_UNAVAILABLE;

@end
