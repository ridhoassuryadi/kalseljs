import React from 'react'

// Import Component
import Card from '../../../components/Card'

class ProjectLists extends React.Component {
    render(){
        return (
            <div className="col flex-container flex-container--lists lg-mg-tb">
                { ['1', '2', '3', '4'].map(() =>                 <Card />)}
            </div>
        )
    }
}

export default ProjectLists