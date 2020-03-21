open BsStorybook.Story;

// Bind Module
module StorybookConst = Constants.Storybook;
module Action = BsStorybook.Action;

let str = React.string;

let jsModule = [%raw "module"];
storiesOf(StorybookConst.storiesOf(`Components(`Atomics)), jsModule)
->(
    add("Column", () =>
      <Col> <Text value="Aloha " /> <Text value="KalselJS" /> </Col>
    )
  );
