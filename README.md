# QuantumSDK-Cordova

## Requirements:
* Download QuantumSDK.xcframework from Infinite Peripherals's developer portal https://developer.ipcmobile.com

## New Cordova app:
1. Create new app from command line: <br>
```
$ cordova create hello com.example.hello HelloWorld
```

2. Add iOS platform <br>
```
$ cd hello
$ cordova platform add ios
```

3. Add QuantumSDKCordova plugin <br>
```
$ cordova plugin add <path to QuantumSDK-Cordova on local machine>
```

4. Copy or replace latest QuantumSDK.xcframework to src/ios/ of the plugin
5. Copy build.json from plugin's root to new app's root folder
6. Build your app.

## Usage:
1. Important: request a developer key from IPC's developer portal https://developer.ipcmobile.com
2. In the app set the developer key BEFORE calling any other functions `QuantumIQ.setDeveloperKey("your_key");`
3. Take a look at QuantumSDKCordova.js for available functions.
4. Make sure to add `Quantum.` in front of any functions you call from QuantumSDKCordova.js 
