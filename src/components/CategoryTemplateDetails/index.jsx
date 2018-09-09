import React from 'react';
import Post from '../Post';

class CategoryTemplateDetails extends React.Component {
  render() {
    const items = [];
    const { category } = this.props.pathContext;
    const posts = this.props.data.allMarkdownRemark.edges;
    posts.forEach((post) => {
      items.push(<Post data={post} key={post.node.fields.slug} />);
    });

    return (
      <div className="content">

      </div>
    );
  }
}

export default CategoryTemplateDetails;
