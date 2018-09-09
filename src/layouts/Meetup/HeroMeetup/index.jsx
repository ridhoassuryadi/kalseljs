import React from 'react'

// Component
import { Speaker, SpeakerList } from '../../../components/Speaker'

// Asset
import './style.scss'
import meetupIllus from '../../../assets/images/meetup__illus.svg';

export default class HeroMeetup extends React.Component {
    render(){
        return (
            <section id="heroMeetup">
                <div className="container flex-container">
                <div className="flex-col--m5">
                    <h5 className="hero-meetup__caption">Next Event</h5>
                    <h3 className="hero-meetup__title">Mengenal UI / UX dari sudut pandang Developer </h3>
                    <SpeakerList>
                        <Speaker name="ridho" />
                        <Speaker name="muslih aqqad"/>
                    </SpeakerList>
                        
                </div>
                <div className="flex-col--m5">
                    <img className="hero-meetup__poster" src={meetupIllus} />
                </div>
                </div>
            </section>
        )
    }
}