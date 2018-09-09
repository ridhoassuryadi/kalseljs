import React from 'react'

// Import Component
import ButtonLink from '../ButtonLink'

class DescriptionInfo extends React.Component {
    render(){
        return (
            <div className="description__section">
            <div className="description__section-illustrate">
                <img src={this.props.imgSrc} alt=""/>
            </div>
            <div className="description__section-text">
                <h3 className="text-title">
                    {this.props.title}
                </h3>
                <p>
                    {this.props.description}
                </p>
                <ButtonLink 
                    text={this.props.btn.text}
                    to={this.props.btn.to}
                />
            </div>
        </div>
        )
    }
}

export default DescriptionInfo