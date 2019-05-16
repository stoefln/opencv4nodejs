#!/bin/sh
cd ../../ &&\
npm install &&\
cd test &&\
npm install &&\
npm test &&\
npm run test-externalMemTracking
