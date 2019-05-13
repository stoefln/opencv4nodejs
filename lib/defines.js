const opencvBuild = require(`@nut-tree/opencv-build-${process.platform}`);
const { getLibDir, linkSystemLibs } = require('./commons');

if (linkSystemLibs()) {
  opencvBuild.getLibs(getLibDir())
    .filter(lib => lib.libPath)
    .map(lib => lib.opencvModule)
    .forEach(opencvModule => console.log(`HAVE_${opencvModule.toUpperCase()}`));

  return;
}

// set defines from auto build
opencvBuild.opencvModules.forEach(m => console.log(`HAVE_${m.toUpperCase()}`));
