open ReactIntl;
let str = React.string;

/* For a page of static text like this one, it would be easier to just use plain React
   components since we don't get to take advantage of Reason's type system */
[@react.component]
let make = () => {
  let (_, actionIntl) = Locale.Context.useLanguange();
  <div>
    <div className="message">
      <FormattedMessage id="page.hello" defaultMessage="Hello" />
    </div>
    <br/>
    <button onClick={_ => actionIntl(SetLocale(En))}>{"Change to English" |> str} </button>
   <button onClick={_ => actionIntl(SetLocale(Id))}>{"Ganti ke indonesia" |> str} </button>
    <button onClick={_ => actionIntl(SetLocale(Bn))}>{"Ganti ke Banjar" |> str} </button>
  </div>;
};

let default = make;