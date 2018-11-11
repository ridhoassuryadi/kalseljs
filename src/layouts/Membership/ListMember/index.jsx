import React from 'react';

// Assets
import MemberItem from '../../../components/MemberItem';
import './style.scss';

class ListMember extends React.Component {
  render() {
    return (
      <section id="memberList">
        <div className="container">
          <div className="description__section-text sp-mg-bottom">
            <h3 className="text-title">
                  So here we are
            </h3>
          </div>
          <div className="col flex-container flex-container--lists lg-mg-tb">
            <MemberItem />
            <MemberItem />
            <MemberItem />
          </div>
        </div>
      </section>
    );
  }
}

export default ListMember;
