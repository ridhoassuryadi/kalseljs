module Constants = {
  let defaultHeight = 0.5;
};

module Styles = {
  open Css;

  let createWrapper = (colors: Colors.t) =>
    style([
      backgroundColor(colors.grey.lightest),
      borderWidth(`rem(0.15)),
      borderStyle(`solid),
      borderColor(colors.black.neutral),
      borderRadius(Constants.defaultHeight->`rem),
      height(Constants.defaultHeight->`rem),
      position(`relative),
    ]);

  let createInner = (~colors: Colors.t, ~value) =>
    style([
      backgroundColor(colors.primary.neutral),
      width(`percent(value)),
      height(`percent(100.)),
      left(`zero),
      top(`zero),
      position(`absolute),
    ]);
};

[@react.component]
let make = (~value, ~accessibilityLabel=?) => {
  let colors = React.useContext(Theme.context);

  <View
    style={Styles.createWrapper(colors)}
    accessibilityRole="progressbar"
    ?accessibilityLabel>
    <View style={Styles.createInner(~colors, ~value)} />
  </View>;
};
