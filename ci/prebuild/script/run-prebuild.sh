#!/bin/sh
export OPENCV4NODEJS_DISABLE_AUTOBUILD=1
echo "Installing dependencies" &&\
npm install --unsafe-perm &&\
echo "Running prebuild" &&\
npm run prebuild -- -u $GITHUB_TOKEN
