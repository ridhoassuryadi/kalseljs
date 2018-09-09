import React from 'react';
import ReactDOM  from 'react-dom';
import { ChevronRight } from 'react-feather';

// Import style
import './style.scss'

// Import Component
import illustrateLaptop from '../../assets/images/illustrate__description-1.svg';
import illustrateBook from '../../assets/images/illustrate__description-2.svg';
import DescriptionInfo from '../../components/DescriptionInfo'

class Description extends React.Component {

    render(){
        return (
            <section id="description">
                <div className="description__info">
                    <p>
                        WHAT WE DO
                    </p>
                </div>
                <div className="container container--medium sp-mg-top lg-pd-top">
                    <DescriptionInfo 
                        title="Meet and Share"
                        description="Meet the javascript developers fellow in South Kalimantan to share knowledge and exchange experiences in tackling various cases."
                        imgSrc={illustrateLaptop}
                        btn={{
                            text: 'Look our Events',
                            to: '/events'
                        }} />
                    <DescriptionInfo 
                        title="Join the project"
                        description="Get ready to involve and collaborate on the challenging project. Share your experience working on the interesting project."
                        imgSrc={illustrateBook}
                        btn={{
                            text: 'Join great project',
                            to: '/projects'
                        }}/>
                </div>
            </section>
        )
    }
}

export default Description