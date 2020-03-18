open BsStorybook.Story;

// Bind Module
module StorybookConst = Constants.Storybook;
module Action = BsStorybook.Action;

let str = React.string;

// @TODO add system block to get description about that component
let jsModule = [%raw "module"];
storiesOf(StorybookConst.storiesOf(`Foundations(`Typography)), jsModule)
->(
    add("Text", () =>
      <>
        <Text size=`Small> {"Hello KalselJS" |> str} </Text>
        <Text variant=`Secondary> {"Hello KalselJS" |> str} </Text>
        <Text size=`Large> {"Hello KalselJS" |> str} </Text>
      </>
    )
  );
