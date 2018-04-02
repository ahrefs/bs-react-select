type item = {
  .
  "value": string,
  "label": string,
};

type action =
  | Change(item);

type state = {selectedItem: option(item)};

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {selectedItem: None},
  reducer: (action, _state) =>
    switch (action) {
    | Change(item) => ReasonReact.Update({selectedItem: Some(item)})
    },
  render: self =>
    <div>
      (ReasonReact.stringToElement("APP"))
      <RS
        value=?(
          Js.Option.map(
            (. b) => RS.Option.(Val(b)),
            self.state.selectedItem,
          )
        )
        name="form-field-name"
        onChange=(
          newItem => {
            Js.log(newItem);
            self.send(Change(newItem));
          }
        )
        arrowRenderer=(
          (_) => <div> (ReasonReact.stringToElement("+")) </div>
        )
        filterOptions=(Func((~options, ~filter as _filter) => options))
        placeholder=(Str("Select something.."))
        options=[|
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
        |]
      />
    </div>,
};