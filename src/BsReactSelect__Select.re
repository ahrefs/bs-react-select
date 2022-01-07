open BsReactSelect__Core;

module Option = {
  type t('a);
  type arg('a) =
    | Str(string)
    | Val('a);
  let encode: arg('a) => t('a) =
    fun
    | Str(v) => Obj.magic(v)
    | Val(v) => Obj.magic(v);
  let encodeOpt = Belt.Option.map(_, encode);
};

module FilterOptions = {
  type t('a);
  type sortFunc('a) = (~options: array('a), ~filter: string) => array('a);
  type arg('a) =
    | Bool(bool)
    | Func(sortFunc('a));
  let encode: arg('a) => t('a) =
    fun
    | Bool(v) => Obj.magic(v)
    | Func(v) => Obj.magic(v);
  let encodeOpt = Belt.Option.map(_, encode);
};

[@bs.module "react-select"] [@react.component]
external make :
(
  ~multi: bool,
  ~arrowRenderer: arrowRendererProps => ReasonReact.reactElement=?, /* Renders a custom drop-down arrow. Won't render when set to null */
  ~autoBlur: bool=?, /* Blurs the input element after a selection has been made. Handy for lowering the keyboard on mobile devices */
  ~autofocus: bool=?, /* deprecated; use the autoFocus prop instead */
  ~autoFocus: bool=?, /* autofocus the component on mount */
  ~autoload: bool=?, /* whether to auto-load the default async options set */
  ~autosize: bool=?, /* If enabled, the input will expand as the length of its value increases */
  ~backspaceRemoves: bool=?, /* whether pressing backspace removes the last item when there is no input value */
  ~backspaceToRemoveMessage: string=?, /* prompt shown in input when at least one option in a multiselect is shown, set to '' to clear */
  ~className: string=?, /* className for the outer element */
  ~clearable: bool=?, /* should it be possible to reset value */
  ~clearAllText: string=?, /* title for the "clear" control when multi is true */
  ~clearRenderer: unit => ReasonReact.reactElement=?, /* Renders a custom clear to be shown in the right-hand side of the select when clearable true: clearRenderer() */
  ~clearValueText: string=?, /* title for the "clear" control */
  ~closeOnSelect: bool=?, /* whether to close the menu when a value is selected */
  ~deleteRemoves: bool=?, /* whether pressing delete key removes the last item when there is no input value */
  ~delimiter: string=?, /* delimiter to use to join multiple values */
  ~disabled: bool=?, /* whether the Select is disabled or not */
  ~escapeClearsValue: bool=?, /* whether escape clears the value when the menu is closed */
  ~filterOption: ('a, string) => bool=?, /* method to filter a single option (option, filterString) => bool */
  ~filterOptions: FilterOptions.t('a)=?,
  /* bool to enable default filtering or function to filter the options array */
  ~id: string=?, /* html id to set on the input element for accessibility or tests */
  ~ignoreAccents: bool=?, /* whether to strip accents when filtering */
  ~ignoreCase: bool=?, /* whether to perform case-insensitive filtering */
  ~inputProps: Js.t({..})=?, /* custom attributes for the Input (in the Select-control) e.g: {'data-foo': 'bar'} */
  ~inputRenderer: Js.t({..}) => ReasonReact.reactElement=?, /* renders a custom input component */
  ~instanceId: string=?, /* instance ID used internally to set html ids on elements for accessibility, specify for universal rendering */
  ~isLoading: bool=?, /* whether the Select is loading externally or not (such as options being loaded) */
  ~joinValues: bool=?, /* join multiple values into a single hidden input using the delimiter */
  ~labelKey: string=?, /* the option property to use for the label */
  ~matchPos: [ | `any | `start]=?, /* (any, start) match the start or entire string when filtering */
  ~matchProp: [ | `any | `label | `value]=?, /* (any, label, value) which option property to filter on */
  ~menuBuffer: int=?, /* buffer of px between the base of the dropdown and the viewport to shift if menu doesnt fit in viewport */
  ~menuContainerStyle: ReactDOMRe.Style.t=?, /* optional style to apply to the menu container */
  ~menuRenderer: menuRendererProps('a) => ReasonReact.reactElement=?, /* Renders a custom menu with options; accepts the following named parameters */
  ~menuStyle: ReactDOMRe.Style.t=?, /* optional style to apply to the menu */
  ~name: string=?, /* field name, for hidden <input /> tag */
  ~noResultsText: StrOrNode.t=?, /* placeholder displayed when there are no matching search results or a falsy value to hide it */
  ~onBlur: Js.t({..}) => unit=?, /* onBlur handler: function(event) {} */
  ~onBlurResetsInput: bool=?, /* Whether to clear input on blur or not. If set to false, it only works if onCloseResetsInput is also false */
  ~onChange: Js.nullable('a) => unit=?, /* onChange handler: function(newOption) {} */
  ~onClose: unit => unit=?, /* handler for when the menu closes: function () {} */
  ~onCloseResetsInput: bool=?, /* whether to clear input when closing the menu through the arrow */
  ~onFocus: unit => unit=?, /* onFocus handler: function(event) {} */
  ~onInputChange: string => string=?, /* onInputChange handler/interceptor: function(inputValue: string): string */
  ~onInputKeyDown: unit => unit=?, /* input keyDown handler */
  ~onMenuScrollToBottom: unit => unit=?, /* called when the menu is scrolled to the bottom */
  ~onOpen: unit => unit=?, /* handler for when the menu opens: function () {} */
  ~onSelectResetsInput: bool=?, /* whether the input value should be reset when options are selected. */
  ~onValueClick: ('a, Js.t({..})) => unit=?, /* onClick handler for value labels: function (value, event) {} */
  ~openOnClick: bool=?, /* open the options menu when the control is clicked (requires searchable = true) */
  ~openOnFocus: bool=?, /* open the options menu when the control gets focus */
  ~optionClassName: string=?, /* additional class(es) to apply to the elements */
  ~optionComponent: ReasonReact.reactClass=?, /* option component to render in dropdown */
  ~optionRenderer: 'a => ReasonReact.reactElement=?, /* custom function to render the options in the menu */
  ~options: array('a)=?, /* array of options */
  ~removeSelected: bool=?, /* whether the selected option is removed from the dropdown on multi selects */
  ~pageSize: int=?, /* number of options to jump when using page up/down keys */
  ~placeholder: StrOrNode.t=?, /* field placeholder, displayed when there's no value */
  ~required: bool=?, /* applies HTML5 required attribute when needed */
  ~resetValue: Option.t('a)=?,
  /* value to set when the control is cleared */
  ~rtl: bool=?, /* use react-select in right-to-left direction */
  ~scrollMenuIntoView: bool=?, /* whether the viewport will shift to display the entire menu when engaged */
  ~searchable: bool=?, /* whether to enable searching feature or not */
  ~searchPromptText: StrOrNode.t=?, /* label to prompt for search input */
  ~simpleValue: bool=?, /* pass the value to onChange as a string */
  ~style: ReactDOMRe.Style.t=?, /* optional styles to apply to the control */
  ~tabIndex: StrOrInt.t=?, /* tabIndex of the control */
  ~tabSelectsValue: bool=?, /* whether to select the currently focused value when the [tab] key is pressed */
  ~trimFilter: bool=?, /* whether to trim whitespace from the filter value */
  ~value: Option.t('a)=?,
  /* initial field value */
  ~valueComponent: ReasonReact.reactClass=?, /* function which returns a custom way to render/manage the value selected <CustomValue /> */
  ~valueKey: string=?, /* the option property to use for the value */
  ~valueRenderer: 'a => ReasonReact.reactElement=?, /* function which returns a custom way to render the value selected function (option) {} */
  ~wrapperStyle: ReactDOMRe.Style.t=?, /* optional styles to apply to the component wrapper */
) => React.element = "default";
