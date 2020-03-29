open BsStorybook.Story;

// Bind Module
module StorybookConst = Constants.Storybook;
module Action = BsStorybook.Action;

let str = React.string;

let jsModule = [%raw "module"];
storiesOf(StorybookConst.storiesOf(`Components(`Atomics)), jsModule)
->(add("Html View", () => <HtmlView source="<p>Hi i'm in there</p>" />));
