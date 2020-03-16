open BsStorybook.Story;

// Bind Module
module StorybookConst = Constants.Storybook;
module Action = BsStorybook.Action;

// 
let str = React.string

let jsModule = [%raw "module"];
storiesOf(StorybookConst.storiesOf(`Components(`Atomics)) , jsModule)
|. (
    add("Touchable Opacity", () =>
      <TouchableOpacity onPress={Action.action("Yeay you clicked it !")}>{"Click me" |> str}</TouchableOpacity>
    )
  )