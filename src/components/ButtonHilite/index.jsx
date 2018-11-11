import React from 'react'

// Component
import { Link } from 'gatsby'

class ButtonHilite extends React.Component {
    render(){
        const { text, to } = this.props 
        return (
            <Link className="btn btn--hilite" to={to}
            > {text} </Link>
        )
    }
}

export default ButtonHilite