/*
 * because this module not published yet,
 * we must bind manually into our source until this binding release
 * based on this implementation https://github.com/reasonml/reason-react/blob/master/src/React.re#L33
 */
type element = React.element;

type propsJs = {. "value": string};
type elementJs = {. "props": propsJs};

module Children = {
  [@bs.module "react"] [@bs.scope "Children"] [@bs.val]
  external map: (element, element => element) => element = "map";
  [@bs.module "react"] [@bs.scope "Children"] [@bs.val]
  external mapJsToString: (element, elementJs => string) => array(string) =
    "map";
  [@bs.module "react"] [@bs.scope "Children"] [@bs.val]
  external forEach: (element, element => unit) => unit = "forEach";
  [@bs.module "react"] [@bs.scope "Children"] [@bs.val]
  external count: element => int = "count";
  [@bs.module "react"] [@bs.scope "Children"] [@bs.val]
  external only: element => element = "only";
  [@bs.module "react"] [@bs.scope "Children"] [@bs.val]
  external toArray: element => array(element) = "toArray";
};
