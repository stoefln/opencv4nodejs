#!/bin/sh
export OPENCV4NODEJS_DISABLE_AUTOBUILD=1
echo "Installing dependencies" &&\
npm install --unsafe-perm &&\
echo "Running prebuild" &&\
npm install --unsafe-perm &&\
npm run prebuild -- --tag-prefix "" -u $GITHUB_TOKEN;
