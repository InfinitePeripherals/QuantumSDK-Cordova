# QuantumSDK-Cordova

## Requirements:
* Download QuantumSDK.xcframework from Infinite Peripherals's developer portal https://developer.ipcmobile.com

## Add QuantumSDK-Cordova plugin to your app:
1. Copy or replace latest QuantumSDK.xcframework to QuantumSDK-Cordova/src/ios/ of the downloaded plugin

2. Create new app from command line: <br>
```
$ cordova create hello com.example.hello HelloWorld
```

3. Add iOS platform <br>
```
$ cd hello
$ cordova platform add ios
```

4. Add QuantumSDKCordova plugin <br>
```
$ cordova plugin add <path to QuantumSDK-Cordova on local machine>
```

5. Make sure you have your iOS plugged into the computer and build your app.
```
$ cordova build
```

## Usage:
1. Important: request a developer key from IPC's developer portal https://developer.ipcmobile.com
2. In the app set the developer key BEFORE calling any other functions `Quantum.setDeveloperKey("your_key");`
3. Take a look at QuantumSDKCordova.js for available functions.
4. Make sure to add `Quantum.` in front of any functions you call from QuantumSDKCordova.js 

Some examples:
* Set a developer key for your app before running:
```
Quantum.setDeveloperKey("your_developer_key", successFunction, errorFunction);
```
<br>

* Connect the scanner (please make sure the device is powered on):
```
Quantum.connect();
```
<br>

* Listen for device connection state:
```
Quantum.connectionState = function (state) {
    alert("State: " + state);
}.bind(this);
```

* Listen for a barcode after scanning:
```
Quantum.barcodeData = function (barcode, type) {
    alert("Barcode: " + barcode + "\n" + "Type: " + type);
}.bind(this);
```

*Note: Some functions should only be called when the device is connected. Your app should wait until `connectionState` returns `CONN_STATES.CONN_CONNECTED` state before executing those functions.*


## Troubleshoot:
* If you get this error:
```
tool 'xcodebuild' requires Xcode, but active developer directory '/Library/Developer/CommandLineTools' is a command line tools instance
```
 -> then run the command below to set your Xcode:

```
sudo xcode-select -s /Applications/Xcode.app/Contents/Developer
```
<br>

* If you get Signing error:
```
error: Signing for "QuantumCordova" requires a development team. Select a development team in the Signing & Capabilities editor. (in target 'QuantumCordova' from project 'QuantumCordova')
** ARCHIVE FAILED **

xcodebuild: Command failed with exit code 65
```

-> You have 3 options:
  1. Open Xcode, and set your Team and Profile in Signing & Capabilities.
  2. Use a build.json config to sign every time you run `cordova build` command. Visit [Cordova](https://cordova.apache.org/docs/en/10.x/guide/platforms/ios/#using-buildjson) for more info.
  3. Use build flags. Visit [Cordova](https://cordova.apache.org/docs/en/10.x/guide/platforms/ios/#using-flags) for more info.

## API Docs:
[Click here](https://infiniteperipherals.github.io/QuantumSDK-Cordova/) to view QuantumSDK-Cordova's API Docs.
