import React from 'react'

// Images
import logoImg from '../../assets/images/community__logo.svg'
import footerPattern1 from '../../assets/images/pattern-footer-1.svg'
import footerPattern2 from '../../assets/images/pattern-footer-2.svg'

class Footer extends React.Component {
    render(){
        return (
            <footer id="footerSite" className="no-pd-top">
                <div className="pos-r lg-pd-top">
                    <img src={footerPattern1} className="footer-pattern footer-pattern--1" />
                    <img src={footerPattern2} className="footer-pattern footer-pattern--2" />
                    <img src={footerPattern1} className="footer-pattern footer-pattern--3" />
                    <img src={footerPattern2} className="footer-pattern footer-pattern--4" />
                    <div className="container flex-container">
                        <div className="flex-col flex-col--m4 footer-description">
                            <img src={logoImg} alt=""/>
                            <p className="text-14 sp-mg-right">Come and meet other developers interested in the JavaScript World in the South Borneo area </p>
                        </div>
                        <div className="flex-col flex-col--m2 in-mobile-full">
                            <h5 className="text-18 text-semibold">Organization</h5>
                            <ul>
                                <li className="text-14"><a href="">About us</a></li>
                                <li className="text-14"><a href="">Our Rules</a></li>
                            </ul>
                        </div>
                        <div className="flex-col flex-col--m2 in-mobile-full">
                            <h5 className="text-18 text-semibold">Join</h5>
                            <ul>
                                <li className="text-14"><a href="">Become member</a></li>
                                <li className="text-14"><a href="">Become speaker</a></li>
                                <li className="text-14"><a href="">Become organizer</a></li>
                                <li className="text-14"><a href="">Become sponsor</a></li>
                            </ul>
                        </div>
                        <div className="flex-col flex-col--m2 in-mobile-full">
                            <h5 className="text-18 text-semibold">Activity</h5>
                            <ul>
                                <li className="text-14"><a href="">Events</a></li>
                                <li className="text-14"><a href="">Projects</a></li>
                                <li className="text-14"><a href="">Learning</a></li>
                            </ul>
                        </div>
                    </div>
                </div>
                <div className="footer-copyright align-center">
                    <p className="text-12">© 2018 KalselJS — Powered by Urang Banua</p>
                </div>
            </footer>
        )
    }
}

export default Footer