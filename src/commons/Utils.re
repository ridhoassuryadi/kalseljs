// str = "2018-10-27T22:40:32.169Z"
// result = "Sunday, February 17, 2019"

let formatDate = (isoDateString: string) => {
  DateFns.internal_format(Js.Date.fromString(isoDateString), "dddd, MMMM D, YYYY");
};

module Option = {
  module Infix = {
    let (|?) = (option, defaultValue) =>
      switch (option) {
      | Some(value) => value
      | None => defaultValue
      };

    let (>>=) = Belt.Option.flatMap;

    let (<$>) = Belt.Option.map;
  };
};