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