const path = require('path')

const PATH_SVG_INLINE = path.resolve(__dirname, '../src/images')

module.exports = ({ config }) => {
  // Transpile Gatsby module because Gatsby includes un-transpiled ES6 code.
  config.module.rules[0].exclude = [/node_modules\/(?!(gatsby)\/)/]

  // use installed babel-loader which is v8.0-beta (which is meant to work with @babel/core@7)
  config.module.rules[0].use[0].loader = require.resolve('babel-loader')

  // use @babel/preset-react for JSX and env (instead of staged presets)
  config.module.rules[0].use[0].options.presets = [
    require.resolve('@babel/preset-react'),
    require.resolve('@babel/preset-env'),
  ]

  // Add existing alias import svg
  ;(config.resolve.alias = {
    ...config.resolve.alias,
    images: PATH_SVG_INLINE,
  }),
    (config.module.rules[0].use[0].options.plugins = [
      // use @babel/plugin-proposal-class-properties for class arrow functions
      require.resolve('@babel/plugin-proposal-class-properties'),
      // use babel-plugin-remove-graphql-queries to remove static queries from components when rendering in storybook
      require.resolve('babel-plugin-remove-graphql-queries'),
    ])

  // modify storybook's file-loader rule to avoid conflicts with svgr
  const fileLoaderRule = config.module.rules.find(rule =>
    rule.test.test('.svg')
  )
  fileLoaderRule.exclude = PATH_SVG_INLINE

  // add svgr as new rules
  config.module.rules.push({
    test: /\.svg$/,
    include: PATH_SVG_INLINE,
    use: [
      {
        loader: '@svgr/webpack',
        options: {
          icon: true,
        },
      },
    ],
  })

  // Prefer Gatsby ES6 entrypoint (module) over commonjs (main) entrypoint
  config.resolve.mainFields = ['browser', 'module', 'main']
  return config
}
