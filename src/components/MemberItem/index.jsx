import React from 'react';

import { GitHub } from 'react-feather';
//  Assets
import './style.scss';

class MemberItem extends React.Component {
  render() {
    const { name } = this.props;
    return (
      <div className="flex-container__item--m4 member-item in-mobile-half">
        <img className="member-item__img" src="https://avatars0.githubusercontent.com/u/2532862?v=4" alt="" />
        <p>{ name }</p>
        <hr className="member-item__border" />
        <div className="member-item__socmed">
          <a href="" className="member-item__socmed--item">
            <GitHub />
          </a>
        </div>
      </div>
    );
  }
}

MemberItem.defaultProps = { name: 'Anggota Kita' };

export default MemberItem;
