
# see https://developer.amazon.com/blogs/post/Tx1UE9W1NQ0GYII/publishing-your-skill-code-to-lambda-via-the-command-line-interface

rm lambda.zip
cd js
zip -X -r ../lambda.zip *
cd ..
aws lambda update-function-code --function-name myDisplay --zip-file fileb://lambda.zip
