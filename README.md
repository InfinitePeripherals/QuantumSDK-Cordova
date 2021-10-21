# QuantumSDK-Cordova

## Prerequisites:
* Download QuantumSDK.framework from IPC's developer portal https://developer.ipcmobile.com

## New Cordova app:
1. Create new app
2. Add iOS platform
3. Add QuantumSDKCordova plugin
4. Copy QuantumSDK.framework to src/ios/ of the plugin
5. Copy build.json from plugin's root to new app's root folder
6. Build your app.

## Usage:
1. Important: request a developer key from IPC's developer portal https://developer.ipcmobile.com
2. In the app set the developer key BEFORE calling any other functions `QuantumIQ.setDeveloperKey("your_key");`
3. Check out QuantumSDKCordova.js for available functions.
4. Make sure to add `Quantum.` in front of any functions you call from QuantumSDKCordova.js 
