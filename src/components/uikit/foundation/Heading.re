open Utils.Option.Infix;

type variant = [ | `H1 | `H2 | `H3 | `H4 | `H5 | `H6];
type textWeight = [ | `Bold | `Semibold | `Medium ];

module Styles = {
  open Css;

  let base =
    style([
      fontFamily("Rubik, serif"),
      fontWeight(`medium),
      fontStyle(`normal),
      lineHeight(`normal),
      marginTop(`rem(0.)),
      marginBottom(`rem(0.8)),
    ]);

  let createStyleBasedOnWeight =
    fun
    | `Medium => style([fontWeight(`medium)])
    | `Semibold => style([fontWeight(`semiBold)])
    | `Bold => style([fontWeight(`bold)])

  let createStyleBasedOnType =
    fun
    | `H1 => style([
        fontSize(`rem(3.4)),
        lineHeight(`abs(1.25))
        ])
    | `H2 => style([
        fontSize(`rem(2.8)),
        lineHeight(`abs(1.30))
        ])
    | `H3 => style([
        fontSize(`rem(2.25)),
        ])
    | `H4 => style([
        fontSize(`rem(1.8)),
        lineHeight(`rem(2.45)),
        ])
    | `H5 => style([
        fontSize(`rem(1.4)),
        lineHeight(`rem(1.95)),
    ])
    | `H6 => style([
        fontSize(`rem(1.1)),
        lineHeight(`rem(1.3))
        ]);
};


[@react.component]
let make =
    (
      ~value=?,
      ~as_: variant,
      ~weight: textWeight = `Medium,
      ~style="",
    ) => {

  let resolvedStyle =
    Css.merge([
      Styles.base,
      Styles.createStyleBasedOnWeight(weight),
      Styles.createStyleBasedOnType(as_),
      style,
    ]);

  let child = value <$> React.string |? React.null;

  let component =
    switch (as_) {
    | `H1 => <h1 className=resolvedStyle> child </h1>
    | `H2 => <h2 className=resolvedStyle> child </h2>
    | `H3 => <h3 className=resolvedStyle> child </h3>
    | `H4 => <h4 className=resolvedStyle> child </h4>
    | `H5 => <h5 className=resolvedStyle> child </h5>
    | `H6 => <h6 className=resolvedStyle> child </h6>
    };

    component
};
