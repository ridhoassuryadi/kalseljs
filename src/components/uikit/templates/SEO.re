open Utils.Option.Infix;
module Helmet = BsReactHelmet

module Captions = {
    let description = "description"
    let keywords = "keywords"
    let keywordsDefaultValue = " content: reasonml, bucklescript, react"
    let ogTitle = "og:title"
    let ogDescription = "og:description"
    let ogType = "og:type"
    let ogTypeValue = "website"
    let twitterCard = "twitter:card"
    let twitterCardValue = "summary"
};

[@react.component]
let make = (~description, ~lang, ~title, ~keywords=?) => {
    let keywordsValue = keywords |? Captions.keywordsDefaultValue;

    <Helmet
        title
        htmlAttributes={lang}
        meta={Helmet.([|
        meta(~name=Captions.description, ~content=description, ()),
        meta(~name=Captions.keywords, ~content=keywordsValue, ()),
        meta(~property=Captions.ogTitle, ~content=title, ()),
        meta(~property=Captions.ogType, ~content=Captions.ogTypeValue, ()),
        meta(~property=Captions.ogDescription, ~content=description, ()),
        meta(~property=Captions.twitterCard, ~content=Captions.twitterCardValue, ())
        |])}
    
        />
}

let default = make