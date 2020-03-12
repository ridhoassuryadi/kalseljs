open BsStorybook.Story;

// Bind Module
module StorybookConst = Constants.Storybook;
module Action = BsStorybook.Action;


let str = React.string

// @TODO add system block to get description about that component
let jsModule = [%raw "module"];
storiesOf(StorybookConst.storiesOf(`Foundations(`Typography))  , jsModule)
->(
    add("Text" , () =>
      <>
        <Text>{"Normal Text" |> str}</Text>
        <Text size=`Large>{"Large Text" |> str}</Text>
        <Text variant=`Secondary>{"Secondary Text Color" |> str}</Text>
      </>
    )
  )