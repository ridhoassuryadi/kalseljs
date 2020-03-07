[@react.component]
let make = (~children)=>{
      <Theme.Provider value=Colors.default>
            children
      </Theme.Provider>
}

let default = make