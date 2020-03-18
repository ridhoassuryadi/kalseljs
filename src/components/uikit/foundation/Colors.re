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
  secondary: Spectrum.t,
  black: Spectrum.t,
  grey: Spectrum.t,
};

let primary =
  Spectrum.make(
    ~darkest="#AE332E",
    ~darker="#D05343",
    ~neutral="#F3795D",
    ~lighter="#FFAE90",
    ~lightest="#FFC4A6",
  );

let secondary =
  Spectrum.make(
    ~darkest="#B48173",
    ~darker="#D7B4A8",
    ~neutral="#FBEDE6",
    ~lighter="#FCF3EC",
    ~lightest="#FDF6F1",
  );

let white = "FFFF";

let black =
  Spectrum.make(
    ~darkest="#120D0E",
    ~darker="#161313",
    ~neutral="#1A1A1A",
    ~lighter="#313131",
    ~lightest="#484848",
  );

let grey =
  Spectrum.make(
    ~darkest="#4E2B34",
    ~darker="#746264",
    ~neutral="#878787",
    ~lighter="#EAE5E3",
    ~lightest="#FFFFFF",
  );

let default = {primary, secondary, black, grey};
