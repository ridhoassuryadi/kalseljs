
[@bs.module]
external en: array(ReactIntl.translation) = "translations/en.json";
[@bs.module]
external id: array(ReactIntl.translation) = "translations/id.json";
[@bs.module]
external bn: array(ReactIntl.translation) = "translations/bn.json";

type locale =
    | En
    | Id
    | Bn;

  let all = [|En, Id, Bn|];

  let toString =
    fun
    | En => "en"
    | Id => "id"
    | Bn => "bn";

  let translations =
    fun
    | En => en
    | Id => id
    | Bn => bn;


type action =
  | SetLocale(locale);


let reducer = (_, action) =>
  switch (action) {
  | SetLocale(locale) => locale
  };

module Context = {
  type dispatch = action => unit;
  type contextValue = (locale, dispatch);

  let initValue: contextValue = (Id, _ => ignore());

  // Create the context that will hold the valuer
  let context = React.createContext(initValue);

  // Create hooks for ease of access to the context value
  let useLanguange = () => React.useContext(context);
}


module Internal_Provider = {
  let make = React.Context.provider(Context.context);

  let makeProps = (~value, ~children, ()) => {
    "value": value,
    "children": children,
  };
};


module Provider = {
  [@react.component]
  let make = (~children) => {
    let initialState = Bn;
    let (locale, dispatch) = reducer->React.useReducer(initialState);

  <Internal_Provider value=(locale,dispatch)>
      <ReactIntl.IntlProvider
        locale={locale->toString}
        messages={locale->translations->Utils.translationsToDict}>
        ...children
      </ReactIntl.IntlProvider>
  </Internal_Provider>
  };
}





