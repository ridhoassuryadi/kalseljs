open BsStorybook.Story;
open Utils.Styles;
// Bind Module
module StorybookConst = Constants.Storybook;
module Action = BsStorybook.Action;

let str = React.string;

// @TODO add system block to get description about that component
let jsModule = [%raw "module"];
storiesOf("Foundations", jsModule)
->(
    add("Card", () =>
      <View
        spacing={Spacing.make(
          ~pt=`rem(2.),
          ~pl=`rem(2.),
          ~pb=`rem(2.),
          ~pr=`rem(2.),
          (),
        )}>
        <Card variant=`Ring> <Text value="Ring Style" /> </Card>
        <br />
        <Card variant={`Shadow(`small)}> <Text value="Small Shadow" /> </Card>
        <br />
        <Card variant={`Shadow(`medium)}>
          <Text value="Medium Shadow" />
        </Card>
        <br />
        <Card variant={`Shadow(`large)}> <Text value="Large Shadow" /> </Card>
        <br />
        <Card variant={`Shadow(`superLarge)}>
          <Text value="Super large shadow" />
        </Card>
      </View>
    )
  );
