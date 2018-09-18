open BsReactSelect;

type item = {
  .
  "value": string,
  "label": string,
};

type action =
  | Change(option(item));

type state = {selectedItem: option(item)};

let component = ReasonReact.reducerComponent("App");

let make = (~options, _children) => {
  ...component,
  initialState: () => {selectedItem: None},
  reducer: (action, _state) =>
    switch (action) {
    | Change(selectedItem) =>
      ReasonReact.Update({selectedItem: selectedItem})
    },
  render: self =>
    <Select
      options
      value=?{
        self.state.selectedItem
        |> Js.Option.map((. b) => Select.Option.Val(b))
      }
      onChange={selected => self.send(Change(selected))}
      arrowRenderer={_ => <div> {ReasonReact.string("+")} </div>}
      filterOptions={Func((~options, ~filter as _filter) => options)}
      placeholder={Str("Select something..")}
    />,
};
