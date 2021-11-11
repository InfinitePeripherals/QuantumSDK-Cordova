var exec = require('cordova/exec');

/**
 Supported device types
    @enum {int}
    */
exports.SUPPORTED_DEVICE_TYPES = {
    /**
     All device types, used when setting active device
        */
    DEVICE_TYPE_ALL: -1,
    /**
     Linea Pro 1,2,3,4,4s, LineaTab
        */
    DEVICE_TYPE_LINEA: 0,
    /**
     Any of the supported printers - PP-60, DPP-250, DPP-350, DPP-450
        */
    DEVICE_TYPE_PRINTER: 1,
    /**
     Any of the supported pinpads - MPED-400, PPAD1, BP50, BP500
        */
    DEVICE_TYPE_PINPAD: 2,
    /**
     Transport device for connecting to other devices via bluetooth
        */
    DEVICE_TYPE_ISERIAL: 3,
    /**
     Any of the supported zebra printers - DPP-450
        */
    DEVICE_TYPE_PRINTER_ZPL: 4,
    /**
     Any of the supported iHUB devices
        */
    DEVICE_TYPE_IHUB: 5,
    /**
     Any of the supported HID barcode devices
        */
    DEVICE_TYPE_HID_BARCODE: 6,
    /**
     Any of the supported USB magnetic stripe reader devices
        */
    DEVICE_TYPE_USB_MSR: 7,
    /**
     HID keyboard devices
        */
    DEVICE_TYPE_HID_KEYBOARD: 8,
};

/**
 The connection states
    @enum {int}
    */
exports.CONN_STATES = {
    /**
     Device is disconnected, no automatic connection attempts will be made
        */
    CONN_DISCONNECTED: 0,
    /**
     The SDK is trying to connect to the device
        */
    CONN_CONNECTING: 1,
    /**
     Device is connected
        */
    CONN_CONNECTED: 2
};

/**
 Battery chip types
    @enum {int}
    */
exports.BATTERY_CHIPS = {
    /**
     No info available
        */
    BATTERY_CHIP_NONE: 0,
    /**
     Chip BQ27421
        */
    BATTERY_CHIP_BQ27421: 1,
};

/**
 Available scan mode settings
    @enum {int}
    */
exports.SCAN_MODES = {
    /**
     The scan will be terminated after successful barcode recognition (default)
        */
    MODE_SINGLE_SCAN: 0,
    /**
     Scanning will continue unless either scan button is releasd, or stop scan function is called
        */
    MODE_MULTI_SCAN: 1,
    /**
     For as long as scan button is pressed or stop scan is not called the engine will operate in low power scan mode trying to detect objects entering the area, then will turn on the lights and try to read the barcode. Supported only on Code engine.
        */
    MODE_MOTION_DETECT: 2,
    /**
     Pressing the button/start scan will enter aim mode, while a barcode scan will actually be performed upon button release/stop scan.
        */
    MODE_SINGLE_SCAN_RELEASE: 3,
    /**
     Same as multi scan mode, but allowing no duplicate barcodes to be scanned
        */
    MODE_MULTI_SCAN_NO_DUPLICATES: 4,
};

/**
 The available update progress phases.
    @enum {int}
    */
exports.UPDATE_PHASE = {
    /**
     Initializing update
        */
    UPDATE_INIT: 0,
    /**
     Erasing old firmware/preparing memory
        */
    UPDATE_ERASE: 1,
    /**
     Writing data
        */
    UPDATE_WRITE: 2,
    /**
     Update complete, this is the final phase
        */
    UPDATE_FINISH: 3,
    /**
     Post-update operations
        */
    UPDATE_COMPLETING: 4
};

/**
 Encryption type
    @enum {int}
    */
exports.ENCRYPTION_TYPE = {
    ALG_EH_AES256: 2,
    ALG_EH_VOLTAGE: 8,
    ALG_EH_IDTECH: 3,
    ALG_EH_MAGTEK: 4,
    ALG_EH_AES128: 9,
    ALG_PPAD_DUKPT: 10,
    ALG_PPAD_3DES_CBC: 7,
    ALG_EH_IDTECH_AES128: 0x0b,
    ALG_EH_MAGTEK_AES128: 0x0c,
    ALG_PPAD_DUKPT_SEPARATE_TRACKS: 14,
    ALG_PPAD_AES256_CBC: 19
};

/**
 The key encryption ID to be used when changing EMSR encryption type
    @enum {int}
    */
exports.KEY_ENCRYPTION = {
    /**
     Authentication key
        */
    KEY_AUTHENTICATION: 0x00,

    /**
     Encrypted head key loading(encryption) key (KEK), used to load other keys with
        */
    KEY_EH_AES256_LOADING: 0x02,

    /**
     Encrypted head AES256 Data encryption key 1
        */
    KEY_EH_AES256_ENCRYPTION1: 0x01,
    /**
     Encrypted head AES256 Data encryption key 2 (present on EMSR firmware version 2.30 and above)
        */
    KEY_EH_AES256_ENCRYPTION2: 0x03,
    /**
     Encrypted head AES256 Data encryption key 3 (present on EMSR firmware version 2.30 and above)
        */
    KEY_EH_AES256_ENCRYPTION3: 0x04,

    /**
     Encrypted head AES128 Data encryption key 1 (present on EMSR firmware version 2.30 and above)
        */
    KEY_EH_AES128_ENCRYPTION1: 0x09,
    /**
     Encrypted head AES128 Data encryption key 2 (present on EMSR firmware version 2.30 and above)
        */
    KEY_EH_AES128_ENCRYPTION2: 0x0B,
    /**
     Encrypted head AES128 Data encryption key 3 (present on EMSR firmware version 2.30 and above)
        */
    KEY_EH_AES128_ENCRYPTION3: 0x0C,

    /**
     Encrypted head TMK key
        */
    KEY_EH_TMK_AES: 0x10,

    /**
     Encrypted head 3DES DUKPT data encryption key 1
        */
    KEY_EH_DUKPT_MASTER1: 0x20,
    /**
     Encrypted head 3DES DUKPT data encryption key 2 (present on EMSR firmware version 2.30 and above)
        */
    KEY_EH_DUKPT_MASTER2: 0x21,
    /**
     Encrypted head 3DES DUKPT data encryption key 3 (present on EMSR firmware version 2.30 and above)
        */
    KEY_EH_DUKPT_MASTER3: 0x22,

    /**
     This flag locks barcode, magnetic card and bluetooth usage, so it will be possible to use them only after authenticating
        */
    KEY_AUTH_FLAG_LOCK: 1
};

// ******* SDK Delegates ********
// These functions will be called when the scanner receives these events
/**
 * Callback from SDK when a barcode is scanned
 * @param {string} barcode The scanned barcode
 * @param {int} type The barcode type
 */
exports.barcodeData = function (barcode, type) {
    
};

/**
 * Callback from SDK when a barcode is scanned
 * @param {array} barcodes The scanned barcode in decimal array. Need to combine them back into a string
 * @param {int} type The barcode type
 */
exports.barcodeDecimals = function (barcodes, type) {
    
};

/**
 * Callback from SDK when a barcode is scanned
 * @param {string} barcode The scanned barcode in hex
 * @param {int} type The barcode type
 */
exports.barcodeNSData = function (barcode, type) {
    
};

/**
 * Called by SDK to notify the current connection state
 * @param {int} state The connection state CONN_STATES
 */
exports.connectionState = function (state) {
    
};

/**
 * Called when an wireless card is in the field. Should power off after successful read.
 * @param {int} cardIndex
 * @param {key-value} cardInfo
 */
exports.rfCardDetected = function (cardIndex, cardInfo) {
    
};

/**
 * Callback from SDK when card is swiped, and the encryption is set to plain text.
 * @param {string} track1
 * @param {string} track2
 * @param {string} track3
 */
exports.magneticCardData = function (track1, track2, track3) {
    
};

/**
 * Called when device fails to read a card. Could be due to a bad swipe or the magnetic strip is corrupted.
 * @param {int} source the track data source, one of the CARD_* constants
 * @param {int} reason card failed reason, one of the REASON_* constants
 */
exports.magneticCardReadFailed = function (source, reason) {
    
};

/**
 * Called when a card is read and the head is encrypted.
 * @param {int} encryption encryption algorithm used
 * @param {int} tracks contain information which tracks are successfully read and inside the encrypted data as bit fields, bit 1 corresponds to track 1, etc, so value of 7 means all tracks are read
 * @param {data} data contains the encrypted card data
 * @param {string} track1masked Masked track 1 info
 * @param {string} track2masked Masked track 2 info
 * @param {string} track3 Track 3 info
 * @param {int} source Source
 */
exports.magneticCardEncryptedData = function (encryption, tracks, data, track1masked, track2masked, track3, source) {
    
};

/**
 * Called when a hardware button is pressed on the scanner device.
 * @param {int} which Button index
 */
exports.deviceButtonPressed = function (which) {
    
};

/**
 * Called when a hardware button released on the scanner device.
 * @param {int} which Button index
 */
exports.deviceButtonReleased = function (which) {
    
};

/**
 * Called continuously while updating the device firmware to report the progress.
 * @param {int} phase Update phase. One of UPDATE_PHASE
 * @param {int} percent The percent complete
 */
exports.firmwareUpdateProgress = function (phase, percent) {
    
};

/**
 * Called when a card is read and the head is encrypted with PPAD & DUKPT separated key
 * @param {data} data contains the whole encrypted card data block
 * @param {string} track1 encrypted data extracted from data
 * @param {string} track2 encrypted data extracted from data
 * @param {string} track3 encrypted data extracted from data
 * @param {string} pan encrypted data extracted from data
 * @param {string} trackJIS encrypted data extracted from data
 * @param {int} source Source
 */
exports.magneticCardPPADDUKPTSeparate = function (data, track1, track2, track3, pan, trackJIS, source) {
    
};

/**
 * Called when a card is read and the head is encrypted with IDTech key
 * @param {data} data contains the whole encrypted card data block
 * @param {string} track1masked unencrypted track1 masked
 * @param {string} track2masked unencrypted track2 masked
 * @param {string} track3masked unencrypted track3 masked
 * @param {string} encryptedData encrypted data extracted from data
 * @param {int} encryption the encryption type of the encrypted data
 */
exports.magneticCardIDTECH = function (data, track1masked, track2masked, track3masked, encryptedData, encryption) {
    
};

// ***********************************************************************************************************

// ******************************
// ***** Available functions ****
// ******************************

/**
 * This must be the first function that gets called, and a valid develop key must be passed in, and validated, BEFORE any other functions get executed.
 * @param {string} key The developer key given by IPC
 * @param {function} success The success function which will receive the information dictionary.
 * @param {function} error The error reason will be passed in if available
 */
exports.setDeveloperKey = function (key, success, error) {
    exec(success, error, 'QuantumSDKCordova', 'setDeveloperKey', [key]);
};

/**
 * Connect the hardware to the application
 */
exports.connect = function () {
    exec(null, null, 'QuantumSDKCordova', 'connect', []);
};

/**
 * Disconnect all hardware from application
 */
exports.disconnect = function () {
    exec(null, null, 'QuantumSDKCordova', 'disconnect', []);
};

/**
 * SDK version
 * @param {function} success The success function to call when this function is successfully executed and pass in the version number.
 * @param {function} error The error reason will be passed in if available
 */
exports.sdkVersion = function (success, error){
    exec(success, null, 'QuantumSDKCordova', 'sdkVersion', []);
}
/**
 * Get information of a specific firmware file. Info will be passed to success function
 * @param {string} resourcePath The path to resource file with "platforms/ios/www/resources" as the root folder, your files must be copied to here. If you have "platforms/ios/www/resources/test.txt", only pass "test.txt" as resourcePath parameter.
 * @param {function} success The success function to call when this function is successfully executed
 * @param {function} error The error reason will be passed in if available
 */
exports.getFirmwareFileInformation = function (resourcePath, success, error) {
    exec(success, error, 'QuantumSDKCordova', 'getFirmwareFileInformation', [resourcePath]);
};

/**
 * Update firmware
 * @param {string} resourcePath The path to resource file with "platforms/ios/www/resources" as the root folder, your files must be copied to here. If you have "platforms/ios/www/resources/test.txt", only pass "test.txt" as resourcePath parameter.
 * @param {function} success The success function to call when this function is successfully executed
 * @param {function} error The error reason will be passed in if available
 */
exports.updateFirmwareData = function (resourcePath, success, error) {
    exec(success, error, 'QuantumSDKCordova', 'updateFirmwareData', [resourcePath]);
};

/**
 * Get the connected device info. Info will be passed to success function
 * @param {SUPPORTED_DEVICE_TYPES} deviceType
 * @param {function} success The connected device info will be passed in as dictionary parameter
 * @param {function} error The error reason will be passed in if available
 */
exports.getConnectedDeviceInfo = function (deviceType, success, error) {
    exec(success, error, 'QuantumSDKCordova', 'getConnectedDeviceInfo', [deviceType]);
};

/**
 * Get the all connected devices info. Info will be passed to success function
 * @param {function} success The connected device infos will be passed in as array parameter contains multiple device infos
 * @param {function} error The error reason will be passed in if available
 */
exports.getConnectedDevicesInfo = function (success, error) {
    exec(success, error, 'QuantumSDKCordova', 'getConnectedDevicesInfo', []);
};

/**
 * Set sled's battery to charge iOS device.
 * @param {bool} value true or false
 * @param {function} success The success function to call when this function is successfully executed
 * @param {function} error The error reason will be passed in if available
 */
exports.setCharging = function (value, success, error) {
    exec(success, error, 'QuantumSDKCordova', 'setCharging', [value]);
};

/**
 * Set pass-thru sync
 * @param {bool} value true or false
 * @param {function} success The success function to call when this function is successfully executed
 * @param {function} error The error reason will be passed in if available
 */
exports.setPassThroughSync = function (value, succes, error) {
    exec(success, error, 'QuantumSDKCordova', 'setPassThroughSync', [value]);
};

/**
 * Get pass-thru sync enabled or disabled
 * @param {function} success The result will be passed in as Boolean
 * @param {function} error The error reason will be passed in if available
 */
exports.getPassThroughSync = function (success, error) {
    exec(success, error, 'QuantumSDKCordova', 'getPassThroughSync', []);
};

/**
 * Set the USB current
 * @param {int} value Must be one of 500, 1000, 2100, 2400
 * @param {function} success The success function to call when this function is successfully executed
 * @param {function} error The error reason will be passed in if available
 */
exports.setUSBChargeCurrent = function (value, success, error) {
    exec(success, error, 'QuantumSDKCordova', 'setUSBChargeCurrent', [value]);
};

/**
 * Get current USB charge current
 * @param {function} success The usb current will be passed in as Int
 * @param {function} error The error reason will be passed in if available
 */
exports.getUSBChargeCurrent = function (success, error) {
    exec(success, error, 'QuantumSDKCordova', 'getUSBChargeCurrent', []);
};

/**
 * Get battery info
 * @param {function} success The battery info will be passed in as key-value dictionary
 * @param {function} error The error reason will be passed in if available
 */
exports.getBatteryInfo = function (success, error) {
    exec(success, error, 'QuantumSDKCordova', 'getBatteryInfo', []);
};

/**
 * Set IPC device sleep timer
 * @param {int} timeIdle this is the idle time, connected or not, after which Linea will turn off. The default value is 5400 seconds (90 minutes)
 * @param {int} timeDisconnected this is the time with no active program connection, after which Linea will turn off. The default value is 30 seconds
 * @param {function} success The success function to call when this function is successfully executed
 * @param {function} error The error reason will be passed in if available
 */
exports.setAutoOffWhenIdle = function (timeIdle, timeDisconnected, success, error) {
    exec(success, error, 'QuantumSDKCordova', 'setAutoOffWhenIdle', [timeIdle, timeDisconnected]);
};

/**
 * Power on the RF module. Continuously leaving the RF module powered on will drain battery.
 * @param {function} success The success function to call when this function is successfully executed
 * @param {function} error The error reason will be passed in if available
 */
exports.rfInit = function (success, error) {
    exec(success, error, 'QuantumSDKCordova', 'rfInit', []);
};

/**
 * Power down the RF module, when not in use.
 * @param {function} success The success function to call when this function is successfully executed
 * @param {function} error The error reason will be passed in if available
 */
exports.rfClose = function (success, error) {
    exec(success, error, 'QuantumSDKCordova', 'rfClose', []);
};

/**
 * Get the scan button mode
 * @param {function} success The scan button mode will be passed in as boolean
 * @param {function} error The error reason will be passed in if available
 */
exports.barcodeGetScanButtonMode = function (success, error) {
    exec(success, error, 'QuantumSDKCordova', 'barcodeGetScanButtonMode', []);
};

/**
 * Enable or Disable scan button.
 * @param {bool} scanButtonMode true or false
 * @param {function} success The success function to call when this function is successfully executed
 * @param {function} error The error reason will be passed in if available
 */
exports.barcodeSetScanButtonMode = function (scanButtonMode, success, error) {
    exec(success, error, 'QuantumSDKCordova', 'barcodeSetScanButtonMode', [scanButtonMode]);
};

/**
 * Get the current barcode scan mode, one of SCAN_MODES
 * @param {function} success The scan mode will be passed in here, one of SCAN_MODES as Int
 * @param {function} error The error reason will be passed in if available
 */
exports.barcodeGetScanMode = function (success, error) {
    exec(success, error, 'QuantumSDKCordova', 'barcodeGetScanMode', []);
};

/**
 * Set a specific scan mode, one of SCAN_MODES
 * @param {int} scanMode One of SCAN_MODES
 * @param {function} success The success function to call when this function is successfully executed
 * @param {function} error The error reason will be passed in if available
 */
exports.barcodeSetScanMode = function (scanMode, success, error) {
    exec(success, error, 'QuantumSDKCordova', 'barcodeSetScanMode', [scanMode]);
};

/**
 * Start scan engine. Can be used for on screen scan button
 * @param {function} success The success function to call when this function is successfully executed
 * @param {function} error The error reason will be passed in if available
 */
exports.barcodeStartScan = function (success, error) {
    exec(success, error, 'QuantumSDKCordova', 'barcodeStartScan', []);
};

/**
 * Stop scan engine. If using an on screen scan button, call this after a barcode is read.
 * @param {function} success The success function to call when this function is successfully executed
 * @param {function} error The error reason will be passed in if available
 */
exports.barcodeStopScan = function (success, error) {
    exec(success, error, 'QuantumSDKCordova', 'barcodeStopScan', []);
};

/**
 * Set encryption type
 * @param {function} success The success function to call when this function is successfully executed
 * @param {function} error The error reason will be passed in if available
 * @param {int} encryption algorithm used
 * @param {int} keyID the ID of the key to use. The key needs to be suitable for the provided algorithm.
 * @param {dictionary} params optional algorithm parameters.
 */
exports.emsrSetEncryption = function (encryption, keyID, params, success, error) {
    exec(success, error, 'QuantumSDKCordova', 'emsrSetEncryption', [encryption, keyID, params]);
};

/**
 * Set encryption active head. This should be called prior to set encryption type.
 * @param {function} success The success function to call when this function is successfully executed
 * @param {function} error The error reason will be passed in if available
 * @param {int} activeHead The encrypted head to use. Usually 0 = Real, 1 = Emulated
 */
exports.emsrSetActiveHead = function (activeHead, success, error) {
    exec(success, error, 'QuantumSDKCordova', 'emsrSetActiveHead', [activeHead]);
};

/**
 * Fine-tunes which part of the card data will be masked, and which will be sent in clear text for display/print purposes
 * @param {function} success The success function to call when this function is successfully executed
 * @param {function} error The error reason will be passed in if available
 * @param {bool} showExpiration If set to TRUE, expiration date will be shown in clear text, otherwise will be masked
 * @param {bool} showServiceCode if set to TRUE, service code will be shown in clear text, otherwise will be masked
 * @param {int} unmaskedDigitsAtStart the number of digits to show in clear text at the start of the PAN, range from 0 to 6 (default is 4)
 * @param {int} unmaskedDigitsAtEnd the number of digits to show in clear text at the end of the PAN, range from 0, to 4 (default is 4)
 * @param {int} unmaskedDigitsAfter the number of digits to unmask after the PAN, i.e. 4 will give you the expiration, 7 will give expiration and service code (default is 0)
 */
exports.emsrConfigMaskedDataShowExpiration = function (showExpiration, showServiceCode, unmaskedDigitsAtStart, unmaskedDigitsAtEnd, unmaskedDigitsAfter, success, error) {
    exec(success, error, 'QuantumSDKCordova', 'emsrConfigMaskedDataShowExpiration', [showExpiration, showServiceCode, unmaskedDigitsAtStart, unmaskedDigitsAtEnd, unmaskedDigitsAfter]);
};

/**
 * Check if encrypted head is tampered
 * @param {function} success Called if execution success, with result of tampered state as Boolean
 * @param {function} error The error reason will be passed in if available
 */
exports.emsrIsTampered = function (success, error) {
    exec(success, error, 'QuantumSDKCordova', 'emsrIsTampered', []);
};

/**
 * Gets the key version from the keyID that is provided
 * @param {function} success get key version as the parameter
 * @param {function} error the Error reason will be passed in if available
 * @param {int} keyID the ID of the key to get the version
 **/
exports.emsrGetKeyVersion = function(keyID, success, error) {
    exec(success, error, 'QuantumSDKCordova', 'emsrGetKeyVersion', [keyID]);
};

/**
 * Returns general information about the encrypted head - firmware version, ident, serial number
 * @param {function} success The success function to call when this function is successfully executed 
 * @param {function} error The error reason will be passed in if available
 *
 **/
exports.emsrGetDeviceInfo = function(success, error) {
    exec(success, error, 'QuantumSDKCordova', 'emsrGetDeviceInfo',[]);
};

/**
 * Returns information about the loaded keys in the encrypted head and tampered status. The returned object will have schema as below
 * @example
    {
        "keys" : [
            {
                "keyID" : Int,
                "keyVersion" : Int,
                "dukptKSN" : String,
                "keyName" : String
            }
        ],
        "tampered" : Boolean
    }
 *
 * @param {function} success The success function to call when this function is successfully executed
 * @param {function} error The error reason will be passed in if available
 **/
exports.emsrGetKeysInfo = function(success, error) {
    exec(success, error, 'QuantumSDKCordova', 'emsrGetKeysInfo',[]);
};

/**
 * Sets the sound, which is used upon successful barcode scan. This setting is not persistent and is best to configure it upon connect. A sample beep containing of 2 tones, each with 400ms duration, first one 2000Hz and second - 5000Hz will look int beepData[]=[2000,400,5000,400]
 * @param {function} success beep successfully enabled/disabled and/or tone changed
 * @param {function} error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 * @param {bool} enabled turns on or off beeping
 * @param {array<int>} data an array of integer values specifying pairs of tone(Hz) and duration(ms).
 */
exports.barcodeSetScanBeep = function(enabled, beepData, success, error) {
    exec(success, error, 'QuantumSDKCordova', 'barcodeSetScanBeep', [enabled, beepData]);
};

/**
 * Plays a sound using the built-in speaker on the active device. A sample beep containing of 2 tones, each with 400ms duration, first one 2000Hz and second - 5000Hz will look int beepData[]={2000,400,5000,400}
 * @param {array<int>} beepData an array of integer values specifying pairs of tone(Hz) and duration(ms).
 * @param {function} success The success function to call when this function is successfully executed
 * @param {function} error The error reason will be passed in if available
 */
exports.playSound = function(beepData, success, error) {
    exec(success, error, 'QuantumSDKCordova', 'playSound',[beepData]);
};

exports.iHUBGetPortsInfo = function(success, error){
    exec(success, error, 'QuantumSDKCordova', 'iHUBGetPortsInfo', []);
};
