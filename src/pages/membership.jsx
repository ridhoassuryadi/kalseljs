// IMPORTANT component
import React from 'react';
import Helmet from 'react-helmet';

// CHILD component
import HeroCleanDescription from '../layouts/Membership/HeroCleanDescription';
import DescriptionOurGoal from '../layouts/Membership/DescriptionOurGoal';
import HeaderApp from '../layouts/Header';
import ListMember from '../layouts/Membership/ListMember';
import Footer from '../layouts/Footer';
import BoxInformation from '../components/BoxInformation';

class Membership extends React.Component {
  render() {
    return (
      <div>
        <Helmet>
          <title>Membership</title>
          <meta name="description" content="membership page" />
        </Helmet>
        <HeaderApp />
        <HeroCleanDescription />
        <DescriptionOurGoal />
        <ListMember />
        <section className="sp-pd-top sp-pd-bottom sp-mg-bottom lg-pd-lr dis-flex justify-center">
          <BoxInformation />
        </section>
        <Footer />
      </div>
    );
  }
}

export default Membership;
