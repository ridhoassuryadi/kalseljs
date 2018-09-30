import React from 'react'

// Import Component
import Header from './Header'
import DescriptionInfo from '../components/DescriptionInfo'

// Asset
import NotFoundIllustrate from '../assets/images/illustrate--not-found.png'

const NotFound = () => (
    <div>
        <Header />
        <section className="full-height dis-flex align-item-center justify-center">
            <div className="container container--medium">
                <DescriptionInfo 
                    title="Ooops !"
                    classNameTitle="without-rect"
                    className="illustrate-right"
                    description="We sincerely apologize. we cant find the page you are looking for"
                    imgSrc={NotFoundIllustrate}
                    btn={{
                        text: 'BACK TO HOME',
                        to: '/',
                        type: "primary"
                    }}/>
            </div>
        </section>
    </div>
)

export default NotFound