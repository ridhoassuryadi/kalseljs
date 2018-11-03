// IMPORTANT component
import React from 'react';
import Helmet from 'react-helmet';

// CHILD component
import HeroCleanDescription from '../layouts/HeroCleanDescription';

class Membership extends React.Component {
  render() {
    return (
      <div>
        <Helmet>
          <title>Membership</title>
          <meta name="description" content="membership page" />
        </Helmet>
        <HeroCleanDescription />
      </div>
    );
  }
}

export default Membership;
