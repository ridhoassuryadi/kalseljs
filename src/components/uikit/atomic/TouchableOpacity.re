type container = [ | `Column | `Row];

module Styles = {
  open Css;

  let create = (activeOpacity, hoverOpacity) =>
      style([
        active([
          opacity(activeOpacity),
          transition(~duration=0, "opacity"),
        ]),
        hover([
          opacity(hoverOpacity),
          transition(~duration=0, "opacity"),
          cursor(`pointer),
        ]),
        zIndex(1),
      ])
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
      ~containerType: container=`Column,
      ~children,
    ) => {
  let resolvedStyle =
    Css.merge([
      Styles.create(activeOpacity, hoverOpacity),
      style,
    ]);

  switch (containerType) {
  | `Column =>
    <View style=resolvedStyle ?onPress ?tabIndex ?onBlur >
      children
    </View>
  | `Row => <Row style=resolvedStyle ?onPress> children </Row>
  };
};
