import React from 'react'
import PropTypes from 'prop-types'
import SEO from 'uikit/templates/SEO.bs'
import GlobalStyles from 'uikit/templates/Global.bs'
import { StaticQuery, graphql } from 'gatsby'


import Header from 'uikit/organism/Header.bs'
import Store from 'prelude/Store.bs'

const Layout = ({ children }) => (
  <StaticQuery
    query={graphql`
      query SiteTitleQuery {
        site {
          siteMetadata {
            title
          }
        }
      }
    `}
    render={data => (
      <>
        <SEO
          title="KalselJS"
          description="Javascript user based on south borneo"
          />
        <Header siteTitle={data.site.siteMetadata.title} />
        <div
          style={{
            margin: '0 auto',
            maxWidth: 700,
            padding: '0px 1.0875rem 1.45rem',
            paddingTop: 0,
            fontFamily: '-apple-system,BlinkMacSystemFont,Segoe UI,Helvetica,Arial,sans-serif'
          }}
        >
          <GlobalStyles>
            <Store>
              {children}
            </Store>
          </GlobalStyles>
        </div>
      </>
    )}
  />
)

Layout.propTypes = {
  children: PropTypes.node.isRequired,
}

export default Layout
