import {configure} from '@storybook/react';

function loadStories() {
  const req = require.context('../__stories__', true, /\.bs\.js$/);
  req.keys().forEach((filename) => req(filename));
}

configure(loadStories, module);