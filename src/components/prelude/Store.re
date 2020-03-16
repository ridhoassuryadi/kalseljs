
type action =
  | SetLocale(Locale.locale);

let initialState = Locale.Bn;

let reducer = (_, action) =>
  switch (action) {
  | SetLocale(locale) => locale
  };

[@react.component]
let make = (~children)=>{

      <Locale.Provider>
            <Theme.Provider value=Colors.default>
                  children
            </Theme.Provider>
      </Locale.Provider>
}

let default = make