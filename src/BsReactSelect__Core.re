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
    | Node(React.element);
  let encode: arg => t =
    fun
    | Str(v) => Obj.magic(v)
    | Node(v) => Obj.magic(v);
  let encodeOpt = Belt.Option.map(_, encode);
};

module StrOrInt = {
  type t;
  type arg =
    | Str(string)
    | Int(int);
  let encode: arg => t =
    fun
    | Str(v) => Obj.magic(v)
    | Int(v) => Obj.magic(v);
  let encodeOpt = Belt.Option.map(_, encode);
};
