#!/usr/bin/sh
set -e

if [[ "$TRAVIS_OS_NAME" == "linux" ]] || [[ "$TRAVIS_OS_NAME" == "osx" ]]
then
    dirs=(
    /opt/opencv-prebuilt
    /usr/local/opt/opencv-prebuilt
    )

    for dir in ${dirs[*]}
    do
        if [ -d $dir ]
        then
            echo "Removing '$dir'"
            rm -rf $dir
        fi
    done
fi

