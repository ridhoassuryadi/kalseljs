type markdown = string;

[@bs.module] [@react.component]
external make:
  (
    ~source: markdown,
    ~escapeHtml: bool=?,
    ~ref: 'someRef=?,
    ~sanitize: bool,
    unit
  ) =>
  React.element =
  "react-markdown/with-html";
