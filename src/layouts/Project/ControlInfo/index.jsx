import React from 'react'

// Assets
import './style.scss'

// Components
import SelectedList from '../../../components/SelectedLists'
import { Briefcase } from 'react-feather'

const itemTab = [
    { title: 'All'},
    { title: 'Open Source'},
    { title: 'Freelance' }
]
class ControlInfo extends React.Component {
    state = {
        selected: 0
    }
    render(){
        return (
            <section className="control-info">
                <h3 className="control-info__caption">
                    <span>Project</span>
                </h3>
                <div className="control-info__filter">
                    <SelectedList caption="Role"/>
                    <SelectedList caption="Categories" iconOptions={<Briefcase />}/>
                </div>
            </section>
        )
    }
}

export default ControlInfo