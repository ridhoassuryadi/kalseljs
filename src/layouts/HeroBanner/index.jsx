import React from 'react';

import './style.scss';
import illustrateImg from '../../assets/images/illustrate-hero.svg';
import wavingHand from '../../assets/images/waving__hand.png';

class HeroBanner extends React.Component {
    render(){
        return (
            <div className="hero">
                <div className="container">
                    <div className="hero__text">
                        <p>
                            
                            <span>Hi there </span>
                            <span><img src={wavingHand} alt=""/></span>
                        </p>
                        <h3>
                            We are <span>Javascript</span> user group
                        </h3>
                        <h5>
                        Come and meet other developers interested in the JavaScript World in the South Borneo area 
                        </h5>
                        <button className="btn btn--primary lg-mg-top">JOIN US</button>
                    </div>
                    <img className="hero__img" src={illustrateImg} />
                </div>
            </div>
        )
    }
}

export default HeroBanner