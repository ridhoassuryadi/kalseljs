open BsStorybook.Story;

// Bind Module
module StorybookConst = Constants.Storybook;
module Action = BsStorybook.Action;


let str = React.string

let jsModule = [%raw "module"];
storiesOf(StorybookConst.storiesOf(`Components(`Atomics)) , jsModule)
->(
    add("Row", () =>
      <Row>{"Hi i am on row" |> str}</Row>
    )
  )