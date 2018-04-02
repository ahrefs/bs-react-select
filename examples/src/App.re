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
  render: self => {
    let value =
      switch (self.state.selectedItem) {
      | Some(item) => item##value
      | None => ""
      };
    <div>
      (ReasonReact.stringToElement("APP"))
      <RS
        name="form-field-name"
        value
        onChange=(newItem => self.send(Change(newItem)))
        arrowRenderer=(
          (_) => <div> (ReasonReact.stringToElement("+")) </div>
        )
        placeholder=(Str("Select something.."))
        resetValue="three"
        options=[|
          {"value": "one", "label": "One"},
          {"value": "two", "label": "Two"},
          {"value": "three", "label": "Three"},
          {"value": "four", "label": "Four"},
        |]
      />
    </div>;
  },
};