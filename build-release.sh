temp=$(mktemp -dt "$0")
src=$(pwd)

rm Quirkbot.zip
cp -r ./* $temp/

rm -r $temp/.git
rm $temp/.gitignore
rm $temp/build-release.sh
rm -r $temp/s3_publish
rm $temp/s3-publish.sh

cd $temp
zip -vr Quirkbot.zip \
./ \
-x "*.DS_Store" \

mv $temp/Quirkbot.zip $src/Quirkbot.zip

rm -r $temp

cd $src
