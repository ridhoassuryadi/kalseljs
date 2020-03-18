open BsStorybook.Story;

// Bind Module
module StorybookConst = Constants.Storybook;
module Action = BsStorybook.Action;

let str = React.string;

// @TODO add system block to get description about that component
let jsModule = [%raw "module"];
storiesOf(StorybookConst.storiesOf(`Components(`Molecules)), jsModule)
->(
    add("Checkbox", () =>
      <>
        <br />
        <Checkbox
          isChecked=true
          label="Ini checkbox true"
          onPress={Action.action("Yeay you clicked it !")}
        />
        <br />
        <Checkbox
          isChecked=false
          label="Ini checkbox false"
          onPress={Action.action("Yeay you clicked it !")}
        />
      </>
    )
  );
