# Reason bindings for react-select

[Reason](https://reasonml.github.io/) bindings for [react-select](https://github.com/JedWatson/react-select).

## Status

🚧 Not everything is supported yet. 🚧

Feel free to create an issue or PR.

## Installation

```sh
npm install --save bs-react-select
```

Then add `bs-react-select` to `bs-dependencies` in your `bsconfig.json`:

```js
{
  ...
  "bs-dependencies": ["bs-react-select"]
}
```

To include styles

```js
[%bs.raw {|require('react-select/dist/react-select.css')|}];
```

## TODO

* [ ] `aria-describedby` / `aria-label` / `aria-labelledby` SpecialCreationFunction doesn't allow to change prop name, hopefully this will be possible in the next bucklescript releases
* [x] `resetValue` / `value` - string | 'a OR string | array('a)
* [x] `filterOptions` - bool | func
* [ ] Separate SelectMulti

## Usage

Please take a look at [examples](https://github.com/ahrefs/bs-react-select/tree/master/examples).
To run demo:

```sh
$ cd examples
$ npm install
$ npm start
```
