open Utils.Option.Infix;

type variant = [ | `Primary | `Secondary | `PrimaryOutlined | `Disabled];

type size = [ | `Large | `Medium | `Small];

module Styles = {
  open Css;

  let baseStyle =
    style([
      justifyContent(`center),
      alignItems(`center),
      flex(`num(1.)),
      flexWrap(`nowrap),
      borderRadius(`rem(0.4)),
      lineHeight(`abs(1.5)),
      fontWeight(`medium),
      hover([
        transitionDuration(200),
        transitionProperty("all"),
        transitionDelay(0),
        transitionTimingFunction(`easeInOut),
      ]),
    ]);

  let createStyleBasedOnVariant = (~colors: Colors.t, ~variant: variant) =>
    switch (variant) {
    | `Primary =>
      style([
        backgroundColor(colors.black.neutral),
        active([backgroundColor(colors.primary.neutral), opacity(1.)]),
        hover([backgroundColor(colors.primary.neutral)]),
      ])
    | `Secondary =>
      style([
        backgroundColor(colors.primary.neutral),
        active([backgroundColor(colors.primary.darkest), opacity(1.)]),
        hover([backgroundColor(colors.primary.darker), opacity(1.)]),
      ])
    | `PrimaryOutlined =>
      style([
        backgroundColor(colors.grey.lightest),
        borderWidth(`rem(0.15)),
        borderStyle(`solid),
        borderColor(colors.black.neutral),
        boxShadow(
          Shadow.box(
            ~x=pxFloat(1.65),
            ~y=px(1),
            ~blur=px(0),
            ~spread=pxFloat(0.5),
            colors.black.neutral,
          ),
        ),
        hover([
          backgroundColor(colors.grey.lightest),
          transforms([translate(px(2), px(2))]),
          boxShadow(Shadow.box(~x=px(0), ~y=px(0), colors.black.neutral)),
        ]),
      ])
    | `Disabled =>
      style([backgroundColor(colors.black.lightest), cursor(`notAllowed)])
    };

  let createTouchableContainer = block => {
    let base = style([padding(`px(2))]);
    let styleBasedOnBlock =
      block ? style([display(`flex), flex(`num(1.))]) : "";
    Css.merge([base, styleBasedOnBlock]);
  };

  let createStyleBasedOnWidth = (~block: bool, ~size: size) =>
    block
      ? style([display(`flex), flex(`num(1.))])
      : (
        switch (size) {
        | `Large => style([padding2(~v=`rem(0.75), ~h=`rem(1.4))])
        | `Medium => style([padding2(~v=`rem(0.46), ~h=`rem(1.1))])
        | `Small => style([padding2(~v=`rem(0.26), ~h=`rem(0.9))])
        }
      );

  let textStyle =
    style([
      fontSize(`rem(14.)),
      fontWeight(`medium),
      letterSpacing(`rem(0.01)),
      flexWrap(`nowrap),
    ]);

  let createTextStyleBasedOnVariant = (~colors: Colors.t, ~variant: variant) =>
    switch (variant) {
    | `Primary => style([color(colors.grey.lightest)])
    | `Secondary => style([color(colors.grey.lightest)])
    | `PrimaryOutlined => style([color(colors.black.neutral)])
    | `Disabled => style([color(colors.grey.lightest)])
    };
};

[@react.component]
let make =
    (
      ~onPress=?,
      ~variant: variant=`Primary,
      ~size=`Medium,
      ~block=false,
      ~onBlur=?,
      ~tabIndex=?,
      ~text=?,
      ~children=?,
      ~containerStyle="",
      ~textStyle="",
    ) => {
  let colors = React.useContext(Theme.context);

  let resolvedStyle =
    Css.merge([
      containerStyle,
      Styles.baseStyle,
      Styles.createStyleBasedOnWidth(~block, ~size),
      Styles.createStyleBasedOnVariant(~colors, ~variant),
      Styles.createTextStyleBasedOnVariant(~colors, ~variant),
    ]);

  let resolvedTextStyle =
    Css.merge([
      Styles.createTextStyleBasedOnVariant(~colors, ~variant),
      textStyle,
    ]);

  <TouchableOpacity
    onPress=?{
      switch (variant) {
      | `Disabled => None
      | _ => onPress
      }
    }
    ?onBlur
    ?tabIndex
    style={Styles.createTouchableContainer(block)}>
    <View style=resolvedStyle>
      {switch (text) {
       | Some(txt) => <Text value=txt style=resolvedTextStyle />
       | None => children |? React.null
       }}
    </View>
  </TouchableOpacity>;
};
