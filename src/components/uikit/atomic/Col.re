open Utils.Option.Infix;

module Styles = {
  open Css;
  let merge = Css.merge;
  let createBase = (justifyContentValue, alignItemsValue) => {
    let base = style([flexDirection(`column)]);
    merge([
      base,
      justifyContentValue <$> (v => style([justifyContent(v)])) |? "",
      alignItemsValue <$> (v => style([alignItems(v)])) |? "",
    ]);
  };
};

[@react.component]
let make =
    (
      ~style="",
      ~forwardRef=?,
      ~onScroll=?,
      ~onPress=?,
      ~onMouseEnter=?,
      ~onMouseLeave=?,
      ~justifyContent=?,
      ~alignItems=?,
      ~accessibilityLabel=?,
      ~accessibilityRole=?,
      ~accessibilityRoleDescription=?,
      ~accessibilityLabelledBy=?,
      ~as_=?,
      ~id=?,
      ~children,
    ) => {
  let resolvedStyle =
    [Styles.createBase(justifyContent, alignItems), style]->Css.merge;
  <View
    style=resolvedStyle
    ?forwardRef
    ?onScroll
    ?onPress
    ?onMouseEnter
    ?onMouseLeave
    ?accessibilityLabel
    ?accessibilityRole
    ?accessibilityRoleDescription
    ?accessibilityLabelledBy
    ?id
    ?as_>
    children
  </View>;
};
