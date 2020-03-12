open BsStorybook.Story;

// Bind Module
module StorybookConst = Constants.Storybook;
module Action = BsStorybook.Action;


let str = React.string


// @TODO add system block to get description about that component
let jsModule = [%raw "module"];
storiesOf(StorybookConst.storiesOf(`Foundations(`Typography)) , jsModule)
->(
    add("Heading", () =>
      <>
        <Heading as_=`H1 value="Javascript user group"/>
        <Heading as_=`H2 value="Javascript user group"/>
        <Heading as_=`H3 value="Javascript user group"/>
        <Heading as_=`H4 value="Javascript user group"/>
        <Heading as_=`H5 value="Javascript user group"/>
        <Heading as_=`H6 value="Javascript user group"/>
      </>
    )
  )