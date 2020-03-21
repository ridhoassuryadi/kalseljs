open BsStorybook.Story;

// Bind Module
module StorybookConst = Constants.Storybook;
module Action = BsStorybook.Action;

//
let str = React.string;

let jsModule = [%raw "module"];
storiesOf(StorybookConst.storiesOf(`Components(`Atomics)), jsModule)
->(
    add("Visually Hidden", () =>
      <View>
        <Text value="inspect my next element" />
        <VisuallyHidden> {"Hi i am not visible" |> str} </VisuallyHidden>
      </View>
    )
  );
