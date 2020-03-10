import React from 'react'
import {configure, addDecorator } from '@storybook/react';
import GlobalStyle from '../src/components/uikit/templates/Global.bs';

const Decorator = storyFn => (
    <GlobalStyle>
        {storyFn()}
    </GlobalStyle>
);

addDecorator(Decorator);

function loadStories() {
  const req = require.context('../__stories__', true, /\.bs\.js$/);
  req.keys().forEach((filename) => req(filename));
}

configure(loadStories, module);