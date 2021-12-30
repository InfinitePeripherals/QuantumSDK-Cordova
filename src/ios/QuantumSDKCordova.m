/********* QuantumSDKCordova.m Cordova Plugin Implementation 1.0.14 *******/

#import <WebKit/WebKit.h>
#import <Cordova/CDV.h>
#import <QuantumSDK/QuantumSDK.h>

@interface QuantumSDKCordova : CDVPlugin <IPCDTDeviceDelegate>

@property (strong, nonatomic) IPCIQ *iq;
@property (strong, nonatomic) IPCDTDevices *ipc;

- (void)coolMethod:(CDVInvokedUrlCommand*)command;

// Available functions
- (void)setDeveloperKey:(CDVInvokedUrlCommand *)command;
- (void)connect:(CDVInvokedUrlCommand*)command;
- (void)disconnect:(CDVInvokedUrlCommand*)command;
- (void)sdkVersion:(CDVInvokedUrlCommand *)command;
- (void)getConnectedDeviceInfo:(CDVInvokedUrlCommand*)command;
- (void)getConnectedDevicesInfo:(CDVInvokedUrlCommand*)command;
- (void)setPassThroughSync:(CDVInvokedUrlCommand*)command;
- (void)getPassThroughSync:(CDVInvokedUrlCommand*)command;
- (void)setUSBChargeCurrent:(CDVInvokedUrlCommand*)command;
- (void)getUSBChargeCurrent:(CDVInvokedUrlCommand*)command;
- (void)getBatteryInfo:(CDVInvokedUrlCommand*)command;
- (void)setAutoOffWhenIdle:(CDVInvokedUrlCommand*)command;
- (void)rfInit:(CDVInvokedUrlCommand*)command;
- (void)rfClose:(CDVInvokedUrlCommand*)command;
- (void)barcodeGetScanButtonMode:(CDVInvokedUrlCommand*)command;
- (void)barcodeSetScanButtonMode:(CDVInvokedUrlCommand*)command;
- (void)barcodeGetScanMode:(CDVInvokedUrlCommand*)command;
- (void)barcodeSetScanMode:(CDVInvokedUrlCommand*)command;
- (void)barcodeStartScan:(CDVInvokedUrlCommand*)command;
- (void)barcodeStopScan:(CDVInvokedUrlCommand*)command;
- (void)barcodeSetScanBeep: (CDVInvokedUrlCommand *)command;
- (void)setCharging:(CDVInvokedUrlCommand*)command;
- (void)getFirmwareFileInformation:(CDVInvokedUrlCommand*)command;
- (void)updateFirmwareData:(CDVInvokedUrlCommand*)command;
- (void)emsrSetEncryption:(CDVInvokedUrlCommand*)command;
- (void)emsrSetActiveHead:(CDVInvokedUrlCommand*)command;
- (void)emsrConfigMaskedDataShowExpiration:(CDVInvokedUrlCommand*)command;
- (void)emsrIsTampered:(CDVInvokedUrlCommand*)command;
- (void)emsrGetKeyVersion:(CDVInvokedUrlCommand*)command;
- (void)emsrGetDeviceInfo:(CDVInvokedUrlCommand*)command;
- (void)emsrGetKeysInfo:(CDVInvokedUrlCommand*)command;
- (void)iHUBGetPortsInfo:(CDVInvokedUrlCommand *) command;
- (void)playSound:(CDVInvokedUrlCommand *) command;

@end

@implementation QuantumSDKCordova

// Prototype
- (void)coolMethod:(CDVInvokedUrlCommand*)command
{
    NSLog(@"Call coolMethod");
    
    CDVPluginResult* pluginResult = nil;
    NSString* echo = [command.arguments objectAtIndex:0];
    
    if (echo != nil && [echo length] > 0) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:echo];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}
// *********

// Callback helper
- (void)callback:(NSString *)format, ... NS_FORMAT_FUNCTION(1,2)
{
    va_list args;
    va_start(args, format);
    NSString *javascript = [[NSString alloc] initWithFormat:format arguments:args];
    va_end(args);
    
    if ([self.webView isKindOfClass:WKWebView.class]) {
        [(WKWebView*)self.webView evaluateJavaScript:javascript completionHandler:^(id result, NSError *error) {}];
    }
    else {
        if ([self.webView respondsToSelector:@selector(stringByEvaluatingJavaScriptFromString:)]) {
            [self.webView performSelector:@selector(stringByEvaluatingJavaScriptFromString:) withObject:javascript];
        }
    }
}


// SDK API

- (void)setDeveloperKey:(CDVInvokedUrlCommand *)command
{
    
    NSLog(@"Call setDeveloperKey");

    NSString* key = [command.arguments objectAtIndex:0];

    CDVPluginResult* pluginResult = nil;

    NSError *error;
    self.iq = [IPCIQ registerIPCIQ];
    [self.iq setDeveloperKey:key withError:&error];
    if (error) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
        NSLog(@"Developer Key Error: %@", error.localizedDescription);
    }
    else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    }

    self.ipc = [IPCDTDevices sharedDevice];
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)connect:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call connect");
    
    self.ipc = [IPCDTDevices sharedDevice];
    [self.ipc addDelegate:self];
    [self.ipc connect];
}

- (void)disconnect:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call disconnect");
    
    self.ipc = [IPCDTDevices sharedDevice];
    [self.ipc disconnect];
}

-(void)sdkVersion: (CDVInvokedUrlCommand *)command
{
    NSLog(@"Call SDK Version");
    CDVPluginResult *pluginResult = nil;
    int sdk = [self.ipc sdkVersion];
    if (sdk > 0) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:sdk];
        NSLog(@"SDK Version: %d", sdk);
    }
    else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)playSound:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call playSound");
    CDVPluginResult* pluginResult = nil;
    
    NSArray *beeps = command.arguments[0];
    BOOL isSuccess = NO;
    NSError *error = nil;
    
    if (beeps.count > 0) {
        int numberOfData = (int)beeps.count;
        int beepData[numberOfData];
        for (int x = 0; x < numberOfData; x++) {
            beepData[x] = [beeps[x] intValue];
        }
                
        isSuccess = [self.ipc playSound:100 beepData:beepData length:(int)sizeof(beepData) error:&error];
    }
    
    if (!error || isSuccess) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)getConnectedDeviceInfo:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call getConnectedDeviceInfo");
    
    CDVPluginResult* pluginResult = nil;
    NSString* echo = [command.arguments objectAtIndex:0];
    
    NSError *error = nil;
    DTDeviceInfo *deviceInfo = [self.ipc getConnectedDeviceInfo:[echo intValue] error:&error];
    if (!error) {
        NSDictionary *info = @{@"deviceType": @(deviceInfo.deviceType),
                               @"connectionType": @(deviceInfo.connectionType),
                               @"name": deviceInfo.name,
                               @"model": deviceInfo.model,
                               @"firmwareRevision": deviceInfo.firmwareRevision,
                               @"hardwareRevision": deviceInfo.hardwareRevision,
                               @"serialNumber": deviceInfo.serialNumber
                               };
        
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:info];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)getConnectedDevicesInfo:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call getConnectedDevicesInfo");
    
    CDVPluginResult* pluginResult = nil;
    NSError *error = nil;
    
    NSArray *connectedDevices = [self.ipc getConnectedDevicesInfo:&error];
    
    if (!error) {
        NSMutableArray *devicesInfo = [NSMutableArray new];
        for (DTDeviceInfo *deviceInfo in connectedDevices) {
            NSDictionary *device = @{@"deviceType": @(deviceInfo.deviceType),
                                     @"connectionType": @(deviceInfo.connectionType),
                                     @"name": deviceInfo.name,
                                     @"model": deviceInfo.model,
                                     @"firmwareRevision": deviceInfo.firmwareRevision,
                                     @"hardwareRevision": deviceInfo.hardwareRevision,
                                     @"serialNumber": deviceInfo.serialNumber
                                     };
            
            [devicesInfo addObject:device];
        }
        
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsArray:devicesInfo];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)setPassThroughSync:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call setPassThroughSync");
    
    CDVPluginResult* pluginResult = nil;
    BOOL echo = [command.arguments objectAtIndex:0];
    
    NSError *error;
    BOOL isSuccess = [self.ipc setPassThroughSync:echo error:&error];
    if (!error || isSuccess) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)getPassThroughSync:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call getPassThroughSync");
    
    CDVPluginResult* pluginResult = nil;
    
    NSError *error;
    BOOL isEnable = NO;
    BOOL isSuccess = [self.ipc getPassThroughSync:&isEnable error:&error];
    if (!error || isSuccess) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsBool:isEnable];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)setUSBChargeCurrent:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call setUSBChargeCurrent");
    
    CDVPluginResult* pluginResult = nil;
    int echo = [[command.arguments objectAtIndex:0] intValue];
    
    NSError *error;
    BOOL isSuccess = [self.ipc setUSBChargeCurrent:echo error:&error];
    if (!error || isSuccess) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}


- (void)getUSBChargeCurrent:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call getUSBChargeCurrent");
    
    CDVPluginResult* pluginResult = nil;
    
    NSError *error;
    int current = 0;
    BOOL isSuccess = [self.ipc getUSBChargeCurrent:&current error:&error];
    if (!error || isSuccess) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:current];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)setAutoOffWhenIdle:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call setAutoOffWhenIdle");
    
    CDVPluginResult* pluginResult = nil;
    int timeIdle = [[command.arguments objectAtIndex:0] intValue];
    int timeDisconnected = [[command.arguments objectAtIndex:1] intValue];
    
    NSError *error;
    BOOL isSuccess = [self.ipc setAutoOffWhenIdle:timeIdle whenDisconnected:timeDisconnected error:&error];
    if (!error || isSuccess) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)getBatteryInfo:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call getBatteryInfo");
    
    CDVPluginResult* pluginResult = nil;
    
    NSError *error = nil;
    DTBatteryInfo *battInfo = [self.ipc getBatteryInfo:&error];
    if (!error) {
        NSDictionary *info = @{@"voltage": @(battInfo.voltage),
                               @"capacity": @(battInfo.capacity),
                               @"health": @(battInfo.health),
                               @"maximumCapacity": @(battInfo.maximumCapacity),
                               @"charging": @(battInfo.charging),
                               @"batteryChipType": @(battInfo.batteryChipType),
                               @"extendedInfo": battInfo.extendedInfo != nil ? battInfo.extendedInfo : @""
                               };
        
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:info];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)rfInit:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call rfInit");
    
    CDVPluginResult* pluginResult = nil;
    NSError *error;
    BOOL isSuccess = [self.ipc rfInit:CARD_SUPPORT_PICOPASS_ISO15|CARD_SUPPORT_TYPE_A|CARD_SUPPORT_TYPE_B|CARD_SUPPORT_ISO15|CARD_SUPPORT_FELICA error:&error];
    if (!error || isSuccess) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}


- (void)rfClose:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call rfClose");
    
    CDVPluginResult* pluginResult = nil;
    NSError *error;
    BOOL isSuccess = [self.ipc rfClose:&error];
    if (!error || isSuccess) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)barcodeGetScanButtonMode:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call barcodeGetScanButtonMode");
    
    CDVPluginResult* pluginResult = nil;
    
    NSError *error;
    int scanButtonMode = 1;
    BOOL isSuccess = [self.ipc barcodeGetScanButtonMode:&scanButtonMode error:&error];
    if (!error || isSuccess) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:scanButtonMode];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}


- (void)barcodeSetScanButtonMode:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call barcodeSetScanButtonMode");
    
    CDVPluginResult* pluginResult = nil;
    int echo = [[command.arguments objectAtIndex:0] intValue];
    
    NSError *error;
    BOOL isSuccess = [self.ipc barcodeSetScanButtonMode:echo error:&error];
    if (!error || isSuccess) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)barcodeGetScanMode:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call barcodeGetScanMode");
    
    CDVPluginResult* pluginResult = nil;
    
    NSError *error;
    int scanMode = 1;
    BOOL isSuccess = [self.ipc barcodeGetScanMode:&scanMode error:&error];
    if (!error || isSuccess) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:scanMode];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)barcodeSetScanMode:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call barcodeSetScanMode");
    
    CDVPluginResult* pluginResult = nil;
    int echo = [[command.arguments objectAtIndex:0] intValue];
    
    NSError *error;
    BOOL isSuccess = [self.ipc barcodeSetScanMode:echo error:&error];
    int scanMode = 0;
    [self.ipc barcodeGetScanMode:&scanMode error:nil];
    NSLog(@"BarcodeSetScanMode - Scan Mode: %d",scanMode);
    if (!error || isSuccess) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)barcodeStartScan:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call barcodeStartScan");
    
    CDVPluginResult* pluginResult = nil;
    
    NSError *error;
    BOOL isSuccess = [self.ipc barcodeStartScan:&error];
    if (!error || isSuccess) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)barcodeStopScan:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call barcodeStopScan");
    
    CDVPluginResult* pluginResult = nil;
    
    NSError *error;
    BOOL isSuccess = [self.ipc barcodeStopScan:&error];
    if (!error || isSuccess) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}


- (void)barcodeSetScanBeep: (CDVInvokedUrlCommand *)command
{
    NSLog(@"Call barocdeSetScanBeep");
    
    CDVPluginResult *pluginResult = nil;
    BOOL enabled = [command.arguments[0] boolValue];
    NSError *beepError = nil;
    NSArray *beeps = command.arguments[1];

    int numberOfData = (int)beeps.count;
    int beepData[numberOfData];
    for (int x = 0; x < numberOfData; x++) {
        beepData[x] = [beeps[x] intValue];
    }

    BOOL isSuccess = YES;
    if (enabled) {
        isSuccess = [self.ipc barcodeSetScanBeep:enabled volume:100 beepData:beepData length:(int)sizeof(beepData) error:&beepError];
    }
    else {
        isSuccess = [self.ipc barcodeSetScanBeep:enabled volume:0 beepData:nil length:0 error:&beepError];
    }
    
    if(isSuccess){
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:enabled];
    }
    else{
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:beepError.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)setCharging:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call setCharging");
    
    CDVPluginResult* pluginResult = nil;
    BOOL echo = [command.arguments objectAtIndex:0];
    
    NSError *error;
    BOOL isSuccess = [self.ipc setCharging:echo error:&error];
    if (!error || isSuccess) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)getFirmwareFileInformation:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call getFirmwareFileInformation");
    
    CDVPluginResult *pluginResult = nil;
    NSString *filePath = [command.arguments objectAtIndex:0];
    filePath = [filePath stringByTrimmingCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@"/"]];
    NSURL *fullFilePathURL = [[self resourcePath] URLByAppendingPathComponent:filePath];
    
    @try {
        NSData *fileData = [NSData dataWithContentsOfURL:fullFilePathURL];
        
        if (!fileData) {
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Unable to read file. Check file path!"];
            [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
            return;
        }
        else {
            
            NSError *error = nil;
            NSDictionary *firmwareInfo = [self.ipc getFirmwareFileInformation:fileData error:&error];
            if (!error) {
                pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:firmwareInfo];
            } else {
                pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
            }
            
            [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
            
            return;
        }
        
    } @catch (NSException *exception) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:exception.reason];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
        
        return;
    }
}

- (void)updateFirmwareData:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call updateFirmwareData");
    
    self.ipc = [IPCDTDevices sharedDevice];
    
    CDVPluginResult *pluginResult = nil;
    NSString *filePath = [command.arguments objectAtIndex:0];
    filePath = [filePath stringByTrimmingCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@"/"]];
    NSURL *fullFilePathURL = [[self resourcePath] URLByAppendingPathComponent:filePath];
    
    if (self.ipc.connstate != CONN_CONNECTED) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Device is not connected!"];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
        
        return;
    }
    else {
        @try {
            NSData *fileData = [NSData dataWithContentsOfURL:fullFilePathURL];
            
            if (!fileData) {
                pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Unable to read file. Check file path!"];
                [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
                return;
            }
            else {
                NSError *error = nil;
                BOOL isUpdate = [self.ipc updateFirmwareData:fileData validate:YES error:&error];
                if (!error || isUpdate) {
                    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
                } else {
                    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
                }
                
                [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
                
                return;
            }
            
        } @catch (NSException *exception) {
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:exception.reason];
            [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
            
            return;
        }
    }
}

- (void)emsrSetEncryption:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call emsrSetEncryption");
    
    CDVPluginResult* pluginResult = nil;
    int encryption = [[command.arguments objectAtIndex:0] intValue];
    int keyID = [[command.arguments objectAtIndex:1] intValue];
    NSDictionary *params = nil;
    if (command.arguments.count > 2) {
        // Check for null
        id object = [command.arguments objectAtIndex:2];
        if ([object isKindOfClass:[NSDictionary class]]) {
            params = (NSDictionary *)object;
        }
    }
    
    NSError *error = nil;
    BOOL isSuccess = [self.ipc emsrSetEncryption:encryption keyID:keyID params:params error:&error];
    if (!error || isSuccess) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)emsrSetActiveHead:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call emsrSetActiveHead");
    
    CDVPluginResult* pluginResult = nil;
    int active = [[command.arguments objectAtIndex:0] intValue];
    
    NSError *error = nil;
    BOOL isSuccess = [self.ipc emsrSetActiveHead:active error:&error];
    if (!error || isSuccess) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)emsrConfigMaskedDataShowExpiration:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call emsrConfigMaskedDataShowExpiration");
    
    CDVPluginResult* pluginResult = nil;
    BOOL showExpiration = [[command.arguments objectAtIndex:0] boolValue];
    BOOL showServiceCode = [[command.arguments objectAtIndex:1] boolValue];
    int unmaskedDigitsAtStart = [[command.arguments objectAtIndex:2] intValue];
    int unmaskedDigitsAtEnd = [[command.arguments objectAtIndex:3] intValue];
    int unmaskedDigitsAfter = [[command.arguments objectAtIndex:4] intValue];
    
    NSError *error = nil;
    BOOL isSuccess = [self.ipc emsrConfigMaskedDataShowExpiration:showExpiration showServiceCode:showServiceCode unmaskedDigitsAtStart:unmaskedDigitsAtStart unmaskedDigitsAtEnd:unmaskedDigitsAtEnd unmaskedDigitsAfter:unmaskedDigitsAfter error:&error];
    if (!error || isSuccess) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)emsrIsTampered:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call emsrIsTampered");
    
    CDVPluginResult* pluginResult = nil;
    BOOL isTampered = NO;
    
    NSError *error = nil;
    BOOL isSuccess = [self.ipc emsrIsTampered:&isTampered error:&error];
    if (!error || isSuccess) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsBool:isTampered];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)emsrGetKeyVersion:(CDVInvokedUrlCommand*)command
{
    NSLog(@"Call emsrGetKeyVersion");
    [NSThread sleepForTimeInterval:.2];
    
    CDVPluginResult* pluginResult = nil;
    int keyID = [command.arguments[0] intValue];
    int keyVersion = -1;
    NSError *error = nil;
    
    BOOL isSuccess = [self.ipc emsrGetKeyVersion:keyID keyVersion:&keyVersion error:&error];
    
    if(isSuccess){
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:keyVersion];
    }
    else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)emsrGetDeviceInfo:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call emsrGetDeviceInfo");
    
    CDVPluginResult* pluginResult = nil;
    NSError *error = nil;
    EMSRDeviceInfo *emsrInfo = [self.ipc emsrGetDeviceInfo:&error];
    
    if(emsrInfo){
        NSDictionary *emsrInfoDictionary = @{@"ident": emsrInfo.ident,
                                             @"serialNumber": [NSString stringWithFormat:@"%@", emsrInfo.serialNumber],
                                             @"serialNumberString": emsrInfo.serialNumberString,
                                             @"firmwareVersion": @(emsrInfo.firmwareVersion),
                                             @"firmwareVersionString": emsrInfo.firmwareVersionString,
                                             @"securityVersion": @(emsrInfo.securityVersion),
                                             @"securityVersionString": emsrInfo.securityVersionString
                                             };
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:emsrInfoDictionary];
    }else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)emsrGetKeysInfo:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call emsrGetKeysInfo");
    
    CDVPluginResult* pluginResult = nil;
    NSError *error = nil;
    EMSRKeysInfo *keysInfo = [self.ipc emsrGetKeysInfo:&error];
    
    if (keysInfo) {
        // Get all EMSRKeys
        NSMutableArray *emsrKeys = [NSMutableArray new];
        for (EMSRKey *key in keysInfo.keys) {
            NSString *dukptHexString = [self hexStringFromData:key.dukptKSN length:(int)key.dukptKSN.length space:NO];
            NSDictionary *keyObject = @{
                @"keyID" : @(key.keyID),
                @"keyVersion" : @(key.keyVersion),
                @"dukptKSN" : dukptHexString ? dukptHexString : @"",
                @"keyName" : key.keyName
            };
            
            if (keyObject) {
                [emsrKeys addObject:keyObject];
            }
        }
        
        // Create the EMSRKeysInfo object
        NSDictionary *keysInfoObject = @{
            @"keys" : emsrKeys,
            @"tampered" : @(keysInfo.tampered)
        };
        
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:keysInfoObject];
    }
    else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (NSURL *)resourcePath
{
    NSURL *pathURL = [[NSBundle mainBundle] resourceURL];
    return [pathURL URLByAppendingPathComponent:@"www/resources"];
}

- (void)iHUBGetPortsInfo:(CDVInvokedUrlCommand *)command
{
    NSLog(@"Call iHUBGetPortsInfo");
    
    CDVPluginResult* pluginResult = nil;
    NSError *err = nil;
    NSArray *ports = [self.ipc iHUBGetPortsInfo:&err];
    NSString *portInfo= @"";
    
    for (iHUBPortInfo *port in ports){
        NSLog(@"Port %d: %@", port.portIndex, port.portConfig);
        portInfo = [portInfo stringByAppendingFormat:@"Port %d: %@\n", port.portIndex, port.portConfig];
    }
    
    
    if(ports){
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:portInfo];
    }
    else{
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:err.localizedDescription];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

#pragma mark - IPCDeviceDelegate
- (void)connectionState:(int)state
{
    [self callback:@"Quantum.connectionState(%i)", state];
}

- (void)barcodeData:(NSString *)barcode type:(int)type
{
    //*************
    // This send to regular barcodeData as string
    [self callback:@"Quantum.barcodeData(\"%@\", %i)", barcode, type];
    
    //*************
    // Convert to decimal
    const char *barcodes = [barcode UTF8String];
    NSMutableArray *barcodeDecimalArray = [NSMutableArray new];
    for (int i = 0; i < barcode.length; i++) {
        NSString *string = [NSString stringWithFormat:@"%02d", barcodes[i]];
        [barcodeDecimalArray addObject:string];
    }
    NSString *barcodeDecimalString = [barcodeDecimalArray componentsJoinedByString:@","];
    
    // Send to barcodeDecimals as decimal array
    [self callback:@"Quantum.barcodeDecimals([%@], %i)", barcodeDecimalString, type];
}

- (void)barcodeNSData:(NSData *)barcode type:(int)type
{
    // Hex data
    NSString *hexData = [self hexStringFromData:barcode length:(int)barcode.length space:NO];
    [self callback:@"Quantum.barcodeNSData(\"%@\", %i)", hexData, type];
}

- (void)rfCardDetected:(int)cardIndex info:(DTRFCardInfo *)info
{
    NSDictionary *cardInfo = @{@"type": @(info.type),
                               @"typeStr": info.typeStr,
                               @"UID": [NSString stringWithFormat:@"%@", info.UID],
                               @"ATQA": @(info.ATQA),
                               @"SAK": @(info.SAK),
                               @"AFI": @(info.AFI),
                               @"DSFID": @(info.DSFID),
                               @"blockSize": @(info.blockSize),
                               @"nBlocks": @(info.nBlocks),
                               @"felicaPMm": [NSString stringWithFormat:@"%@", info.felicaPMm],
                               @"felicaRequestData": [NSString stringWithFormat:@"%@", info.felicaRequestData],
                               @"cardIndex": @(info.cardIndex)
                               };
    
    [self callback:@"Quantum.rfCardDetected(%i, %@)", cardIndex, cardInfo];
}

- (void)magneticCardData:(NSString *)track1 track2:(NSString *)track2 track3:(NSString *)track3
{
    [self callback:@"Quantum.magneticCardData(\"%@\", \"%@\", \"%@\")", track1, track2, track3];
}

- (void)magneticCardEncryptedData:(int)encryption tracks:(int)tracks data:(NSData *)data track1masked:(NSString *)track1masked track2masked:(NSString *)track2masked track3:(NSString *)track3 source:(int)source
{
    NSString *hexData = [self hexStringFromData:data length:(int)data.length space:NO];

    [self callback:@"Quantum.magneticCardEncryptedData(%i, %i, \"%@\", \"%@\", \"%@\", \"%@\", %i)", encryption, tracks, hexData, track1masked, track2masked, track3, source];
    
    // Passing along to corresponding callback
    if (encryption == ALG_PPAD_DUKPT_SEPARATE_TRACKS) {
        if(![self magneticCardPPADDUKPTSeparate:data source:source]) {
            [self magneticCardData:track1masked track2:track2masked track3:track3 source:source];
        }
    }
    else if (encryption==ALG_EH_IDTECH || encryption==ALG_EH_IDTECH_AES128) {
        [self magneticCardIDTECH:data encryption:encryption];
    }
}

- (BOOL)magneticCardPPADDUKPTSeparate:(NSData *)data source:(int)source
{
    const uint8_t *bytes=(uint8_t *)[data bytes];

    int index=0;
    //first block = KSN ident (0x00)
    index++;
    //2 more bytes - length (10)
    int ksnLen=(bytes[index+0]<<8)|(bytes[index+1]);
    index+=2;
    NSData *ksnData = [NSData dataWithBytes:&bytes[index] length:ksnLen];
    index+=ksnLen;
    //blocks of data follow for the tracks read
    NSData *t1Encrypted=nil;
    NSData *t2Encrypted=nil;
    NSData *t3Encrypted=nil;
    NSData *panEncrypted=nil;
    NSData *tJISEncrypted=nil;
    while (index<data.length) {
        //get the block
        int tid=bytes[index++];
        int tlen=(bytes[index+0]<<8)|(bytes[index+1]);
        index+=2;
        NSData *tdata=[NSData dataWithBytes:&bytes[index] length:tlen];
        index+=tlen;
        //assign to the track
        switch (tid) {
            case 0x01:
                t1Encrypted=tdata;
                break;
            case 0x02:
                t2Encrypted=tdata;
                break;
            case 0x03:
                t3Encrypted=tdata;
                break;
            case 0x04:
                panEncrypted=tdata;
                break;
            case 0x05:
                tJISEncrypted=tdata;
                break;
        }
    }
    
    NSString *dataHexString = [self hexStringFromData:data length:(int)data.length space:NO];
    NSString *ksnHexString = [self hexStringFromData:ksnData length:(int)ksnData.length space:NO];
    NSString *t1EncryptedHexString = [self hexStringFromData:t1Encrypted length:(int)t1Encrypted.length space:NO];
    NSString *t2EncryptedHexString = [self hexStringFromData:t2Encrypted length:(int)t2Encrypted.length space:NO];
    NSString *t3EncryptedHexString = [self hexStringFromData:t3Encrypted length:(int)t3Encrypted.length space:NO];
    NSString *panEncryptedHexString = [self hexStringFromData:panEncrypted length:(int)panEncrypted.length space:NO];
    NSString *tJISEncryptedHexString = [self hexStringFromData:tJISEncrypted length:(int)tJISEncrypted.length space:NO];
    
    // Callback with all tracks
    [self callback:@"Quantum.magneticCardPPADDUKPTSeparate(\"%@\",\"%@\",\"%@\",\"%@\",\"%@\",\"%@\",%i,\"%@\")", dataHexString, t1EncryptedHexString, t2EncryptedHexString, t3EncryptedHexString, panEncryptedHexString, tJISEncryptedHexString, source, ksnHexString];

    return true;
}

- (void)magneticCardIDTECH:(NSData *)data encryption:(int)encryption
{
    //find the tracks, turn to ascii hex the data
    int index=0;
    const uint8_t *bytes=(uint8_t *)[data bytes];
    
    index++; //card encoding type
    index++; //track status
    int t1Len=bytes[index++]; //track 1 unencrypted length
    int t2Len=bytes[index++]; //track 2 unencrypted length
    int t3Len=bytes[index++]; //track 3 unencrypted length
    NSString *t1masked=[[NSString alloc] initWithBytes:&bytes[index] length:t1Len encoding:NSASCIIStringEncoding];
    index+=t1Len; //track 1 masked
    NSString *t2masked=[[NSString alloc] initWithBytes:&bytes[index] length:t2Len encoding:NSASCIIStringEncoding];
    index+=t2Len; //track 2 masked
    NSString *t3masked=[[NSString alloc] initWithBytes:&bytes[index] length:t3Len encoding:NSASCIIStringEncoding];
    index+=t3Len; //track 3 masked
    const uint8_t *encrypted=&bytes[index]; //encrypted
    size_t encLen=[data length]-index-10-40;
    // KSN
    index += encLen;
    index += 20; //track1 sha1
    index += 20; //track2 sha1
    NSData *ksnData = [NSData dataWithBytes:&bytes[index] length:10]; //dukpt serial number
    
    NSString *ksnHexString = [self hexStringFromData:ksnData length:(int)ksnData.length space:NO];
    NSString *dataHexString = [self hexStringFromData:data length:(int)data.length space:NO];
    NSString *encryptedHexString = [self hexStringFromBytes:encrypted length:(int)encLen space:NO];
    
    [self callback:@"Quantum.magneticCardIDTECH(\"%@\",\"%@\",\"%@\",\"%@\",\"%@\",%i,\"%@\")", dataHexString, t1masked, t2masked, t3masked, encryptedHexString, encryption, ksnHexString];
}

- (void)magneticCardReadFailed:(int)source reason:(int)reason
{
    [self callback:@"Quantum.magneticCardReadFailed(%i, %i)", source, reason];
}

- (void)magneticCardReadFailed:(int)source
{
    [self callback:@"Quantum.magneticCardReadFailed(%i, %i)", source, -1];
}

- (void)deviceButtonPressed:(int)which
{
    [self callback:@"Quantum.deviceButtonPressed(%i)", which];
}

- (void)deviceButtonReleased:(int)which
{
    [self callback:@"Quantum.deviceButtonReleased(%i)", which];
}

- (void)firmwareUpdateProgress:(int)phase percent:(int)percent
{
    [self callback:@"Quantum.firmwareUpdateProgress(%i, %i)", phase, percent];
}

/** Helpers **/

- (NSString *)hexStringFromBytes:(const uint8_t *)bytes length:(size_t)length space:(BOOL)space
{
    if (!bytes) {
        return @"";
    }
    
    @try {
        NSMutableString *hexString = [NSMutableString new];
        for (int x = 0; x < length;x++)
        {
            [hexString appendFormat:@"%02X", bytes[x] ];
            
            if (space && x < length - 1) {
                [hexString appendFormat:@" "];
            }
        }
        
        return hexString;
    }
    @catch (NSException *exception) {
        return @"";
    }
}

- (NSString *)hexStringFromData:(NSData *)data length:(int)length space:(BOOL)space
{
    if (!data) {
        return @"";
    }
    
    const uint8_t *bytes = (uint8_t *)[data bytes];
    
    return [self hexStringFromBytes:bytes length:length space:space];
}


@end

