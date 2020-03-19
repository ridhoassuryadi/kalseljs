type prefixPhone = string;

type variant = [
  | `Text
  | `Number
  | `Password
  | `Phone(prefixPhone)
  | `Date
  | `Time
  | `Email
  | `File
  | `Color
];

type prefix = [ | `Icon(React.element) | `Nothing];
type lineType = [ | `Multiple | `Single];
type status = [ | `Ok | `Error(string) | `Idle];

module Styles = {
  open Css;
  let createOuter = (~lineType, ~colors: Colors.t) => {
    let base =
      style([
        marginBottom(`rem(1.6)),
        marginTop(`rem(0.8)),
        position(`relative),
      ]);

    let styleBasedOnLineType =
      switch (lineType) {
      | `Single => style([])
      | `Multiple =>
        style([
          after([
            position(`absolute),
            unsafe("content", "''"),
            unsafe("-webkit-transform", "rotate(-45deg)"),
            backgroundColor(colors.black.neutral),
            zIndex(1),
            bottom(`px(6)),
            right(`px(6)),
            pointerEvents(`none),
            width(`rem(0.6)),
            height(`rem(0.6)),
            unsafe("clip-path", "polygon(0% 0%, 100% 100%, 0% 100%)"),
            borderTopRightRadius(`zero),
            borderBottomLeftRadius(`rem(0.15)),
            borderTopLeftRadius(`rem(0.15)),
            borderTopRightRadius(`rem(0.15)),
            borderBottomRightRadius(`zero),
            transform(rotate(`deg(-90.))),
          ]),
        ])
      };

    Css.merge([base, styleBasedOnLineType]);
  };
  let textCommon = style([fontSize(`rem(1.))]);
  let createInput = (~prefix, ~colors: Colors.t) => {
    let base =
      style([
        focus([outlineStyle(`none)]),
        placeholder([color(colors.black.lightest)]),
        borderColor(colors.black.lighter),
        borderRadius(`rem(0.5)),
        borderStyle(`solid),
        borderWidth(`rem(0.1)),
        boxSizing(`borderBox),
        color(colors.black.darkest),
        padding2(~v=`rem(0.84), ~h=`rem(0.8)),
        position(`relative),
        zIndex(1),
        margin(`zero),
        resize(`vertical),
      ]);

    let styleBasedOnPrefix =
      switch (prefix) {
      | `Icon(_) => style([paddingLeft(`rem(2.4))])
      | _ => ""
      };

    Css.merge([base, styleBasedOnPrefix, textCommon]);
  };
  let createPrefix = (colors: Colors.t) =>
    [
      style([
        backgroundColor(colors.black.lightest),
        borderRadius(`rem(0.2)),
        color(colors.black.darkest),
        width(`rem(5.)),
        height(`calc((`sub, `percent(100.0), `rem(0.2)))),
        display(`flex),
        alignItems(`center),
        justifyContent(`center),
        height(`percent(100.)),
        position(`absolute),
        marginLeft(`rem(0.1)),
        marginTop(`rem(0.1)),
        marginBottom(`rem(0.1)),
        zIndex(2),
      ]),
      textCommon,
    ]
    ->merge;
  let createError = (colors: Colors.t) =>
    [
      style([
        color(colors.danger.neutral),
        fontSize(`rem(1.4)),
        marginTop(`rem(0.4)),
      ]),
      textCommon,
    ]
    ->merge;

  let wrapperIcon =
    style([
      width(`rem(1.5)),
      height(`rem(1.5)),
      justifyContent(`center),
      alignItems(`center),
      position(`absolute),
      top(`percent(50.)),
      transform(translate(`percent(50.), `percent(-50.))),
      zIndex(2),
    ]);
};
[@react.component]
let make =
    (
      ~variant: variant=`Text,
      ~forwardRef=?,
      ~value=?,
      ~onBlur=?,
      ~lineType=`Single,
      ~onChange,
      ~onKeyDown=?,
      ~autoComplete=false,
      ~placeholder="",
      ~status=`Idle,
      ~prefix=`Nothing,
      ~onFocus=?,
      ~style="",
      ~inputStyle="",
      ~prefixStyle="",
      ~inputPrefixStyle="",
      ~disabled=false,
      ~min=?,
      ~max=?,
      ~name=?,
      ~rows=?,
      ~step=?,
    ) => {
  let colors = React.useContext(Theme.context);
  let resolvedStyle =
    [Styles.createOuter(~lineType, ~colors), style]->Css.merge;
  let resolvedInputStyle =
    Css.merge([Styles.createInput(~prefix, ~colors), inputStyle]);
  let inputType =
    switch (variant) {
    | `Text
    | `Phone(_) => "text"
    | `Email => "email"
    | `Number => "number"
    | `Date => "date"
    | `Password => "password"
    | `Time => "time"
    | `File => "file"
    | `Color => "color"
    };

  let props =
    ReactDOMRe.objToDOMProps({
      "ref": forwardRef,
      "name": name,
      "type": inputType,
      "placeholder": placeholder,
      "value": value,
      "onBlur": onBlur,
      "onChange": onChange,
      "onKeyDown": onKeyDown,
      "onFocus": onFocus,
      "disabled": disabled,
      "step": step,
      "min": min,
      "max": max,
      "rows": rows,
      "autoComplete": string_of_bool(autoComplete),
      "className": resolvedInputStyle,
    });
  let prefixComponent =
    switch (prefix) {
    | `Icon(iconComponent) =>
      <View style=Styles.wrapperIcon> iconComponent </View>
    | `Nothing => React.null
    };
  let resolvedComponent =
    switch (lineType) {
    | `Multiple => ReactDOMRe.createElement("textarea", ~props, [||])
    | `Single => ReactDOMRe.createElement("input", ~props, [||])
    };
  let errorComponent =
    switch (status) {
    | `Error(value) => <Text style={Styles.createError(colors)} value />
    | _ => ReasonReact.null
    };
  <View style=resolvedStyle>
    <View> prefixComponent resolvedComponent </View>
    errorComponent
  </View>;
};
