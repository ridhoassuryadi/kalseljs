type elevation = [ | `superLarge | `large | `medium | `small];
type t = [ | `Ring | `Shadow(elevation)];

module Styles = {
  open Css;

  let base = style([padding(`rem(1.0))]);

  let createRingStyle = (colors: Colors.t) =>
    style([
      borderWidth(`rem(0.15)),
      borderStyle(`solid),
      borderColor(colors.black.neutral),
      transitionDuration(100),
      transitionProperty("box-shadow"),
      transitionDelay(0),
      transitionTimingFunction(`ease),
      borderRadius(`rem(0.4)),
      hover([
        boxShadow(
          Shadow.box(
            ~x=px(0),
            ~y=px(0),
            ~blur=px(0),
            ~spread=px(4),
            colors.black.neutral,
          ),
        ),
      ]),
    ]);
  let createElevationShadow = elevation =>
    switch (elevation) {
    | `superLarge =>
      style([
        boxShadows([
          Shadow.box(
            ~x=px(0),
            ~y=px(1),
            ~blur=px(12),
            `rgba((13, 27, 56, 0.08)),
          ),
          Shadow.box(
            ~x=px(0),
            ~y=px(4),
            ~blur=px(6),
            `rgba((13, 27, 56, 0.1)),
          ),
          Shadow.box(
            ~x=px(0),
            ~y=px(2),
            ~blur=px(4),
            `rgba((13, 27, 56, 0.12)),
          ),
        ]),
      ])
    | `large =>
      style([
        boxShadows([
          Shadow.box(
            ~x=px(0),
            ~y=px(1),
            ~blur=px(6),
            `rgba((13, 27, 56, 0.08)),
          ),
          Shadow.box(
            ~x=px(0),
            ~y=px(3),
            ~blur=px(5),
            `rgba((13, 27, 56, 0.08)),
          ),
          Shadow.box(
            ~x=px(0),
            ~y=px(2),
            ~blur=px(5),
            `rgba((13, 27, 56, 0.12)),
          ),
        ]),
      ])
    | `medium =>
      style([
        boxShadows([
          Shadow.box(
            ~x=px(0),
            ~y=px(1),
            ~blur=px(5),
            `rgba((13, 27, 56, 0.08)),
          ),
          Shadow.box(
            ~x=px(0),
            ~y=px(2),
            ~blur=px(4),
            `rgba((13, 27, 56, 0.08)),
          ),
          Shadow.box(
            ~x=px(0),
            ~y=px(0),
            ~blur=px(3),
            `rgba((13, 27, 56, 0.12)),
          ),
        ]),
      ])
    | `small =>
      style([
        boxShadows([
          Shadow.box(
            ~x=px(0),
            ~y=px(2),
            ~blur=px(2),
            `rgba((0, 0, 0, 0.08)),
          ),
          Shadow.box(
            ~x=px(0),
            ~y=px(0),
            ~blur=px(3),
            `rgba((13, 27, 56, 0.1)),
          ),
        ]),
      ])
    };

  let createStyleBasedOnVariant = (~colors, ~variant) => {
    switch (variant) {
    | `Ring => createRingStyle(colors)
    | `Shadow(elevation) => createElevationShadow(elevation)
    };
  };
};

[@react.component]
let make =
    (~style as customStyle="", ~spacing="", ~variant, ~onPress=?, ~children) => {
  let colors = React.useContext(Theme.context);

  let resolvedStyle =
    Css.merge([
      Styles.base,
      Styles.createStyleBasedOnVariant(~colors, ~variant),
      spacing,
      customStyle,
    ]);

  <View style=resolvedStyle ?onPress> children </View>;
};
