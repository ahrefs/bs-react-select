let fromOpt = Js.Nullable.fromOption;

type arrowRendererProps = {
  .
  "onMouseDown": unit => unit,
  "isOpen": bool,
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