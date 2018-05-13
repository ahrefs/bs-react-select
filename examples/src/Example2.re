open BSReactSelect;

type item = {
  .
  "value": string,
  "label": string,
};

type action =
  | Change(array(item));

type state = {selectedItem: array(item)};

let component = ReasonReact.reducerComponent("App");

let make = (~options, _children) => {
  ...component,
  initialState: () => {selectedItem: [|{"value": "one", "label": "One"}|]},
  reducer: (action, _state) =>
    switch (action) {
    | Change(item) => ReasonReact.Update({selectedItem: item})
    },
  render: self =>
    <SelectMulti
      options
      value=(SelectMulti.Option.Arr(self.state.selectedItem))
      onChange=(selected => self.send(Change(selected)))
    />,
};