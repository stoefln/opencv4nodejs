const opencvBuild = require(`@nut-tree/opencv-build-${process.platform}`);
const { resolvePath, defaultDir, linkSystemLibs } = require('./commons');

if (linkSystemLibs()) {
  console.log(resolvePath(process.env.OPENCV_INCLUDE_DIR) || `${defaultDir}/include`);
  return;
}

// set include dir from auto build
console.log(resolvePath(opencvBuild.opencvInclude));
