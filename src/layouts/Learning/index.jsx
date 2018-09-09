import React from 'react'

import illusLibJS from '../../assets/images/all-lib.svg'
import './style.scss'

class LearningInfo extends React.Component {
    render(){
        return (
            <div className="container align-center learning-promote lg-pd-top">
                <p className="text-section sp-mg-top">AND EXPLORE MORE</p>
                <img  className="lg-mg-top" src={illusLibJS} alt=""/>
                <h3 className="text-title bs-mg-bottom">Get tutorial with focused Javascript and Library</h3>
                <button className="btn btn--primary">LEARN NOW</button>
            </div>
        )
    }
}

export default LearningInfo