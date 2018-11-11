import React from 'react';

// Assets
import './style.scss';

// Components
import ButtonGhost from '../ButtonGhost';

const BoxInformation = ({ title, description, action }) => (
  <div className="box-information">
    <h5 className="box-information__title">{ title }</h5>
    <p className="box-information__description">{ description }</p>
    <ButtonGhost caption="EMAIL US" />
  </div>
);

BoxInformation.defaultProps = {
  title: 'BE A MEMBER',
  description: 'Feel free if you had a question about this organization,  or just get information'
};

export default BoxInformation;
