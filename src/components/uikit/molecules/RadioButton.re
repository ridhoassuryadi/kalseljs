open Utils.Option.Infix;

type variant = [ | `Idle | `Chosen];
type value = string;

module Styles = {
  open Css;

  let createRadioBoxStyle = (~variant, ~colors: Colors.t) => {
    let base =
      style([
        position(`relative),
        width(`rem(1.5)),
        height(`rem(1.5)),
        borderRadius(`percent(50.)),
        borderWidth(`rem(0.15)),
        marginRight(`rem(0.56)),
      ]);

    let styleBasedOnVariant =
      switch (variant) {
      | `Idle => style([borderColor(colors.black.neutral)])
      | `Chosen => style([borderColor(colors.primary.neutral)])
      };

    Css.merge([base, styleBasedOnVariant]);
  };

  let createInnerCircleStyle = (~variant, ~colors: Colors.t) => {
    let base =
      style([
        position(`absolute),
        top(`percent(50.)),
        left(`percent(50.)),
        width(`rem(0.8)),
        height(`rem(0.8)),
        borderRadius(`percent(50.)),
        transforms([translate(`percent(-50.), `percent(-50.))]),
      ]);

    let styleBasedOnVariant =
      switch (variant) {
      | `Idle => style([backgroundColor(`transparent)])
      | `Chosen => style([backgroundColor(colors.primary.neutral)])
      };

    Css.merge([base, styleBasedOnVariant]);
  };

  let labelWrapper = style([marginLeft(`rem(0.8))]);

  let row = style([alignItems(`center)]);

  let col = style([flexDirection(`column), flex(`num(1.))]);
  let container =
    style([
      padding2(~v=`rem(0.5), ~h=`zero),
      unsafe("cursor", Constants.Styles.Cursor.pointer),
    ]);
};

module Radio_Group_Context = {
  type setChecked = value => unit;
  type otherValues = array(string);
  type contextValue = (value, otherValues, setChecked);

  let initValue: contextValue = ("", [||], _ => ignore());

  // Create the context that will hold the valuer
  let context = React.createContext(initValue);

  // Create hooks for ease of access to the context value
  let useRadioGroup = () => React.useContext(context);
};

// Create Context
let radioGroupContext = React.Context.provider(Radio_Group_Context.context);

module RadioGroupProvider = {
  let make = radioGroupContext;

  let makeProps = (~value, ~children, ()) => {
    "value": value,
    "children": children,
  };
};

module Group = {
  [@react.component]
  let make = (~value, ~onChange, ~children) => {
    let setChecked = React.useCallback0(v => onChange(v));

    let otherRadioValues =
      children
      |> ReactBind.Children.mapJsToString(_, child => child##props##value);

    let ctx =
      React.useMemo2(
        () => (value, otherRadioValues, setChecked),
        (value, otherRadioValues),
      );

    <RadioGroupProvider value=ctx>
      <div role="radiogroup"> children </div>
    </RadioGroupProvider>;
  };
};

module Item = {
  [@react.component]
  let make = (~value, ~onBlur=?, ~onFocus=?, ~children) => {
    // Context
    let (_, setFocus) = React.useState(() => false);
    let (radioGroupValue, otherRadioValues, setChecked) =
      Radio_Group_Context.useRadioGroup();

    // Private Value
    let index = Js.Array.findIndex(item => item == value, otherRadioValues);
    let count = otherRadioValues->Array.length - 1;
    let divRef = React.useRef(Js.Nullable.null);

    // if this item selected this will radio button focus
    React.useEffect2(
      () => {
        if (value == radioGroupValue) {
          let divNode = React.Ref.current(divRef)->Js.Nullable.toOption;
          divNode <$> (div => div->ReactDOMRe.domElementToObj##focus()) |? ();
        };
        None;
      },
      (value, radioGroupValue),
    );

    let handleClick =
      React.useCallback1(() => setChecked(value), [|value|]);

    // Event handler
    let handleBlur =
      React.useCallback0(() => {
        onBlur <$> (cb => cb()) |? ();
        setFocus(_ => false);
      });

    let handleFocus =
      React.useCallback0(() => {
        onFocus <$> (cb => cb()) |? ();
        setFocus(_ => true);
      });

    let handleKeyDown =
      React.useCallback3(
        event => {
          let setNext = () =>
            if (index == count) {
              setChecked(otherRadioValues[0]);
            } else {
              setChecked(otherRadioValues[index + 1]);
            };

          let setPrevious = () =>
            if (index === 0) {
              setChecked(otherRadioValues[count]);
            } else {
              setChecked(otherRadioValues[index - 1]);
            };
          let keyboardCode = event->ReactEvent.Keyboard.keyCode;
          switch (keyboardCode) {
          // currently reason not support pattern matching with variable

          // 37 for left arrow and 38 for up arrow
          | 37
          | 38 => setPrevious()
          // 39 for right arrow and 40 for bottom arrow
          | 39
          | 40 => setNext()
          | _ => ()
          };
        },
        (children, count, index),
      );

    let colors = React.useContext(Theme.context);
    let variant = value == radioGroupValue ? `Chosen : `Idle;
    <div
      role="radiobutton"
      tabIndex={radioGroupValue == value ? 0 : (-1)}
      onClick={_ => handleClick()}
      onKeyDown={e => handleKeyDown(e)}
      onFocus={_ => handleFocus()}
      onBlur={_ => handleBlur()}
      ref={ReactDOMRe.Ref.domRef(divRef)}
      className=Styles.container>
      <Row style=Styles.row>
        <View style={Styles.createRadioBoxStyle(~variant, ~colors)}>
          <View style={Styles.createInnerCircleStyle(~variant, ~colors)} />
        </View>
        children
      </Row>
    </div>;
  };
};
