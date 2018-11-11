import React from 'react';
import HeroProject from '../layouts/Project/HeroProject';
import ControlInfo from '../layouts/Project/ControlInfo';
import HeaderApp from '../layouts/Header';
import Footer from '../layouts/Footer';
import ProjectList from '../layouts/Project/ProjectLists';

class Project extends React.Component {
  render() {
    return (
      <div>
        <HeaderApp />
        <HeroProject />
        <div className="container container--lists lg-pd-tb">
          <ControlInfo />
          <ProjectList />
        </div>
        <Footer />
      </div>
    );
  }
}

export default Project;
