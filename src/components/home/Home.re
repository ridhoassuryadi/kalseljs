open ReactIntl;
let str = React.string;


/* For a page of static text like this one, it would be easier to just use plain React
   components since we don't get to take advantage of Reason's type system */
[@react.component]
let make = () => {
  <div>
    <div className="message">
      <FormattedMessage id="page.hello" defaultMessage="Hello" />
    </div>
    <br/>
    <TouchableOpacity 
      accessibilityLabel="button"
      accessibilityRoleDescription="button home"
      onPress={_ => ()}>
      {"Klik Saya" |> str}
    </TouchableOpacity>
  </div>;
};

let default = make;