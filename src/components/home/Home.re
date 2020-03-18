open ReactIntl;
let str = React.string;

/* For a page of static text like this one, it would be easier to just use plain React
   components since we don't get to take advantage of Reason's type system */
[@react.component]
let make = () => {
  let (selectedValue, setSelectedValue) = React.useState(() => "ayam");
  <View>
    <Text value={"Selected value: " ++ selectedValue} />
    <RadioButton.Group
      value=selectedValue onChange={v => setSelectedValue(_ => v)}>
      <RadioButton.Item value="ayam"> "ayam"->React.string </RadioButton.Item>
      <RadioButton.Item value="nasi goreng">
        "nasi goreng"->React.string
      </RadioButton.Item>
      <RadioButton.Item value="capcay">
        "capcay"->React.string
      </RadioButton.Item>
      <RadioButton.Item value="mie ayam">
        "mie ayam"->React.string
      </RadioButton.Item>
    </RadioButton.Group>
  </View>;
};

let default = make;
