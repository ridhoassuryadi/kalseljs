module Storybook = {
    [@bs.deriving jsConverter]
    type t = [
        |`Foundations
        |`Atomics
        |`Molecules
        |`Templates
    ];

    // Smart Constructor
    let toString = type_ => type_ |> tToJs
}