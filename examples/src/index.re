[%bs.raw {|require('react-select/dist/react-select.css')|}];

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

ReactDOMRe.renderToElementWithId(
  <div>
    <h2> {ReasonReact.string("Select component")} </h2>
    <Example1 options />
    <h2> {ReasonReact.string("Multi-select component")} </h2>
    <Example2 options />
  </div>,
  "root",
);
