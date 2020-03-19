open BsStorybook.Story;

// Bind Module
module StorybookConst = Constants.Storybook;
module Action = BsStorybook.Action;

let str = React.string;

let jsModule = [%raw "module"];
storiesOf(StorybookConst.storiesOf(`Components(`Molecules)), jsModule)
->(
    add("Text Input", () =>
      <>
        <TextInput
          value="Belajar tuk mencintai cerminan diri, tanpa tuk takut dengan marathon duniawi"
          onChange={_ => ()}
          lineType=`Multiple
        />
        <TextInput value="ridhoassuryadi@aldnoah.org" onChange={_ => ()} />
        <TextInput
          value="Ini pasti error"
          status={`Error("tuh kan error")}
          onChange={_ => ()}
          prefix={`Icon(<Icons.Mail />)}
        />
      </>
    )
  );
