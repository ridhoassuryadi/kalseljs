open Utils.Option.Infix;

module Styles = {
  open Css;
  let container = style([alignItems(`center)]);
  let label = style([marginLeft(`rem(0.5))]);

  let createCheckboxContainerStyle = (~isChecked, ~colors: Colors.t) => {
    let base =
      style([
        height(`rem(1.5)),
        width(`rem(1.5)),
        borderRadius(`rem(0.2)),
        backgroundColor(`hex("fff")),
        justifyContent(`center),
        alignItems(`center),
      ]);

    let styleBasedOnIsChecked =
      if (isChecked) {
        style([backgroundColor(colors.primary.neutral)]);
      } else {
        style([
          border(`rem(0.125), `solid, colors.black.neutral),
          hover([backgroundColor(colors.primary.lightest)]),
        ]);
      };

    Css.merge([base, styleBasedOnIsChecked]);
  };

  let checkbox =
    style([visibility(`hidden), width(`px(1)), height(`px(1))]);
  let touchArea =
    style([
      display(`flex),
      flexDirection(`row),
      alignItems(`center),
      unsafe("cursor", Constants.Styles.Cursor.pointer),
    ]);
};

[@react.component]
let make = (~isChecked=false, ~onPress, ~label=?) => {
  let colors = React.useContext(Theme.context);

  <View onPress style=Styles.touchArea>
    <View style={Styles.createCheckboxContainerStyle(~isChecked, ~colors)}>
      {isChecked ? <Icons.Checkmark /> : React.null}
    </View>
    <input type_="checkbox" checked=isChecked className=Styles.checkbox />
    {label
     <$> (label => <Text style=Styles.label> {React.string(label)} </Text>)
     |? React.null}
  </View>;
};

let default = make;
