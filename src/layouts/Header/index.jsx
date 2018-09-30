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
    state = {
      isOpen: false
    }

    toggleClick = () => {
      this.setState({
        isOpen: !this.state.isOpen
      })
    }

    hamburgerMenuClass = (menuIsOpen) => {
      if (menuIsOpen) {
        return "btn btn--hamburger-menu btn--hamburger-menu--open"
      } else {
        return "btn btn--hamburger-menu"
      }
    }

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
                    <button className={this.hamburgerMenuClass(this.state.isOpen)} onClick={this.toggleClick}>
                        <span />
                    </button>
                    <HamburgerMenu isOpen= {this.state.isOpen} />
                </header>

        )
    }
}

export default HeaderApp
