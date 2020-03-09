[@react.component]
let make = () => {
  <h1> {React.string("Not found")} </h1>;
};

React.setDisplayName(make, "404");

let default = make;