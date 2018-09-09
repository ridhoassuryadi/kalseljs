import React from 'react'
import { Search } from 'react-feather';

// Assets
import './style.scss'

class HeroProject extends React.Component {
    state = {
        focus: false,
    }

    render(){
        return (
           <section className="hero-project">
                <div className="container">
                    <h3>Find Your greatest <br />Project.</h3>
                    <div className={`hero-project__input ${this.state.focus ? 'on-focus' : '' }`}>
                        <Search />
                        <input 
                            type="search" placeholder='"try validator"'
                            onFocus={() => this.setState({ focus: true})}
                            onBlur={() => this.setState({ focus: false })}/>
                    </div>
                </div>
           </section>
        )
    }
}

export default HeroProject