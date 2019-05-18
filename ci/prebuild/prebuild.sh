#!/bin/sh
cd ../../ &&\
npm install --unsafe-perm &&\
cd test
npm test
cd -
npm run prebuild -- --tag-prefix "" -u $GITHUB_TOKEN;
