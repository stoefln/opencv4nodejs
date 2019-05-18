const { opencvInclude } = require("./dirs");
const { resolvePath, defaultDir, linkSystemLibs } = require('./commons');

if (linkSystemLibs()) {
  console.log(resolvePath(process.env.OPENCV_INCLUDE_DIR) || `${defaultDir}/include`);
  return;
}

// set include dir from auto build
console.log(opencvInclude);
