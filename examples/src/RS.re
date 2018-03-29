let fromOpt = Js.Nullable.fromOption;

let booleanFromOptBool = (var: option(bool)) =>
  Js.Option.map((. b) => Js.Boolean.to_js_boolean(b), var);

type matchPos =
  | Any
  | Start;

let matchPosOptToStringOpt = v =>
  switch (v) {
  | Some(Any) => Some("any")
  | Some(Start) => Some("start")
  | None => None
  };

type matchProp =
  | Any
  | Label
  | Value;

let matchPropOptToStringOpt = v =>
  switch (v) {
  | Some(Any) => Some("any")
  | Some(Label) => Some("label")
  | Some(Value) => Some("value")
  | None => None
  };

type arrowRendererProps = {
  .
  "onMouseDown": unit => unit,
  "isOpen": Js.boolean,
};

type menuRendererProps('a) = {
  .
  "focusedOption": 'a,
  "focusOption": 'a => unit,
  "options": array('a),
  "selectValue": 'a => unit,
  "valueArray": array('a),
};

module StringOrNode = {
  type t =
    | Node(ReasonReact.reactElement)
    | String(string);
  external fromNode : ReasonReact.reactElement => t = "%identity";
  external fromString : string => t = "%identity";
  let encode = (v: t) =>
    switch (v) {
    | Node(a) => fromNode(a)
    | String(a) => fromString(a)
    };
  let encodeFromOpt = opt =>
    switch (opt) {
    | Some(opt) => Js.Nullable.return(encode(opt))
    | None => Js.Nullable.null
    };
};

module StringOrNumber = {
  type t =
    | Number(int)
    | String(string);
  external fromNumber : int => t = "%identity";
  external fromString : string => t = "%identity";
  let encode = (v: t) =>
    switch (v) {
    | Number(a) => fromNumber(a)
    | String(a) => fromString(a)
    };
  let encodeFromOpt = opt =>
    switch (opt) {
    | Some(opt) => Js.Nullable.return(encode(opt))
    | None => Js.Nullable.null
    };
};

[@bs.module "react-select"]
external select : ReasonReact.reactClass = "default";

let make =
    /* HTML ID(s) of element(s) that should be used to describe this input (for assistive tech) */
    (
      ~ariaDescribedby: option(string)=?,
      /* Aria label (for assistive tech) */
      ~ariaLabel: option(string)=?,
      /* HTML ID of an element that should be used as the label (for assistive tech) */
      ~ariaLabelledby: option(string)=?,
      /* Renders a custom drop-down arrow. Won't render when set to null */
      ~arrowRenderer: option(arrowRendererProps => ReasonReact.reactElement)=?,
      /* Blurs the input element after a selection has been made. Handy for lowering the keyboard on mobile devices */
      ~autoBlur: option(bool)=?,
      /* deprecated; use the autoFocus prop instead */
      ~autofocus: option(bool)=?,
      /* autofocus the component on mount */
      ~autoFocus: option(bool)=?,
      /* whether to auto-load the default async options set */
      ~autoload: option(bool)=?,
      /* If enabled, the input will expand as the length of its value increases */
      ~autosize: option(bool)=?,
      /* whether pressing backspace removes the last item when there is no input value */
      ~backspaceRemoves: option(bool)=?,
      /* prompt shown in input when at least one option in a multiselect is shown, set to '' to clear */
      ~backspaceToRemoveMessage: option(string)=?,
      /* className for the outer element */
      ~className: option(string)=?,
      /* should it be possible to reset value */
      ~clearable: option(bool)=?,
      /* title for the "clear" control when multi is true */
      ~clearAllText: option(string)=?,
      /* Renders a custom clear to be shown in the right-hand side of the select when clearable true: clearRenderer() */
      ~clearRenderer: option(unit => ReasonReact.reactElement)=?,
      /* title for the "clear" control */
      ~clearValueText: option(string)=?,
      /* whether to close the menu when a value is selected */
      ~closeOnSelect: option(bool)=?,
      /* whether pressing delete key removes the last item when there is no input value */
      ~deleteRemoves: option(bool)=?,
      /* delimiter to use to join multiple values */
      ~delimiter: option(string)=?,
      /* whether the Select is disabled or not */
      ~disabled: option(bool)=?,
      /* whether escape clears the value when the menu is closed */
      ~escapeClearsValue: option(bool)=?,
      /* method to filter a single option (option, filterString) => boolean */
      ~filterOption: option(('a, string) => Js.boolean)=?,
      /* boolean to enable default filtering or function to filter the options array */
      ~filterOptions=?,
      /* html id to set on the input element for accessibility or tests */
      ~id: option(string)=?,
      /* whether to strip accents when filtering */
      ~ignoreAccents: option(bool)=?,
      /* whether to perform case-insensitive filtering */
      ~ignoreCase: option(bool)=?,
      /* custom attributes for the Input (in the Select-control) e.g: {'data-foo': 'bar'} */
      ~inputProps: option(Js.t({..}))=?,
      /* renders a custom input component */
      ~inputRenderer: option(Js.t({..}) => ReasonReact.reactElement)=?,
      /* instance ID used internally to set html ids on elements for accessibility, specify for universal rendering */
      ~instanceId: option(string)=?,
      /* whether the Select is loading externally or not (such as options being loaded) */
      ~isLoading: option(bool)=?,
      /* join multiple values into a single hidden input using the delimiter */
      ~joinValues: option(bool)=?,
      /* the option property to use for the label */
      ~labelKey: option(string)=?,
      /* (any, start) match the start or entire string when filtering */
      ~matchPos: option(matchPos)=?,
      /* (any, label, value) which option property to filter on */
      ~matchProp: option(matchProp)=?,
      /* buffer of px between the base of the dropdown and the viewport to shift if menu doesnt fit in viewport */
      ~menuBuffer: option(int)=?,
      /* optional style to apply to the menu container */
      ~menuContainerStyle: option(Js.t({..}))=?,
      /* Renders a custom menu with options; accepts the following named parameters */
      ~menuRenderer:
         option(menuRendererProps('a) => ReasonReact.reactElement)=?,
      /* optional style to apply to the menu */
      ~menuStyle: option(Js.t({..}))=?,
      /* multi-value input */
      ~multi: option(bool)=?,
      /* field name, for hidden <input /> tag */
      ~name: option(string)=?,
      /* placeholder displayed when there are no matching search results or a falsy value to hide it */
      ~noResultsText: option(StringOrNode.t)=?,
      /* onBlur handler: function(event) {} */
      ~onBlur: option(Js.t({..}) => unit)=?,
      /* Whether to clear input on blur or not. If set to false, it only works if onCloseResetsInput is also false */
      ~onBlurResetsInput: option(bool)=?,
      /* onChange handler: function(newOption) {} */
      ~onChange: option('a => unit)=?,
      /* handler for when the menu closes: function () {} */
      ~onClose: option(unit => unit)=?,
      /* whether to clear input when closing the menu through the arrow */
      ~onCloseResetsInput: option(bool)=?,
      /* onFocus handler: function(event) {} */
      ~onFocus: option(unit => unit)=?,
      /* onInputChange handler/interceptor: function(inputValue: string): string */
      ~onInputChange: option(string => string)=?,
      /* input keyDown handler */
      ~onInputKeyDown: option(unit => unit)=?,
      /* called when the menu is scrolled to the bottom */
      ~onMenuScrollToBottom: option(unit => unit)=?,
      /* handler for when the menu opens: function () {} */
      ~onOpen: option(unit => unit)=?,
      /* whether the input value should be reset when options are selected. */
      ~onSelectResetsInput: option(bool)=?,
      /* onClick handler for value labels: function (value, event) {} */
      ~onValueClick: option(('a, Js.t({..})) => unit)=?,
      /* open the options menu when the control is clicked (requires searchable = true) */
      ~openOnClick: option(bool)=?,
      /* open the options menu when the control gets focus */
      ~openOnFocus: option(bool)=?,
      /* additional class(es) to apply to the elements */
      ~optionClassName: option(string)=?,
      /* option component to render in dropdown */
      ~optionComponent: option(ReasonReact.reactClass)=?,
      /* custom function to render the options in the menu */
      ~optionRenderer: option('a => ReasonReact.reactElement)=?,
      /* array of options */
      ~options: option(array('a))=?,
      /* whether the selected option is removed from the dropdown on multi selects */
      ~removeSelected: option(bool)=?,
      /* number of options to jump when using page up/down keys */
      ~pageSize: option(int)=?,
      /* field placeholder, displayed when there's no value */
      ~placeholder: option(StringOrNode.t)=?,
      /* applies HTML5 required attribute when needed */
      ~required: option(bool)=?,
      /* value to set when the control is cleared */
      ~resetValue=?,
      /* use react-select in right-to-left direction */
      ~rtl: option(bool)=?,
      /* whether the viewport will shift to display the entire menu when engaged */
      ~scrollMenuIntoView: option(bool)=?,
      /* whether to enable searching feature or not */
      ~searchable: option(bool)=?,
      /* label to prompt for search input */
      ~searchPromptText: option(StringOrNode.t)=?,
      /* pass the value to onChange as a string */
      ~simpleValue: option(bool)=?,
      /* optional styles to apply to the control */
      ~style: option(Js.t({..}))=?,
      /* tabIndex of the control */
      ~tabIndex: option(StringOrNumber.t)=?,
      /* whether to select the currently focused value when the [tab] key is pressed */
      ~tabSelectsValue: option(bool)=?,
      /* whether to trim whitespace from the filter value */
      ~trimFilter: option(bool)=?,
      /* initial field value */
      ~value=?,
      /* function which returns a custom way to render/manage the value selected <CustomValue /> */
      ~valueComponent: option(ReasonReact.reactClass)=?,
      /* the option property to use for the value */
      ~valueKey: option(string)=?,
      /* function which returns a custom way to render the value selected function (option) {} */
      ~valueRenderer: option('a => ReasonReact.reactElement)=?,
      /* optional styles to apply to the component wrapper */
      ~wrapperStyle: option(Js.t({..}))=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=select,
    ~props={
      "aria-describedby": ariaDescribedby |> fromOpt,
      "aria-label": ariaLabel |> fromOpt,
      "aria-labelledby": ariaLabelledby |> fromOpt,
      "arrowRenderer": arrowRenderer |> fromOpt,
      "autoBlur": autoBlur |> booleanFromOptBool |> fromOpt,
      "autofocus": autofocus |> booleanFromOptBool |> fromOpt,
      "autoFocus": autoFocus |> booleanFromOptBool |> fromOpt,
      "autoload": autoload |> booleanFromOptBool |> fromOpt,
      "autosize": autosize |> booleanFromOptBool |> fromOpt,
      "backspaceRemoves": backspaceRemoves |> booleanFromOptBool |> fromOpt,
      "backspaceToRemoveMessage": backspaceToRemoveMessage |> fromOpt,
      "className": className |> fromOpt,
      "clearable": clearable |> booleanFromOptBool |> fromOpt,
      "clearAllText": clearAllText |> fromOpt,
      "clearRenderer": clearRenderer |> fromOpt,
      "clearValueText": clearValueText |> fromOpt,
      "closeOnSelect": closeOnSelect |> booleanFromOptBool |> fromOpt,
      "deleteRemoves": deleteRemoves |> booleanFromOptBool |> fromOpt,
      "delimiter": delimiter |> fromOpt,
      "disabled": disabled |> booleanFromOptBool |> fromOpt,
      "escapeClearsValue": escapeClearsValue |> booleanFromOptBool |> fromOpt,
      "filterOption": filterOption |> fromOpt,
      "filterOptions": filterOptions |> fromOpt,
      "id": id |> fromOpt,
      "ignoreAccents": ignoreAccents |> booleanFromOptBool |> fromOpt,
      "ignoreCase": ignoreCase |> booleanFromOptBool |> fromOpt,
      "inputProps": inputProps |> fromOpt,
      "inputRenderer": inputRenderer |> fromOpt,
      "instanceId": instanceId |> fromOpt,
      "isLoading": isLoading |> booleanFromOptBool |> fromOpt,
      "joinValues": joinValues |> booleanFromOptBool |> fromOpt,
      "labelKey": labelKey |> fromOpt,
      "matchPos": matchPos |> matchPosOptToStringOpt |> fromOpt,
      "matchProp": matchProp |> matchPropOptToStringOpt |> fromOpt,
      "menuBuffer": menuBuffer |> fromOpt,
      "menuContainerStyle": menuContainerStyle |> fromOpt,
      "menuRenderer": menuRenderer |> fromOpt,
      "menuStyle": menuStyle |> fromOpt,
      "multi": multi |> booleanFromOptBool |> fromOpt,
      "name": name |> fromOpt,
      "noResultsText": noResultsText |> StringOrNode.encodeFromOpt,
      "onBlur": onBlur |> fromOpt,
      "onBlurResetsInput": onBlurResetsInput |> booleanFromOptBool |> fromOpt,
      "onChange": onChange |> fromOpt,
      "onClose": onClose |> fromOpt,
      "onCloseResetsInput":
        onCloseResetsInput |> booleanFromOptBool |> fromOpt,
      "onFocus": onFocus |> fromOpt,
      "onInputChange": onInputChange |> fromOpt,
      "onInputKeyDown": onInputKeyDown |> fromOpt,
      "onMenuScrollToBottom": onMenuScrollToBottom |> fromOpt,
      "onOpen": onOpen |> fromOpt,
      "onSelectResetsInput":
        onSelectResetsInput |> booleanFromOptBool |> fromOpt,
      "onValueClick": onValueClick |> fromOpt,
      "openOnClick": openOnClick |> booleanFromOptBool |> fromOpt,
      "openOnFocus": openOnFocus |> booleanFromOptBool |> fromOpt,
      "optionClassName": optionClassName |> fromOpt,
      "optionComponent": optionComponent |> fromOpt,
      "optionRenderer": optionRenderer |> fromOpt,
      "options": options |> fromOpt,
      "removeSelected": removeSelected |> booleanFromOptBool |> fromOpt,
      "pageSize": pageSize |> fromOpt,
      "placeholder": placeholder |> StringOrNode.encodeFromOpt,
      "required": required |> booleanFromOptBool |> fromOpt,
      "resetValue": resetValue |> fromOpt,
      "rtl": rtl |> booleanFromOptBool |> fromOpt,
      "scrollMenuIntoView":
        scrollMenuIntoView |> booleanFromOptBool |> fromOpt,
      "searchable": searchable |> booleanFromOptBool |> fromOpt,
      "searchPromptText": searchPromptText |> StringOrNode.encodeFromOpt,
      "simpleValue": simpleValue |> booleanFromOptBool |> fromOpt,
      "style": style |> fromOpt,
      "tabIndex": tabIndex |> StringOrNumber.encodeFromOpt,
      "tabSelectsValue": tabSelectsValue |> booleanFromOptBool |> fromOpt,
      "trimFilter": trimFilter |> booleanFromOptBool |> fromOpt,
      "value": value |> fromOpt,
      "valueComponent": valueComponent |> fromOpt,
      "valueKey": valueKey |> fromOpt,
      "valueRenderer": valueRenderer |> fromOpt,
      "wrapperStyle": wrapperStyle |> fromOpt,
    },
    children,
  );