import React from 'react'
import ReactDOM  from 'react-dom';
import { ChevronRight } from 'react-feather';

class ButtonLink extends React.Component {

    _getRectangle(e){
        return  ReactDOM.findDOMNode(e.target).getElementsByClassName('btn--link__rect')[0]
    }

    _hover = (e) => {
        try {
            // FIND Child with rectangle, for add animation
            let _rectangle = this._getRectangle(e)
            return _rectangle.classList.add('hovered')
        }catch(e){

        }
    }

    _unHover = (e) => {
        try {
            let _rectangle = this._getRectangle(e)
            _rectangle.classList.add('unhovered')
    
            setTimeout(() => {
                _rectangle.classList.remove('hovered')
                _rectangle.classList.remove('unhovered')
            }, 400);
        }catch(e){
            
        }
    }


    render(){
        return (
            <button className="btn btn--link" onMouseEnter={(e) => this._hover(e)} onMouseLeave={(e) => this._unHover(e)}>
            <ChevronRight />
            <span className="btn--link__text">{this.props.text}</span>
            <span className="btn--link__rect"/></button>
        )
    }
}

export default ButtonLink