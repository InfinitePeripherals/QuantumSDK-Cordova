// QuantumSDK
// Apple Frameworks
#import <Foundation/Foundation.h>

#if INCLUDE_CORE_LOCATION
#import <CoreLocation/CoreLocation.h>
#endif

// IPCIQ headers
#import <QuantumSDK/QuantumSDK.h>
#import <QuantumSDK/IQExtension.h>
#import <QuantumSDK/IQCustomDevice.h>
#import <QuantumSDK/IQTransactionReceipt.h>
#import <QuantumSDK/IQMetrics.h>
#import <QuantumSDK/IQLogger.h>

// Constants
extern NSString * const kIPC_IQ_VERSION;
extern NSString * const kIPC_DEVICE_CONNECTED_NOTIFICATION;

/// Checkin completion block
typedef void(^CompletionBlock)(BOOL isSuccess, NSData *data, NSURLResponse *response, NSError *error);

// ********************************* PROTOCOLS *******************************
@protocol IPCIQDelegate <NSObject>
@optional
/**
 Get IPC Devices info
 @param devicesInfo contains IPC Device infos pass along to delegate
 */
- (void)ipcDevicesInfo:(NSArray *)devicesInfo;

/**
 The current status message of IPCIQ checkin process.
 @param statusMessage The status message
 */
- (void)ipciqStatus:(NSString *)statusMessage;

/**
 The report that gets send back to IPCIQ with the status of each configuration. You can read this to see which config has been changed.
 @param report The dictionary that contains the report
 */
- (void)configsDidUpdateWithReport:(NSDictionary *)report;

/**
 Status of setting device's tag.
 @param isSuccess The BOOL value status
 @param error If there is error, the error will be passed here
 */
- (void)deviceTagStatus:(BOOL)isSuccess error:(NSError *)error;

@end
// ******************************** END PROTOCOLS *******************************


// ******************************* INTERFACES ***********************************
/**
 A class that handles key check, device's diagnostic information, and configuration.
 */
@interface IPCIQ : NSObject

// The state of IPCIQ whether it is checking in or not
@property (nonatomic, readonly) BOOL isCheckingIn;

// Allow location request or skip completely. Default is False.
@property (nonatomic) BOOL locationEnabled;

// Allow check-in or skip completely. Default is True.
@property (nonatomic) BOOL checkInEnabled;

// Default is False. If set to true, will allow IQ to run on simulator.
@property (nonatomic) BOOL testMode;

/**
 Get the shared instance of IPCIQ. This will also start IPCIQ timer to check in
 @return IPCIQ shared object
 */
+ (instancetype)registerIPCIQ;

/**
 A developer key is needed in order to use the framework. Please contact IPC for a developer key. This key needs to be set BEFORE calling any other methods, preferrably in application:didFinishLaunchingWithOptions:, or anywhere prior to
 @param key The developer key.
 @param error If there is an error with the developer key, the error object will be returned here.
 @return Boolean A response to indicate the developer key is valid or not.
 */
- (BOOL)setDeveloperKey:(NSString *)key withError:(NSError *__autoreleasing *)error;

/**
 A boolean indicate if the framework has a developer key and is valid.
 @return boolean True if valid, false otherwise
 */
- (BOOL)isValidated;

/**
 Register a dependent module
 @param module The module to register
 @param response The response when register the module
 */
- (void)registerModule:(id)module response:(void (^)(id value))response;

/**
 IQ logging events into file and console
 @param enable A boolean value to enable/disable loggin from IQ
 */
- (void)setEnableLogging:(BOOL)enable;

/**
 Check if your license key is valid for the specific service
 @param license The license key provided by IPC.
 @param service The service that the key was generated for.
 */
- (NSError *)validateLicense:(NSString *)license forService:(NSString *)service;

/**
 Convert NSDate to UTC time string
 @param adate Take in an NSDate
 @return NSString of UTC time
 */
- (NSString *)convertTimeToUTC:(NSDate *)adate;

/**
 Pause IPCIQ from checking in. This only works if the app is Active. When app goes to background, this pause will be released, and IPCIQ will be resumed.
 */
- (void)pause;

/**
 Resume IPCIQ to continue check in
 */
- (void)resume;

/**
 Get all the added extensions
 @return NSArray IQExtension objects
 */
- (NSArray *)getExtensions;

/**
 Get all connected devices info
 @return NSArray The array contains all devices info
 */
- (NSArray *)getConnectedDeviceInfo;

/**
 Add an instance of IQExtension into the checkin data to be sent to IPCIQ
 @param extension An instance of IQExtension
 */
- (void)addExtension:(IQExtension *)extension;

/**
 Remove an instance of IQExtension from the list of checkin data
 @param extension An instance of IQExtension
 */
- (void)removeExtension:(IQExtension *)extension;

/**
 Add an instance of IQCustomDevice into the checkin data to be sent to IPCIQ
 @param customDevice An instance of IQCustomDevice
 */
- (void)addCustomDevice:(IQCustomDevice *)customDevice;

/**
 Remove an instance of IQCustomDevice from the list of checkin data
 @param customDevice An instance of IQCustomDevice
 */
- (void)removeCustomDevice:(IQCustomDevice *)customDevice;

/**
 Add metric to be included on check in to IQ
 @param metric The metric object to be checked in.
 */
- (void)addMetric:(IQMetrics *)metric;

/**
 Remove metric from being checking in to IQ
 @param metric The metric to be removed, if existed
 */
- (void)removeMetric:(IQMetrics *)metric;

/**
 Set company code that associate with this app bundle id
 @param companyCode The company code to be set
 */
- (void)setCompanyCode:(NSString *)companyCode;

/**
 Get company code that this app bundle id associated with
 @return NSString contains company code, or nil if not set.
 */
- (NSString *)getCompanyCode;

/**
 Set check in timer interval, in seconds. The minimum is 1200, which is 20 minutes.
 @param interval Number of seconds until next check in. A number smaller than 1200 will be cap at 1200.
 */
- (void)setCheckInInterval:(NSTimeInterval)interval;

/**
 Get check in interval, in seconds
 @return NSInteger of check in interval
 */
- (NSInteger)getCheckInInterval;

/**
 Set config check in timer interval, in seconds.
 @param interval Number of seconds until next config check in
 */
- (void)setConfigCheckInInterval:(NSTimeInterval)interval;

/**
 Get current config check in interval, in seconds
 @return NSInteger Seconds of config check-in interval
 */
- (NSInteger)getConfigCheckInInterval;

/**
 Set device's tag
 @param tag The NSString tag name
 */
- (void)setDeviceTag:(NSString *)tag;

/**
 Set location upload interval in seconds
 @param seconds The upload interval
 */
- (void)setLocationUploadInterval:(NSInteger)seconds;

/**
 Set location upload interval in seconds
 @return seconds The location upload interval
 */
- (NSInteger)getLocationUploadInterval;

/**
 Upload devices, extensions, metrics to IQ
 @param force A boolean flag that force the checkin to upload regardless of checkin time interval.
 */
- (void)checkIn:(BOOL)force NS_SWIFT_NAME(checkIn(force:));

/**
 Get device UUID assigned by IPCIQ
 @return NSString contains UUID
 */
- (NSString *)getUUID;

/**
 Add an object to be one of IPCIQ's delegates
 @param object The delegate object
 */
- (void)addDelegate:(id)object;

/**
 Remove an object from being IPCIQ's delegate
 @param object The object to be removed
 */
- (void)removeDelegate:(id)object;

/**
Upload transaction receipt
@param receipt The transaction receipt
*/
- (void)uploadTransactionReceipt:(IQTransactionReceipt *)receipt;


// UNAVAILABLE
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;


@end
