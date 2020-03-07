
type color = Css_AtomicTypes.Color.t;

module Spectrum = {
  type t = {
    darkest: color,
    darker: color,
    neutral: color,
    lighter: color,
    lightest: color,
  };

  /*
      TODO: add validation to remove what's not sensical for the colors to be there
      for example: #lkjhnbbvv it is not valid hex code, so it will return None
   */
  let make = (~darkest, ~darker, ~neutral, ~lighter, ~lightest) => {
    darkest: `hex(Js.String.substr(~from=1, darkest)),
    darker: `hex(Js.String.substr(~from=1, darker)),
    neutral: `hex(Js.String.substr(~from=1, neutral)),
    lighter: `hex(Js.String.substr(~from=1, lighter)),
    lightest: `hex(Js.String.substr(~from=1, lightest)),
  };
};


type t = {
  primary: Spectrum.t,
  secondary: Spectrum.t
};

let primary =
  Spectrum.make(
    ~darkest="#955B16",
    ~darker="#C67A1E",
    ~neutral="#F89825",
    ~lighter="#FCCC92",
    ~lightest="#FEEAD3",
  );

let secondary =
  Spectrum.make(
    ~darkest="#1C6D73",
    ~darker="#25919A",
    ~neutral="#2EB5C0",
    ~lighter="#97DAE0",
    ~lightest="#EAF8F9",
  );

let default = {
  primary,
  secondary
};
