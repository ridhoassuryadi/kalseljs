// This Api Based on React Native Web

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
      ~style="",
      ~additionalClassName="",
      ~onScroll=?,
      ~onPress=?,
      ~onMouseEnter=?,
      ~onMouseLeave=?,
      ~onBlur=?,
      ~tabIndex=?,
      ~forwardRef=?,
      ~onKeyDown=?,
      ~id=?,
      ~children=?,
      ~onDoubleClick=?,
    ) => {


  let props =
    ReactDOMRe.objToDOMProps({
      "className": Styles.container ++ " " ++ additionalClassName,
      "onScroll": onScroll,
      "onClick": onPress,
      "onMouseEnter": onMouseEnter,
      "onMouseLeave": onMouseLeave,
      "onBlur": onBlur,
      "tabIndex": tabIndex,
      "ref": forwardRef,
      "onKeyDown": onKeyDown,
      "onDoubleClick": onDoubleClick,
      "id": id,
    });

  let child =
    switch (children) {
    | Some(child) => child
    | None => React.null
    };

  ReactDOMRe.createElement("div", ~props, [|child|]);
};