let context = React.createContext(Colors.default);

module Provider = {
  let make = context->React.Context.provider;

  [@bs.obj]
  external makeProps:
    (~value: Colors.t, ~children: React.element, ~key: string=?, unit) =>
    {
      .
      "value": Colors.t,
      "children": React.element,
    } =
    "";
};