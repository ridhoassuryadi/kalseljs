module  Styles = {
    open Css;

    let container = style([
        width(`percent(100.)),
        height(`percent(100.)),
        margin(zero),
        padding(zero),
        overflow(`hidden)
    ]);
};
[@react.component]
let make = (~children) => {
    Utils.Styles.preset();

    <View style=Styles.container>
        ...children
    </View>
}

let default = make;