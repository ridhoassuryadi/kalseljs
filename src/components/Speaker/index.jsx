import React, { Children } from 'react'

//Assets
import './style.scss'

const Speaker = ({ name, src }) => (
            <div className="speaker-list__item">
                img
                <h3>{ name }</h3>
            </div>
        )
        

class SpeakerList extends React.Component {
    render(){

        const children = React.Children.map(this.props.children, (child) => {
            if (child.type.displayName === "Speaker"){
                return child
            }else {
                return null
            }
        })
        return (
            <div className="speaker-list">
                { children }
            </div>
        )
    }
}

export { Speaker, SpeakerList}