//
//  IQPluginExtension.h
//  QuantumSDK
//
//  Copyright © 2015 Infinite Peripherals. All rights reserved.
//

#import <Foundation/Foundation.h>

/// Display type
typedef NS_ENUM (NSUInteger, DISPLAY_TYPE)   {
    DISPLAY_TYPE_BOOL = 1,
    DISPLAY_TYPE_STRING = 2,
    DISPLAY_TYPE_INT = 3,
    DISPLAY_TYPE_LIST = 4,
    DISPLAY_TYPE_FIRMWARE = 5,
	DISPLAY_TYPE_FILE = 6
};

/// Config type
typedef NS_ENUM (NSUInteger, CONFIG_TYPE) {
    CONFIG_TYPE_BOOL = 1,
    CONFIG_TYPE_STRING = 2,
    CONFIG_TYPE_INT = 3,
    CONFIG_TYPE_LIST = 4,
    CONFIG_TYPE_FIRMWARE = 5,
	CONFIG_TYPE_FILE = 6,
};

@interface IQExtension : NSObject

/**
 The display name, in pretty format
 */
@property (readonly, nonatomic, strong) NSString *name;

/**
 Version number
 */
@property (readonly, nonatomic, strong) NSString *pluginVersion;

/**
 The prefix for extension field
 */
@property (readonly, nonatomic, strong) NSString *pluginName;

/**
 The plugin type for extension
 */
@property (readonly, nonatomic, strong) NSString *pluginType;

/**
 Init function with plugin name and display name
 @param prettyName The tab display name, should be in pretty format, which appears on IPCIQ portal
 @return IQExtension object
 */
- (instancetype)initWithName:(NSString *)prettyName;

/** 
 Set extension field data with configuration
 @param value The initial value for this field
 @param field The field identifier
 @param prettyName The display name for this field
 @param displayType One of the DISPLAY_TYPE enum
 @param configType One of the CONFIG_TYPE
 @param section Group configuration into sections
 @param passive Allow application to set configuration value. No will reset parameter based off configuration
 @param regex Regex string value
 @param defaultValue A string value of the default value for configuration
 @param configValues A string of values, separated by commas
 @param min Min value for this configuration
 @param max Max value for this configuration
 @param order The displaying order in the web portal
 */
- (void)setValue:(NSString *)value
        forField:(NSString *)field
           title:(NSString *)prettyName
     displayType:(DISPLAY_TYPE)displayType
      configType:(CONFIG_TYPE)configType
		 section:(NSString *)section
         passive:(BOOL)passive
           regEx:(NSString *)regex
	defaultValue:(NSString *)defaultValue
          values:(NSString *)configValues
             min:(NSUInteger)min
             max:(NSUInteger)max
           order:(NSInteger)order;

/**
 Get value for the given field
 @param field The field name to query object for
 @return NSString value
 */
- (NSString *)getValueForField:(NSString *)field;

/**
 Set extension plugin version number
 @param major Version major
 @param minor Version minor
 @param build Version build
 */
- (void)setPluginVersionMajor:(NSInteger)major minor:(NSInteger)minor build:(NSInteger)build;

/**
 Update value for the given field
 @param value The new value
 @param field The field to be updated
 @return BOOL returns YES if operation is succeed, NO otherwise
 */
- (BOOL)updateValue:(NSString *)value forField:(NSString *)field;

/**
 Set extension field data without configuration
 @param value The initial value for this field
 @param field The field identifier
 @param prettyName The display name for this field
 @param displayType One of the DISPLAY_TYPE enum
 @param order The displaying order in the web portal
 */
- (void)setValue:(NSString *)value
        forField:(NSString *)field
           title:(NSString *)prettyName
     displayType:(DISPLAY_TYPE)displayType
           order:(NSInteger)order;

/**
 Generate a complete plugin data
 @return NSDictionary contains the plugin data
 */
- (NSDictionary *)getExtensionPluginData;

/**
 Generate a list of key-value pairs that have been added
 @return NSDictionary contains added info
 */
- (NSDictionary *)getExtensionDetails;

/**
 Clear all saved data of an IQExtension object
 */
- (void)clearData;

/**
 UNAVAILABLE
 */
- (id)init NS_UNAVAILABLE;

@end
