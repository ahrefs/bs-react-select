open BsReactSelect;

type item = {
  .
  "value": string,
  "label": string,
};

type action =
  | Change(item);

type state = {selectedItem: option(item)};

let component = ReasonReact.reducerComponent("App");

let make = (~options, _children) => {
  ...component,
  initialState: () => {selectedItem: None},
  reducer: (action, _state) =>
    switch (action) {
    | Change(item) => ReasonReact.Update({selectedItem: Some(item)})
    },
  render: self =>
    <Select
      options
      value=?(
        Js.Option.map(
          (. b) => Select.Option.Val(b),
          self.state.selectedItem,
        )
      )
      onChange=(newItem => self.send(Change(newItem)))
      arrowRenderer=((_) => <div> (ReasonReact.stringToElement("+")) </div>)
      filterOptions=(Func((~options, ~filter as _filter) => options))
      placeholder=(Str("Select something.."))
    />,
};