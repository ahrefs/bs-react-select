open BsReactSelect;
open Belt;

type item = {
  .
  "value": string,
  "label": string,
};

let options = [|
  {"value": "one", "label": "One"},
  {"value": "two", "label": "Two"},
  {"value": "three", "label": "Three"},
  {"value": "four", "label": "Four"},
  {"value": "five", "label": "Five"},
  {"value": "six", "label": "Six"},
  {"value": "seven", "label": "Seven"},
  {"value": "eight", "label": "Eight"},
  {"value": "nine", "label": "Nine"},
  {"value": "ten", "label": "Ten"},
|];
  
  [@react.component]
  let make = () =>{
    let (selectedValue, setValue) = React.useState(() => None);
    
    <Select
      multi=false
      options
      value=?selectedValue->Option.map(item => Select.Option.encode(Val(item)))
      onChange={
        selected => {
          Js.log("onChange");
          setValue(_ => selected->Js.Nullable.toOption);
        }
      }
      arrowRenderer={_ => <div> {React.string("+")} </div>}
      filterOptions={Select.FilterOptions.encode(Func((~options, ~filter as _filter) => options))}
      placeholder={BsReactSelect__Core.StrOrNode.encode(Str("Select something.."))}
      style=ReactDOMRe.Style.make(~width="200px", ())
    />
  }