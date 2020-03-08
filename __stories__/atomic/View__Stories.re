open BsStorybook.Story;

// Bind Module
module StorybookConst = Constants.Storybook;
module Action = BsStorybook.Action;

// 
let str = React.string

let jsModule = [%raw "module"];
storiesOf(`Atomics |> StorybookConst.toString , jsModule)
->(
    add("View", () =>
      <View>{"Hi i am on view" |> str}</View>
    )
  )