#!/bin/sh
if [[ "$TRAVIS_OS_NAME" == "linux" ]] || [[ "$TRAVIS_OS_NAME" == "osx" ]];
then
    dirs=(
    /opt/opencv-prebuilt
    /usr/local/opt/opencv-prebuilt
    )

    for dir in ${dirs[*]}; do if [ -d $dir ]; then rm -rf $dir; fi; done
fi
if [[ "$TRAVIS_OS_NAME" == "windows" ]];
then
    for dir in ${dirs[*]}; do if [ -d $dir ]; then rm -rf $dir; fi; done
fi

cd ../../ &&\
npm install --unsafe-perm &&\
npm test
npm run prebuild -- --tag-prefix "" -u $GITHUB_TOKEN;
