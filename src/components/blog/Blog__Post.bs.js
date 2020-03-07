// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Css = require("bs-css/src/Css.js");
var React = require("react");
var Gatsby = require("gatsby");
var Theme$ReactGatsbyTemplate = require("../uikit/foundation/Theme.bs.js");
var Utils$ReactGatsbyTemplate = require("../../commons/Utils.bs.js");
var Colors$ReactGatsbyTemplate = require("../uikit/foundation/Colors.bs.js");

function str(prim) {
  return prim;
}

var article = Css.style(/* :: */[
      Css.marginBottom(Css.px(32)),
      /* [] */0
    ]);

var link = Css.style(/* :: */[
      Css.textDecoration(/* none */-922086728),
      /* :: */[
        Css.hover(/* :: */[
              Css.textDecoration(/* underline */131142924),
              /* :: */[
                Css.textDecorationColor(Css.red),
                /* [] */0
              ]
            ]),
        /* [] */0
      ]
    ]);

var h2 = Css.style(/* :: */[
      Css.color(Css.red),
      /* [] */0
    ]);

var p = Css.style(/* :: */[
      Css.color(Css.black),
      /* [] */0
    ]);

var date = Css.style(/* :: */[
      Css.color(Css.darkgray),
      /* [] */0
    ]);

var Styles = {
  article: article,
  link: link,
  h2: h2,
  p: p,
  date: date
};

function Blog__Post(Props) {
  var post = Props.post;
  var colors = React.useContext(Theme$ReactGatsbyTemplate.context);
  console.log("jalan");
  React.useEffect((function () {
          console.log(colors);
          return ;
        }));
  return React.createElement(Theme$ReactGatsbyTemplate.Provider.make, {
              value: Colors$ReactGatsbyTemplate.$$default,
              children: React.createElement("article", {
                    className: article
                  }, React.createElement(Gatsby.Link, {
                        to: "/blog/" + post.frontmatter.path,
                        className: link,
                        children: React.createElement("h2", {
                              className: h2
                            }, post.frontmatter.title)
                      }), React.createElement("p", {
                        className: p
                      }, post.excerpt), React.createElement("small", {
                        className: date
                      }, Utils$ReactGatsbyTemplate.formatDate(post.frontmatter.date)))
            });
}

var make = Blog__Post;

exports.str = str;
exports.Styles = Styles;
exports.make = make;
/* article Not a pure module */