import React from 'react'

// Assets
import './style.scss'
import projectOne from '../../assets/images/project-1.png'

class Card extends React.Component {
    render(){
        return (
            <div className="flex-container__item--m4">
                <div className="m-card">
                    <div className="m-card__head">
                        <img className="m-card__thumb" src={projectOne} alt="Simpati Jawa Barat &amp; Netizen untuk Gempa Lombok"/>
                        <p className="m-card__tag">Open Source</p>
                    </div>
                    <div className="m-card__body">
                    <a href="/test" className="m-card__label">Fullstack Dev</a>
                        <h3 className="m-card__title">
                        Simpati Jawa Barat &amp; Netizen untuk Gempa Lombok 
                        </h3>
                    </div>
                </div>
            </div>
        )
    }
}

export default Card;