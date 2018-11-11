import React from 'react';

// Assets
import mobileImg from '../../../assets/images/people-learn--mobile.png';
import desktopImg from '../../../assets/images/people-learn--desktop.png';
import './style.scss';

class DescriptionOurGoal extends React.Component {
  render() {
    return (
      <section id="descOurGoal">
        <div className="desc-our-goal__picture">
          <picture>
            <source media="(max-width: 465px)" srcSet={mobileImg} alt="people learn" />
            <img src={desktopImg} alt="people learn" />
          </picture>
        </div>
        <div className="container">
          <p>
                We spend every day thinking about new ways to improve cities for the riders and drivers who live in them. With your unique perspective, our dreams for tomorrow will move closer to reality.
          </p>
        </div>
      </section>
    );
  }
}

export default DescriptionOurGoal;
