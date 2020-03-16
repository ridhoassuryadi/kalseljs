// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var React$1 = require("@storybook/react");
var AddonActions = require("@storybook/addon-actions");
var Constants$KalseljsCommunityPage = require("../../src/commons/Constants.bs.js");
var TouchableOpacity$KalseljsCommunityPage = require("../../src/components/uikit/atomic/TouchableOpacity.bs.js");

function str(prim) {
  return prim;
}

var jsModule = module;

React$1.storiesOf(Constants$KalseljsCommunityPage.Storybook.storiesOf(/* `Components */[
            -791693002,
            /* Atomics */573549320
          ]), jsModule).add("Touchable Opacity", (function (param) {
        return React.createElement(TouchableOpacity$KalseljsCommunityPage.make, {
                    onPress: AddonActions.action("Yeay you clicked it !"),
                    children: "Click me"
                  });
      }));

var StorybookConst = 0;

var Action = 0;

exports.StorybookConst = StorybookConst;
exports.Action = Action;
exports.str = str;
exports.jsModule = jsModule;
/* jsModule Not a pure module */
