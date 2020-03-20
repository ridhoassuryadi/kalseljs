/**
 * Provides text for screen readers that is visually hidden. It is the logical opposite of the aria-hidden attribute.
In the following example, screen readers will announce "Save" and will ignore the icon; the browser displays the icon and ignores the text.
 */

[@react.component]
let make = (~children=?, ~tabIndex=0, ~forwardRef=?) => {
  let style =
    Css.(
      style([
        borderWidth(`zero),
        unsafe("clip", "rect(0 0 0 0)"),
        height(`px(1)),
        margin(`px(-1)),
        overflow(`hidden),
        padding(`zero),
        position(`absolute),
        width(`px(1)),
        whiteSpace(`nowrap),
        wordWrap(`normal),
      ])
    );
  let props =
    ReactDOMRe.objToDOMProps({
      "className": style,
      "tabIndex": tabIndex,
      "ref": forwardRef,
    });

  let child =
    switch (children) {
    | Some(child) => child
    | None => React.null
    };

  ReactDOMRe.createElement("span", ~props, [|child|]);
};
