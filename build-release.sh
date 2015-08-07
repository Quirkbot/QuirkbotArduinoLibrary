rm QuirkbotArduinoLibrary.zip

rm -r Quirkbot
mkdir Quirkbot
cp ./* ./Quirkbot/

rm -r Quirkbot/.git
rm Quirkbot/.gitignore
rm Quirkbot/build-release.sh

zip -vr QuirkbotArduinoLibrary.zip \
Quirkbot/ \
-x "*.DS_Store"

rm -r Quirkbot
