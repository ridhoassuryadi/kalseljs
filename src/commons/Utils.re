// str = "2018-10-27T22:40:32.169Z"
// result = "Sunday, February 17, 2019"

let formatDate = (isoDateString: string) => {
  DateFns.internal_format(
    Js.Date.fromString(isoDateString),
    "dddd, MMMM D, YYYY",
  );
};

module Option = {
  module Infix = {
    let (|?) = (option, defaultValue) =>
      switch (option) {
      | Some(value) => value
      | None => defaultValue
      };

    let (>>=) = Belt.Option.flatMap;

    let (<$>) = Belt.Option.map;
  };
};

module Styles = {
  open Css;

  module Spacing = {
    open Option.Infix;

    type t = string;

    let make = (~pt=?, ~pb=?, ~pl=?, ~pr=?, ~mt=?, ~mb=?, ~ml=?, ~mr=?, _unit) => {
      // Padding
      let ptStyle = pt <$> (pt' => style([paddingTop(pt')])) |? "";
      let pbStyle = pb <$> (pb' => style([paddingBottom(pb')])) |? "";
      let plStyle = pl <$> (pl' => style([paddingLeft(pl')])) |? "";
      let prStyle = pr <$> (pr' => style([paddingRight(pr')])) |? "";

      // Margin
      let mtStyle = mt <$> (mt' => style([marginTop(mt')])) |? "";
      let mbStyle = mb <$> (mb' => style([marginBottom(mb')])) |? "";
      let mlStyle = ml <$> (ml' => style([marginLeft(ml')])) |? "";
      let mrStyle = mr <$> (mr' => style([marginRight(mr')])) |? "";

      merge([
        ptStyle,
        pbStyle,
        plStyle,
        prStyle,
        mtStyle,
        mbStyle,
        mlStyle,
        mrStyle,
      ]);
    };
  };
  /**
   * This preset based on this library "https://gist.github.com/DavidWells/18e73022e723037a50d6"
   * because this preset doesnt have binding, we just insert global html from global method emotion.
   */
  let preset = () => {
    global(
      "
      html, body, div, span, applet, object, iframe,
      h1, h2, h3, h4, h5, h6, p, blockquote, pre,
      a, abbr, acronym, address, big, cite, code,
      del, dfn, em, img, ins, kbd, q, s, samp,
      small, strike, strong, sub, sup, tt, var,
      b, u, i, center,
      dl, dt, dd, ol, ul, li,
      fieldset, form, label, legend,
      table, caption, tbody, tfoot, thead, tr, th, td,
      article, aside, canvas, details, embed,
      figure, figcaption, footer, header, hgroup,
      menu, nav, output, ruby, section, summary,
      time, mark, audio, video
    ",
      [
        margin(zero),
        border(zero, solid, black),
        fontSize(`percent(100.)),
        verticalAlign(`baseline),
        fontSize(inherit_),
      ],
    );

    global(
      "html",
      [
        width(`percent(100.)),
        height(`percent(100.)),
        margin(zero),
        overflow(`hidden),
        fontSize(`percent(100.)),
      ],
    );

    global(
      "body",
      [
        width(`percent(100.)),
        height(`percent(100.)),
        margin(zero),
        padding(zero),
        overflow(`hidden),
        backgroundColor(`hex("FAE8DD")),
        lineHeight(`abs(1.)),
        fontFamily("Rubik, sans-serif"),
        unsafe("cursor", Constants.Styles.Cursor.default),
      ],
    );

    global(
      "article, aside, details, figcaption, figure, footer, header, hgroup, menu, nav, section",
      [display(`block)],
    );

    global("ol, ul", [listStyleType(`none)]);

    global("blockquote, q", [unsafe("quotes", "none")]);

    global(
      "blockquote:before, blockquote:after, q:before, q:after",
      [unsafe("content", "''"), unsafe("content", "none")],
    );

    global("table", [borderCollapse(`collapse), borderSpacing(zero)]);

    global(
      "input[type=search]::-webkit-search-cancel-button,
       input[type=search]::-webkit-search-decoration,
       input[type=search]::-webkit-search-results-button,
       input[type=search]::-webkit-search-results-decoration",
      [
        unsafe("-webkit-appearance", "none"),
        unsafe("-moz-appearance", "none"),
      ],
    );

    global(
      "button",
      [hover([unsafe("cursor", Constants.Styles.Cursor.pointer)])],
    );
  };
};

let translationsToDict = (translations: array(ReactIntl.translation)) => {
  translations->Belt.Array.reduce(
    Js.Dict.empty(),
    (dict, entry) => {
      dict->Js.Dict.set(
        entry##id,
        switch (entry##message->Js.Nullable.toOption) {
        | None
        | Some("") => entry##defaultMessage
        | Some(message) => message
        },
      );
      dict;
    },
  );
};

module List = {
  let rec getElementAt = (~index: int, l: list('a)) =>
    switch (l) {
    | [] => None
    | [head, ...tail] =>
      Js.log(head);
      if (index <= 0) {
        Some(head);
      } else {
        getElementAt(~index=index - 1, tail);
      };
    };
};
