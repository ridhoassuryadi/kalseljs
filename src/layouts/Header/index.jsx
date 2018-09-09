import React from 'react';
import Link from 'gatsby-link';

// Import assets
import logoImg from '../../assets/images/community__logo.svg';
import './style.scss';

// Import Component
import HamburgerMenu from '../HamburgerMenu'

// Styles when link is active
const activeStyle = {
    color: '#E06D2A'
}

class HeaderApp extends React.Component {
    render(){
        return (
                <header id="headerApp">
                    <img className="header__logo" src={logoImg} />
                    <ul className="header__links">
                        <li>
                            <Link to="/projects" activeStyle={activeStyle}>
                                Projects
                            </Link>
                        </li>
                        <li>
                            <Link to="/events" activeStyle={activeStyle}>
                                Events
                            </Link>
                        </li>
                        <li>
                            <Link to="/learnings">
                                Learnings
                            </Link>
                        </li>
                    </ul>
                    <button className="btn btn--hamburger-menu">
                        <span />
                    </button>
                    <HamburgerMenu />
                </header>
                
        )
    }
}

export default HeaderApp