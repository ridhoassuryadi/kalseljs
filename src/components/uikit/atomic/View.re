// This Api Based on React Native Web

[@bs.deriving jsConverter]
type variant = [ | `Section | `Div | `Button | `Span];

module Styles = {
  open Css;
  let container =
    style([
      alignItems(`stretch),
      borderWidth(`pt(0)),
      borderStyle(`solid),
      boxSizing(`borderBox),
      display(`flex),
      flexDirection(`column),
      flexGrow(0.),
      flexShrink(0.),
      margin(`pt(0)),
      padding(`pt(0)),
      position(`relative),
      minHeight(`pt(0)),
      minWidth(`pt(0)),
      userSelect(`none),
    ]);
};

[@react.component]
let make =
    (
      ~as_=`Div,
      ~style="",
      ~additionalClassName="",
      ~onScroll=?,
      ~onPress=?,
      ~onMouseEnter=?,
      ~onMouseLeave=?,
      ~onBlur=?,
      ~forwardRef=?,
      ~onKeyDown=?,
      ~accessibilityLabel=?,
      ~accessibilityRole=?,
      ~accessibilityRoleDescription=?,
      ~accessibilityLabelledBy=?,
      ~id=?,
      ~children=?,
      ~onDoubleClick=?,
      ~tabIndex=0,
    ) => {
  let props =
    ReactDOMRe.objToDOMProps({
      "className": Css.merge([Styles.container, style]),
      "onScroll": onScroll,
      "onClick": onPress,
      "onMouseEnter": onMouseEnter,
      "onMouseLeave": onMouseLeave,
      "onBlur": onBlur,
      "tabIndex": tabIndex,
      "ref": forwardRef,
      "onKeyDown": onKeyDown,
      "onDoubleClick": onDoubleClick,
      "aria-label": accessibilityLabel,
      "aria-roledescription": accessibilityRoleDescription,
      "aria-labelledby": accessibilityLabelledBy,
      "role": accessibilityRole,
      "id": id,
    });

  let child =
    switch (children) {
    | Some(child) => child
    | None => React.null
    };

  ReactDOMRe.createElement(
    as_->variantToJs->String.lowercase,
    ~props,
    [|child|],
  );
};
