import React from 'react'

import './style.scss'
import illusMeetup from '../../assets/images/meetup-poster.png';
import { MapPin } from 'react-feather';

class MeetupSection extends React.Component {
    render(){
        return (
            <section className="meetup-section bg-orange bs-pd-top align-center">
                <p className="text-section">NEXT EVENT</p>
                <div className="container flex-container">
                    <div className="flex-container__item--2 flex-dir-col justify-center bs-pd-right flex-one">
                        <div className="meetup-section__speaker">
                            <div className="meetup-section__speaker-item">
                                <h5>Muhammad Ridho</h5>
                                <p>Frontend Engineer kitabisa.com</p>
                            </div>
                            <div className="meetup-section__speaker-item">
                                <h5>Muslih Aqqad</h5>
                                <p>Software Engineer quipper</p>
                            </div>
                        </div>
                        <h2 className="meetup-section__title align-left">Mengenal UI / UX dari sudut pandang Developer</h2>
                        <div className="meetup-section__time text-18">
                            <p className="">16 November 2018</p>
                            <p>6.30 PM ( WIB )</p>
                        </div>
                        <p className="meetup-section__location">
                            <MapPin />
                            <a className="btn--link" href="">Munaqadh HQ , Banjar Digital Village</a>
                        </p>
                    </div>
                    <div className="flex-container__item--2 flex-dir-col">
                        <img className="align-self-center" src={illusMeetup} />
                        <button className="btn btn--primary btn--block lg-mg-top">RSVP NOW</button>
                    </div>
                </div>
            </section>
        )
    }
}

export default MeetupSection