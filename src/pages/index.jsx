import React from 'react';
import Helmet from 'react-helmet';
import { graphql } from 'gatsby';

// Import Component
import Post from '../components/Post';
import HeroBanner from '../layouts/HeroBanner';
import HeaderApp from '../layouts/Header';
import Description from '../layouts/Description';
import Learning from '../layouts/Learning';
import MeetupSection from '../layouts/MeetupSection';
import Footer from '../layouts/Footer';

import '../assets/scss/init.scss';

class IndexRoute extends React.Component {
  render() {
    const { title, subtitle } = this.props.data.site.siteMetadata;

    return (
      <div>
        <Helmet>
          <title>{title}</title>
          <meta name="description" content={subtitle} />
        </Helmet>
        <HeaderApp className="no-border" />
        <HeroBanner />
        <Description />
        <MeetupSection />
        <Learning />
        <Footer />
      </div>
    );
  }
}

export default IndexRoute;

export const pageQuery = graphql`
  query IndexQuery {
    site {
      siteMetadata {
        title
        subtitle
        copyright
        menu {
          label
          path
        }
        author {
          name
          email
          telegram
          twitter
          github
          rss
          vk
        }
      }
    }
    allMarkdownRemark(
        limit: 1000,
        filter: { frontmatter: { layout: { eq: "post" }, draft: { ne: true } } },
        sort: { order: DESC, fields: [frontmatter___date] }
      ){
      edges {
        node {
          fields {
            slug
            categorySlug
          }
          frontmatter {
            title
            date
            category
            description
          }
        }
      }
    }
  }
`;
