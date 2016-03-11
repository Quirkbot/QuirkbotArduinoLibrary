temp=$(mktemp -dt "$0")
src=$(pwd)

rm Quirkbot.zip
cp -r ./* $temp/

rm -r $temp/.git
rm -r $temp/.gitignore
rm -r $temp/.npmignore
rm -r $temp/node_modules
rm -r $temp/gulpfile.js
rm -r $temp/library.template.properties
rm -r $temp/build-release.sh
rm -r $temp/s3_publish
rm -r $temp/s3-publish.sh

cd $temp
zip -vr Quirkbot.zip \
./ \
-x "*.DS_Store" \

mv $temp/Quirkbot.zip $src/Quirkbot.zip

rm -r $temp

cd $src