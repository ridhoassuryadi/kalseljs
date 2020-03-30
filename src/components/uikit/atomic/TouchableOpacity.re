type container = [ | `Column | `Row];

module Styles = {
  open Css;

  let create = (activeOpacity, hoverOpacity) =>
    style([
      backgroundColor(`transparent),
      active([opacity(activeOpacity), transition(~duration=0, "opacity")]),
      hover([
        opacity(hoverOpacity),
        transition(~duration=0, "opacity"),
        unsafe("cursor", Constants.Styles.Cursor.pointer),
      ]),
      zIndex(1),
    ]);
};

[@react.component]
let make =
    (
      ~onPress=?,
      ~tabIndex=?,
      ~onBlur=?,
      ~style="",
      ~hoverOpacity=0.85,
      ~activeOpacity=0.5,
      ~accessibilityRoleDescription=?,
      ~containerType: container=`Column,
      ~accessibilityLabel=?,
      ~children,
    ) => {
  let resolvedStyle =
    Css.merge([Styles.create(activeOpacity, hoverOpacity), style]);

  switch (containerType) {
  | `Column =>
    <View
      as_=`Button
      accessibilityRole="button"
      ?accessibilityLabel
      ?accessibilityRoleDescription
      style=resolvedStyle
      ?onPress
      ?tabIndex
      ?onBlur>
      children
    </View>
  | `Row => <Row style=resolvedStyle ?onPress> children </Row>
  };
};
