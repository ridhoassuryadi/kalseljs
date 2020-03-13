/**
 *   Simple Code generator to create module svgr component on reasonml
 *   There are following rules:
 *   - Add SVG Assets inside assets/svg
 *   - Capitalize the assets name because it will be use for module name
 */

const fs = require('fs-extra');

const OUTPUT_FILE = './src/components/uikit/foundation/Icons.re';
const ASSETS_SOURCE = 'images/icons'
const ASSETS_0RIGIN = './src/images/icons'
let DESCRIPTION = `
  // This files is auto generated from codegen, PLEASE DONT EDIT THIS

`

const capitalizeFirstLetter = (word) =>
    word.charAt(0).toUpperCase() + word.slice(1);

const getNameWithoutExtension = (file) => file.split('.')[0]

const getModuleName = (file) =>
  capitalizeFirstLetter(
    getNameWithoutExtension(file)
  );

function createSVGAssets() {
  fs.readdir(ASSETS_0RIGIN, function(_err, files) {
    let reasonModules = files.reduce((generatedAccumulator, file) => {
      generatedAccumulator += `
      module ${getModuleName(file)} = {
        [@bs.module "${ASSETS_SOURCE}/${file}"] [@react.component]
        external make: (~className:option(string)=?) => React.element = "default";
      };
      `;

      return generatedAccumulator
    }, DESCRIPTION)
    
    fs.writeFile(OUTPUT_FILE, reasonModules);
    console.log("Success bosque 🤖")
  });
}

try {  
  createSVGAssets()
}catch(e){
  throw `Failed to generate images because ${e}`
}


