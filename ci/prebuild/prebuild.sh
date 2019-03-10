#!/bin/sh
if [[ "$TRAVIS_OS_NAME" == "linux" ]];
then
    image=opencv4nodejs-ci_$1
    docker build -t $image -f ./Dockerfile --build-arg TAG=$1 ../../
    docker run -e GITHUB_TOKEN=$GITHUB_TOKEN $image
elif [[ "$TRAVIS_OS_NAME" == "osx" ]];
then
    cd ../../ &&\
    npm install --unsafe-perm &&\
    npm run prebuild -- --tag-prefix "" -u $GITHUB_TOKEN;
fi
