/**
 * Instead of using pure dangerrousSetInnerHtml from react, whis this is not guard you from sanitize script
 * for example when we input "<img src=x onerror=alert(1)></img>" this will inject alert script to our sites
 * alternatively we use react-markdown to prevent XSS from our markdown
 */
[@react.component]
let make = (~source, ~forwardRef=?) => {
  <ReactMarkdown source ref=forwardRef sanitize=true />;
};
