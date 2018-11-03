import React from 'react'

// Assets
import './style.scss'

// Components
import ButtonHilite from '../../components/ButtonHilite'

class HeroCleanDescription extends React.Component {
    render(){
        return (
            <section id="hero-clean-description">
                <div className="container">
                    <h3>Meet our Member</h3>
                    <p>We are passionate about the pursuit of ideas that put people first</p>
                    <ButtonHilite text="JOIN US" to="/become/member" />
                </div>
            </section>
        )
    }
}

export default HeroCleanDescription