let fromOpt = Js.Nullable.fromOption;

let optBoolToOptBoolean = v =>
  Js.Option.map((. b) => Js.Boolean.to_js_boolean(b), v);

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

module StrOrNode = {
  type t;
  type arg =
    | Str(string)
    | Node(ReasonReact.reactElement);
  external fromStr : string => t = "%identity";
  external fromNode : ReasonReact.reactElement => t = "%identity";
  let encode = v =>
    switch (v) {
    | Str(v) => fromStr(v)
    | Node(v) => fromNode(v)
    };
  let encodeOpt = v => Js.Option.map((. b) => encode(b), v);
};

module StrOrInt = {
  type t;
  type arg =
    | Str(string)
    | Int(int);
  external fromStr : string => t = "%identity";
  external fromInt : int => t = "%identity";
  let encode = v =>
    switch (v) {
    | Str(v) => fromStr(v)
    | Int(v) => fromInt(v)
    };
  let encodeOpt = v => Js.Option.map((. b) => encode(b), v);
};

module Option = {
  type t('a);
  type arg('a) =
    | Str(string)
    | Val('a);
  external fromStr : string => t('a) = "%identity";
  external fromVal : 'a => t('a) = "%identity";
  let encode = v =>
    switch (v) {
    | Str(v) => fromStr(v)
    | Val(v) => fromVal(v)
    };
  let encodeOpt = v => Js.Option.map((. b) => encode(b), v);
};

[@bs.module "react-select"]
external select : ReasonReact.reactClass = "default";

[@bs.obj]
external makeProps :
  (
    ~arrowRenderer: arrowRendererProps => ReasonReact.reactElement=?, /* Renders a custom drop-down arrow. Won't render when set to null */
    ~autoBlur: Js.boolean=?, /* Blurs the input element after a selection has been made. Handy for lowering the keyboard on mobile devices */
    ~autofocus: Js.boolean=?, /* deprecated; use the autoFocus prop instead */
    ~autoFocus: Js.boolean=?, /* autofocus the component on mount */
    ~autoload: Js.boolean=?, /* whether to auto-load the default async options set */
    ~autosize: Js.boolean=?, /* If enabled, the input will expand as the length of its value increases */
    ~backspaceRemoves: Js.boolean=?, /* whether pressing backspace removes the last item when there is no input value */
    ~backspaceToRemoveMessage: string=?, /* prompt shown in input when at least one option in a multiselect is shown, set to '' to clear */
    ~className: string=?, /* className for the outer element */
    ~clearable: Js.boolean=?, /* should it be possible to reset value */
    ~clearAllText: string=?, /* title for the "clear" control when multi is true */
    ~clearRenderer: unit => ReasonReact.reactElement=?, /* Renders a custom clear to be shown in the right-hand side of the select when clearable true: clearRenderer() */
    ~clearValueText: string=?, /* title for the "clear" control */
    ~closeOnSelect: Js.boolean=?, /* whether to close the menu when a value is selected */
    ~deleteRemoves: Js.boolean=?, /* whether pressing delete key removes the last item when there is no input value */
    ~delimiter: string=?, /* delimiter to use to join multiple values */
    ~disabled: Js.boolean=?, /* whether the Select is disabled or not */
    ~escapeClearsValue: Js.boolean=?, /* whether escape clears the value when the menu is closed */
    ~filterOption: ('a, string) => Js.boolean=?, /* method to filter a single option (option, filterString) => boolean */
    /* ~filterOptions=?, */
    /* boolean to enable default filtering or function to filter the options array */
    ~id: string=?, /* html id to set on the input element for accessibility or tests */
    ~ignoreAccents: Js.boolean=?, /* whether to strip accents when filtering */
    ~ignoreCase: Js.boolean=?, /* whether to perform case-insensitive filtering */
    ~inputProps: Js.t({..})=?, /* custom attributes for the Input (in the Select-control) e.g: {'data-foo': 'bar'} */
    ~inputRenderer: Js.t({..}) => ReasonReact.reactElement=?, /* renders a custom input component */
    ~instanceId: string=?, /* instance ID used internally to set html ids on elements for accessibility, specify for universal rendering */
    ~isLoading: Js.boolean=?, /* whether the Select is loading externally or not (such as options being loaded) */
    ~joinValues: Js.boolean=?, /* join multiple values into a single hidden input using the delimiter */
    ~labelKey: string=?, /* the option property to use for the label */
    ~matchPos: [@bs.string] [ | `any | `start]=?, /* (any, start) match the start or entire string when filtering */
    ~matchProp: [@bs.string] [ | `any | `label | `value]=?, /* (any, label, value) which option property to filter on */
    ~menuBuffer: int=?, /* buffer of px between the base of the dropdown and the viewport to shift if menu doesnt fit in viewport */
    ~menuContainerStyle: ReactDOMRe.Style.t=?, /* optional style to apply to the menu container */
    ~menuRenderer: menuRendererProps('a) => ReasonReact.reactElement=?, /* Renders a custom menu with options; accepts the following named parameters */
    ~menuStyle: ReactDOMRe.Style.t=?, /* optional style to apply to the menu */
    ~multi: Js.boolean=?,
    ~name: string=?, /* field name, for hidden <input /> tag */
    ~noResultsText: StrOrNode.t=?, /* placeholder displayed when there are no matching search results or a falsy value to hide it */
    ~onBlur: Js.t({..}) => unit=?, /* onBlur handler: function(event) {} */
    ~onBlurResetsInput: Js.boolean=?, /* Whether to clear input on blur or not. If set to false, it only works if onCloseResetsInput is also false */
    ~onChange: 'a => unit=?, /* onChange handler: function(newOption) {} */
    ~onClose: unit => unit=?, /* handler for when the menu closes: function () {} */
    ~onCloseResetsInput: Js.boolean=?, /* whether to clear input when closing the menu through the arrow */
    ~onFocus: unit => unit=?, /* onFocus handler: function(event) {} */
    ~onInputChange: string => string=?, /* onInputChange handler/interceptor: function(inputValue: string): string */
    ~onInputKeyDown: unit => unit=?, /* input keyDown handler */
    ~onMenuScrollToBottom: unit => unit=?, /* called when the menu is scrolled to the bottom */
    ~onOpen: unit => unit=?, /* handler for when the menu opens: function () {} */
    ~onSelectResetsInput: Js.boolean=?, /* whether the input value should be reset when options are selected. */
    ~onValueClick: ('a, Js.t({..})) => unit=?, /* onClick handler for value labels: function (value, event) {} */
    ~openOnClick: Js.boolean=?, /* open the options menu when the control is clicked (requires searchable = true) */
    ~openOnFocus: Js.boolean=?, /* open the options menu when the control gets focus */
    ~optionClassName: string=?, /* additional class(es) to apply to the elements */
    ~optionComponent: ReasonReact.reactClass=?, /* option component to render in dropdown */
    ~optionRenderer: 'a => ReasonReact.reactElement=?, /* custom function to render the options in the menu */
    ~options: array('a)=?, /* array of options */
    ~removeSelected: Js.boolean=?, /* whether the selected option is removed from the dropdown on multi selects */
    ~pageSize: int=?, /* number of options to jump when using page up/down keys */
    ~placeholder: StrOrNode.t=?, /* field placeholder, displayed when there's no value */
    ~required: Js.boolean=?, /* applies HTML5 required attribute when needed */
    ~resetValue: Option.t('a)=?,
    /* value to set when the control is cleared */
    ~rtl: Js.boolean=?, /* use react-select in right-to-left direction */
    ~scrollMenuIntoView: Js.boolean=?, /* whether the viewport will shift to display the entire menu when engaged */
    ~searchable: Js.boolean=?, /* whether to enable searching feature or not */
    ~searchPromptText: StrOrNode.t=?, /* label to prompt for search input */
    ~simpleValue: Js.boolean=?, /* pass the value to onChange as a string */
    ~style: ReactDOMRe.Style.t=?, /* optional styles to apply to the control */
    ~tabIndex: StrOrInt.t=?, /* tabIndex of the control */
    ~tabSelectsValue: Js.boolean=?, /* whether to select the currently focused value when the [tab] key is pressed */
    ~trimFilter: Js.boolean=?, /* whether to trim whitespace from the filter value */
    ~value: Option.t('a)=?,
    /* initial field value */
    ~valueComponent: ReasonReact.reactClass=?, /* function which returns a custom way to render/manage the value selected <CustomValue /> */
    ~valueKey: string=?, /* the option property to use for the value */
    ~valueRenderer: 'a => ReasonReact.reactElement=?, /* function which returns a custom way to render the value selected function (option) {} */
    ~wrapperStyle: ReactDOMRe.Style.t=?, /* optional styles to apply to the component wrapper */
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~arrowRenderer=?,
      ~autoBlur=?,
      ~autofocus=?,
      ~autoFocus=?,
      ~autoload=?,
      ~autosize=?,
      ~backspaceRemoves=?,
      ~backspaceToRemoveMessage=?,
      ~className=?,
      ~clearable=?,
      ~clearAllText=?,
      ~clearRenderer=?,
      ~clearValueText=?,
      ~closeOnSelect=?,
      ~deleteRemoves=?,
      ~delimiter=?,
      ~disabled=?,
      ~escapeClearsValue=?,
      ~filterOption=?,
      /* ~filterOptions=?, */
      ~id=?,
      ~ignoreAccents=?,
      ~ignoreCase=?,
      ~inputProps=?,
      ~inputRenderer=?,
      ~instanceId=?,
      ~isLoading=?,
      ~joinValues=?,
      ~labelKey=?,
      ~matchPos=?,
      ~matchProp=?,
      ~menuBuffer=?,
      ~menuContainerStyle=?,
      ~menuRenderer=?,
      ~menuStyle=?,
      ~multi=?,
      ~name=?,
      ~noResultsText=?,
      ~onBlur=?,
      ~onBlurResetsInput=?,
      ~onChange=?,
      ~onClose=?,
      ~onCloseResetsInput=?,
      ~onFocus=?,
      ~onInputChange=?,
      ~onInputKeyDown=?,
      ~onMenuScrollToBottom=?,
      ~onOpen=?,
      ~onSelectResetsInput=?,
      ~onValueClick=?,
      ~openOnClick=?,
      ~openOnFocus=?,
      ~optionClassName=?,
      ~optionComponent=?,
      ~optionRenderer=?,
      ~options=?,
      ~removeSelected=?,
      ~pageSize=?,
      ~placeholder=?,
      ~required=?,
      ~resetValue=?,
      ~rtl=?,
      ~scrollMenuIntoView=?,
      ~searchable=?,
      ~searchPromptText=?,
      ~simpleValue=?,
      ~style=?,
      ~tabIndex=?,
      ~tabSelectsValue=?,
      ~trimFilter=?,
      ~value=?,
      ~valueComponent=?,
      ~valueKey=?,
      ~valueRenderer=?,
      ~wrapperStyle=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=select,
    ~props=
      makeProps(
        ~arrowRenderer?,
        ~autoBlur=?autoBlur |> optBoolToOptBoolean,
        ~autofocus=?autofocus |> optBoolToOptBoolean,
        ~autoFocus=?autoFocus |> optBoolToOptBoolean,
        ~autoload=?autoload |> optBoolToOptBoolean,
        ~autosize=?autosize |> optBoolToOptBoolean,
        ~backspaceRemoves=?backspaceRemoves |> optBoolToOptBoolean,
        ~backspaceToRemoveMessage?,
        ~className?,
        ~clearable=?clearable |> optBoolToOptBoolean,
        ~clearAllText?,
        ~clearRenderer?,
        ~clearValueText?,
        ~closeOnSelect=?closeOnSelect |> optBoolToOptBoolean,
        ~deleteRemoves=?deleteRemoves |> optBoolToOptBoolean,
        ~delimiter?,
        ~disabled=?disabled |> optBoolToOptBoolean,
        ~escapeClearsValue=?escapeClearsValue |> optBoolToOptBoolean,
        ~filterOption?,
        /* ~filterOptions?, */
        ~id?,
        ~ignoreAccents=?ignoreAccents |> optBoolToOptBoolean,
        ~ignoreCase=?ignoreCase |> optBoolToOptBoolean,
        ~inputProps?,
        ~inputRenderer?,
        ~instanceId?,
        ~isLoading=?isLoading |> optBoolToOptBoolean,
        ~joinValues=?joinValues |> optBoolToOptBoolean,
        ~labelKey?,
        ~matchPos?,
        ~matchProp?,
        ~menuBuffer?,
        ~menuContainerStyle?,
        ~menuRenderer?,
        ~menuStyle?,
        ~multi=?multi |> optBoolToOptBoolean,
        ~name?,
        ~noResultsText=?noResultsText |> StrOrNode.encodeOpt,
        ~onBlur?,
        ~onBlurResetsInput=?onBlurResetsInput |> optBoolToOptBoolean,
        ~onChange?,
        ~onClose?,
        ~onCloseResetsInput=?onCloseResetsInput |> optBoolToOptBoolean,
        ~onFocus?,
        ~onInputChange?,
        ~onInputKeyDown?,
        ~onMenuScrollToBottom?,
        ~onOpen?,
        ~onSelectResetsInput=?onSelectResetsInput |> optBoolToOptBoolean,
        ~onValueClick?,
        ~openOnClick=?openOnClick |> optBoolToOptBoolean,
        ~openOnFocus=?openOnFocus |> optBoolToOptBoolean,
        ~optionClassName?,
        ~optionComponent?,
        ~optionRenderer?,
        ~options?,
        ~removeSelected=?removeSelected |> optBoolToOptBoolean,
        ~pageSize?,
        ~placeholder=?placeholder |> StrOrNode.encodeOpt,
        ~required=?required |> optBoolToOptBoolean,
        ~resetValue=?resetValue |> Option.encodeOpt,
        ~rtl=?rtl |> optBoolToOptBoolean,
        ~scrollMenuIntoView=?scrollMenuIntoView |> optBoolToOptBoolean,
        ~searchable=?searchable |> optBoolToOptBoolean,
        ~searchPromptText=?searchPromptText |> StrOrNode.encodeOpt,
        ~simpleValue=?simpleValue |> optBoolToOptBoolean,
        ~style?,
        ~tabIndex=?tabIndex |> StrOrInt.encodeOpt,
        ~tabSelectsValue=?tabSelectsValue |> optBoolToOptBoolean,
        ~trimFilter=?trimFilter |> optBoolToOptBoolean,
        ~value=?value |> Option.encodeOpt,
        ~valueComponent?,
        ~valueKey?,
        ~valueRenderer?,
        ~wrapperStyle?,
        (),
      ),
    children,
  );