open Utils.Option.Infix;

module Styles = {
  open Css;
  let createBase = (~colors: Colors.t, ~customWidth) =>
    style([
      height(`px(1)),
      customWidth <$> (customWidth' => width(customWidth')) |? width(`auto),
      margin(`rem(1.2)),
      backgroundColor(colors.primary.lightest),
    ]);
};

[@react.component]
let make = (~width as customWidth=?) => {
  let colors = React.useContext(Theme.context);

  let props =
    ReactDOMRe.objToDOMProps({
      "className": Styles.createBase(~customWidth, ~colors),
      "aria-label": "divider",
      "aria-labelledby": "divider",
      "role": "divider",
    });

  ReactDOMRe.createElement("div", ~props, [||]);
};
