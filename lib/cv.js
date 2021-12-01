const path = require('path');
const { resolvePath } = require('./commons');

const isElectron = process.versions.hasOwnProperty('electron')
const packagePath = 'node_modules/opencv4nodejs-prebuilt'

const debugOrRelease = process.env.BINDINGS_DEBUG ? 'Debug' : 'Release'
const binaryName = 'opencv4nodejs.node'
let requirePath
let cv = null
let requireFunc
const logDebug = process.env.OPENCV4NODES_DEBUG_REQUIRE ? require('npmlog').info : () => {}
try {
  if (isElectron) {
    // in electron we are referencing the node module from a packed file in some static folder. So relative path will be complicated. Use absolute path instead.
    const electron = require("electron")
    const appPath = (electron.app || electron.remote.app).getAppPath()
    requirePath = path.resolve(appPath, packagePath, `build/${debugOrRelease}/${binaryName}`)
    // requireing a .node file fails with webpack. __non_webpack_require__ tells webpack not to resolve the dependency
    logDebug('require', 'require path is ' + requirePath)
    cv = __non_webpack_require__(requirePath);
  } else {
    requirePath = path.join(__dirname, `../build/${debugOrRelease}/${binaryName}`)
    logDebug('require', 'require path is ' + requirePath)
    cv = require(requirePath);
  }
} catch (err) {
  logDebug('require', 'failed to require cv with exception: ' + err.toString())
  throw err
}

// resolve haarcascade files
const { haarCascades, lbpCascades } = cv;
Object.keys(haarCascades).forEach(
  key => cv[key] = resolvePath(path.join(__dirname, './haarcascades'), haarCascades[key]));
Object.keys(lbpCascades).forEach(
  key => cv[key] = resolvePath(path.join(__dirname, './lbpcascades'), lbpCascades[key]));

module.exports = cv;
