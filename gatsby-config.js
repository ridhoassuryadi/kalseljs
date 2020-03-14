module.exports = {
  siteMetadata: {
    title: 'KalselJS - Community Page',
    author: 'Urang Banua',
  },
  plugins: [
    {
      resolve: 'gatsby-plugin-prefetch-google-fonts',
      options: {
        fonts: [
          {
            family: 'Rubik',
            variants: ['400', '500', '700', '900'],
          },
        ],
      },
    },
    'gatsby-plugin-react-helmet',
    {
      resolve: `gatsby-plugin-manifest`,
      options: {
        name: 'kalseljs-community-page',
        short_name: 'kalseljs',
        start_url: '/',
        background_color: '#663399',
        theme_color: '#663399',
        display: 'minimal-ui',
        icon: 'src/images/gatsby-icon.png', // This path is relative to the root of the site.
      },
    },
    {
      resolve: `gatsby-source-filesystem`,
      options: {
        name: `pages`,
        path: `${__dirname}/src/pages`,
      },
    },
    'gatsby-transformer-remark',
    'gatsby-plugin-offline',
    'gatsby-plugin-react-helmet',
    // This plugin transforms JSON file nodes.
    `gatsby-transformer-json`,
    {
      resolve: 'gatsby-plugin-reason',
      options: {
        derivePathFromComponentName: true,
      },
    }
  ],
}
