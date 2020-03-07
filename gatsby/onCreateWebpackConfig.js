const {resolve} = require('path');
const webpack = require('webpack');
const path = require('path');

module.exports = ({_stage, actions}) => {
  actions.setWebpackConfig({
    resolve: {
      modules: [
        resolve(__dirname, '../src'),
        resolve(__dirname, '../node_modules'),
      ],
      alias: {
        components: path.resolve(__dirname, '../src/components'),
        bindings: path.resolve(__dirname, '../src/bindings'),
        pages: path.resolve(__dirname, '../src/pages'),
        images: path.resolve(__dirname, '../src/images'),
      },
      extensions: ['.js', '.bs.js']
    },
    // See https://github.com/FormidableLabs/react-live/issues/5
    plugins: [new webpack.IgnorePlugin(/^(xor|props)$/)],
  });
};