open Utils.Option.Infix;

type textVariant = [ | `Primary | `Secondary];

type textSize = [ | `Small | `Medium | `Large];

type fontWeightType = [ | `Normal | `SemiBold | `Bold];

module Styles = {
  open Css;

  let base =
    style([
      borderWidth(zero),
      boxSizing(`borderBox),
      display(`inline),
      fontFamily("Rubik, sans-serif"),
      fontStyle(`inherit_),
      fontVariant(`normal),
      margin(zero),
      padding(zero),
      textDecoration(`none),
      whiteSpace(`preWrap),
      wordWrap(`breakWord),
    ]);

  let inlineDisplay = style([display(`inline)]);
  let blockDisplay = style([display(`block)]);

  let createStyleBasedOnTextSize = (textSize: textSize) =>
    switch (textSize) {
    | `Small => style([fontSize(`rem(0.8))])
    | `Medium => style([fontSize(`rem(1.10))])
    | `Large => style([fontSize(`rem(1.5))])
    };

  let createStyleBasedOnTextType =
      (textVariant: textVariant, colors: Colors.t) =>
    switch (textVariant) {
    | `Primary => style([color(colors.black.neutral)])
    | `Secondary => style([color(colors.black.lighter)])
    };

  let createStyleBasedOnWeight = (weight: fontWeightType) =>
    switch (weight) {
    | `Normal => style([fontWeight(`normal)])
    | `SemiBold => style([fontWeight(`semiBold)])
    | `Bold => style([fontWeight(`bold)])
    };

  let strikeThrough = style([textDecoration(`lineThrough)]);

  let maxLines = (~maxLines=?, ()) =>
    switch (maxLines) {
    | Some(value) =>
      style([
        textOverflow(`ellipsis),
        unsafe("display", "-webkit-box"),
        important(unsafe("-webkit-line-clamp", value |> string_of_int)),
        unsafe("-webkit-box-orient", "vertical"),
      ])
    | None => ""
    };
};

module Parent = {
  let context = React.createContext(false);

  module Provider = {
    let make = context->React.Context.provider;

    [@bs.obj]
    external makeProps:
      (~value: bool, ~children: React.element, ~key: string=?, unit) =>
      {
        .
        "value": bool,
        "children": React.element,
      } =
      "";
  };
};

[@react.component]
let make =
    (
      ~value=?,
      ~style="",
      ~variant: textVariant=`Primary,
      ~size: textSize=`Medium,
      ~weight: fontWeightType=`Normal,
      ~strikeThrough=false,
      ~maxLines=?,
      ~children=?,
      ~id=?,
      ~tooltip=?,
    ) => {
  let colors = React.useContext(Theme.context);
  let hasParentText = React.useContext(Parent.context);

  let resolvedStyle =
    [
      Styles.base,
      Styles.createStyleBasedOnTextType(variant, colors),
      Styles.createStyleBasedOnTextSize(size),
      Styles.createStyleBasedOnWeight(weight),
      hasParentText ? Styles.inlineDisplay : Styles.blockDisplay,
      strikeThrough ? Styles.strikeThrough : "",
      Styles.maxLines(~maxLines?, ()),
      style,
    ]
    ->Css.merge;

  let text =
    switch (value) {
    | Some(v) => React.string(v)
    | None => children |? ReasonReact.null
    };

  if (hasParentText) {
    <span ?id className=resolvedStyle> text </span>;
  } else {
    <Parent.Provider value=true>
      <p ?id title=?tooltip className=resolvedStyle> text </p>
    </Parent.Provider>;
  };
};
