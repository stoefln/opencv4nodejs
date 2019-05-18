const { opencvLibDir } = require("./dirs");
const { readdirSync, realpathSync } = require("fs");
const { join } = require("path");

for (const file of readdirSync(opencvLibDir)) {
    console.log(join(realpathSync(opencvLibDir), file));
}
