sh "build-release.sh"

rm -r s3_publish
mkdir s3_publish

cp "Quirkbot.zip" "s3_publish/quirkbot-arduino-library.zip"
aws s3 sync s3_publish s3://code.quirkbot.com/downloads/ --exclude *.DS_Store

rm -r s3_publish
mkdir s3_publish

cp Quirkbot.zip s3_publish/Quirkbot.zip
aws s3 sync s3_publish s3://code.quirkbot.com/downloads/ --exclude *.DS_Store
