let str = React.string;

module Styles = {
  open Css;
  let article = style([marginBottom(px(32))]);
  let link =
    style([
      textDecoration(`none),
      hover([textDecoration(`underline), textDecorationColor(red)]),
    ]);
  let h2 = style([color(red)]);
  let p = style([color(black)]);
  let date = style([color(darkgray)]);
};

[@react.component]
let make = (~post) => {
  let colors = React.useContext(Theme.context);
  Js.log("jalan");

  React.useEffect(() => {
      Js.log(colors);
    None
  });

  <Theme.Provider value=Colors.default>
  <article className=Styles.article>
    <Gatsby.Link
      _to={"/blog/" ++ post##frontmatter##path} className=Styles.link>
      <h2 className=Styles.h2> {post##frontmatter##title |> str} </h2>
    </Gatsby.Link>
    <p className=Styles.p> {post##excerpt} </p>
    <small className=Styles.date>
      {post##frontmatter##date |> Utils.formatDate |> str}
    </small>
  </article>
  </Theme.Provider>
};