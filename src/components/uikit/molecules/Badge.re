open Utils.Option.Infix;

module Styles = {
  open Css;

  let createBase = (colors: Colors.t) =>
    style([
      justifyContent(`center),
      alignItems(`center),
      flex(`num(1.)),
      flexWrap(`nowrap),
      borderRadius(`rem(1.6)),
      lineHeight(`abs(1.5)),
      padding2(~v=`rem(0.26), ~h=`rem(0.9)),
      alignItems(`center),
      fontWeight(`medium),
      backgroundColor(`transparent),
      borderWidth(`rem(0.1)),
      borderStyle(`solid),
      borderColor(colors.black.lightest),
      selector("image", [filter([`invert(0.)])]),
      hover([
        backgroundColor(colors.primary.neutral),
        selector("p", [color(colors.grey.lightest)]),
        selector("image", [filter([`invert(100.)])]),
      ]),
    ]);

  let text = style([marginLeft(`rem(0.4))]);
  let image =
    style([
      display(`flex),
      width(`rem(1.)),
      height(`rem(1.)),
      justifyContent(`center),
      alignItems(`center),
    ]);
};

[@react.component]
let make = (~prefixIcon=?, ~onPress=?, ~text) => {
  let colors = React.useContext(Theme.context);
  <TouchableOpacity ?onPress>
    <Row style={Styles.createBase(colors)}>
      <image className=Styles.image> {prefixIcon |? ReasonReact.null} </image>
      <Text size=`Small value=text style=Styles.text />
    </Row>
  </TouchableOpacity>;
};
