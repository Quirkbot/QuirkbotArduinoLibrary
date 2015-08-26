rm Quirkbot.zip

rm -r Quirkbot
mkdir Quirkbot
cp ./* ./Quirkbot/

rm -r Quirkbot/.git
rm Quirkbot/.gitignore
rm Quirkbot/build-release.sh

cd Quirkbot
zip -vr Quirkbot.zip \
./ \
-x "*.DS_Store"
cd ..
mv Quirkbot/Quirkbot.zip Quirkbot.zip

rm -r Quirkbot
