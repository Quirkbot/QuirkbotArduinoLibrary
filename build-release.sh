temp=$(mktemp -dt "$0")
src=$(pwd)

rm Quirkbot.zip
cp -rf ./* $temp/

rm -rf $temp/.git
rm -rf $temp/.gitignore
rm -rf $temp/.npmignore
rm -rf $temp/node_modules
rm -rf $temp/gulpfile.js
rm -rf $temp/library.template.properties
rm -rf $temp/build-release.sh
rm -rf $temp/s3_publish
rm -rf $temp/s3-publish.sh

cd $temp
zip -vr Quirkbot.zip \
./ \
-x "*.DS_Store" \

mv $temp/Quirkbot.zip $src/Quirkbot.zip

rm -r $temp

cd $src
