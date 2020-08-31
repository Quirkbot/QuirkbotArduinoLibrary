# Quirkbot Arduino Library

## Deploying Releases

- Install node dependencies:
```
npm install
```
- Use node version 10 (tested with 14 and it doesn't work):
```
npm use 10
```
- Update the version in `package.json`
- Run:
```
npm run gulp -- build
```
- When you are completely satisfied with the deployed release, run:
```
npm publish
```
- Create a git tag.
- Make a manual [Github release](https://github.com/Quirkbot/QuirkbotArduinoLibrary/releases) and upload the generated _quirkbot-arduino-library-*.zip_.
