//
//  IQTransactionReceipt.h
//  QuantumSDK
//
//  Copyright © 2016 Infinite Peripherals. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IQTransactionReceipt : NSObject

///
@property (nonatomic, strong) NSString *merchantName;

///
@property (nonatomic, strong) NSString *location;

///
@property (nonatomic, strong) NSString *transactionTime;

///
@property (nonatomic, strong) NSString *cardBrand;

///
@property (nonatomic, strong) NSString *primaryAccountNumber;

///
@property (nonatomic, strong) NSString *transactionType;

///
@property (nonatomic, strong) NSString *entryMethod;

///
@property (nonatomic, strong) NSString *totalAmount;

///
@property (nonatomic, strong) NSString *authorizationCode;

///
@property (nonatomic, strong) NSString *referenceNumber;

///
@property (nonatomic, strong) NSString *signatureImage;

///
@property (nonatomic, strong) NSString *emvAuthorizationMode;

///
@property (nonatomic, strong) NSString *emvApplicationID;

///
@property (nonatomic, strong) NSString *aidName;


/**
 Get a list of info for the current transaction receipt
 @return NSDictionary object contains the info
 */
- (NSDictionary *)getTransactionReceipt;

@end
