open BsStorybook.Story;

// Bind Module
module StorybookConst = Constants.Storybook;
module Action = BsStorybook.Action;
module Spacing = Utils.Styles.Spacing;

let str = React.string;

let jsModule = [%raw "module"];
storiesOf(StorybookConst.storiesOf(`Components(`Atomics)), jsModule)
->(
    add("Divider", () =>
      <View
        spacing={Spacing.make(
          ~pt=`rem(2.),
          ~pb=`rem(2.),
          ~pl=`rem(1.),
          ~pr=`rem(1.),
          (),
        )}>
        <Divider />
      </View>
    )
  );
