open BsStorybook.Story;

// Bind Module
module StorybookConst = Constants.Storybook;
module Action = BsStorybook.Action;

let str = React.string;

let jsModule = [%raw "module"];
storiesOf(StorybookConst.storiesOf(`Components(`Molecules)), jsModule)
->(
    add("RadioButton", () =>
      <RadioButton.Group
        value="ayam" onChange={Action.action("Yeay you clicked it !")}>
        <RadioButton.Item value="ayam">
          "ayam"->React.string
        </RadioButton.Item>
        <RadioButton.Item value="nasi goreng">
          "nasi goreng"->React.string
        </RadioButton.Item>
        <RadioButton.Item value="capcay">
          "capcay"->React.string
        </RadioButton.Item>
        <RadioButton.Item value="mie ayam">
          "mie ayam"->React.string
        </RadioButton.Item>
      </RadioButton.Group>
    )
  );
