/**
 * How to Use:
 * 
 * <SelectedList
 *  items=[{ }]
 *  selected={}
 *  onSelect={}
 *   />
 */

 import React from 'react'

 // Assets
 import { ChevronDown, User } from 'react-feather'
 import './style.scss'

 class SelectedList extends React.Component {
     state = {
         isOpened : false
     }

     componentDidMount() {
        document.addEventListener('click', this.handleClickOutside);
      }
    
      componentWillUnmount() {
        document.removeEventListener('click', this.handleClickOutside);
      }

     setOpened = (e) => {
            this.setState({ isOpened: !this.state.isOpened}) 
     }

     setRef = (node) => {
        this.dropdownRef = node
     }

     handleClickOutside = (event) => {
        if (this.dropdownRef && !this.dropdownRef.contains(event.target) && !this.buttonTrigger.contains(event.target)) {
            this.setState({ isOpened: false })
        }
      }


     render(){
         return (
            <div className={`selected-list ${this.state.isOpened ? ' is-selected' : ''}`}>
                <button ref={(node) => this.buttonTrigger = node } className="selected-list__button" onClick={() => { this.setOpened()}} >
                    <span className="selected-list__button-icon">{ this.props.iconOptions }</span>
                    <span className="selected-list__button-caption">{ this.props.caption }</span>
                    <span className="selected-list__button-selected">All</span>
                    <span className="selected-list__button-dropdown-icon"><ChevronDown /></span>
                </button>
                <div className="selected-list__options">
                    <ul ref={this.setRef}>
                        <li>All</li>
                        <li>Open Source</li>
                        <li>Freelance</li>
                    </ul>
                </div>
            </div>
         )
     }
 }

SelectedList.defaultProps = {
    items: ['All', 'First Item', 'Second Item'],
    caption: 'Item',
    iconOptions: <User />
}

export default SelectedList;