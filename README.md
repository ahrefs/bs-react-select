> **Warning**
> This repository is no longer maintained, as we don't use it anymore at Ahrefs.

# Reason bindings for react-select

[Reason](https://reasonml.github.io/) bindings for [react-select](https://github.com/JedWatson/react-select/tree/v1.x).

## Status

🚧 Not everything is supported yet; Unstable; Doesn't follow semver; 🚧

Feel free to create an issue or PR.

## Installation, [npm](https://www.npmjs.com/package/@ahrefs/bs-react-select)

```sh
npm install --save @ahrefs/bs-react-select
```

Then add `@ahrefs/bs-react-select` to `bs-dependencies` in your `bsconfig.json`:

```js
{
  ...
  "bs-dependencies": ["@ahrefs/bs-react-select"]
}
```

To include styles

```js
[%bs.raw {|require('react-select/dist/react-select.css')|}];
```

## Contributing/Development

Run `yarn start` for bucklescript compiler watcher.
Then run `yarn start:reshowcase` which will start on `localhost:9001`.

It would be good to have an example for every component and every prop eventually.

## TODO

* [ ] `aria-describedby` / `aria-label` / `aria-labelledby` SpecialCreationFunction doesn't allow to change prop name, hopefully this will be possible in the next bucklescript releases
* [ ] Annotate [Async props](https://github.com/JedWatson/react-select/tree/v1.x#async-options)
* [ ] Annotate [Creatable props](https://github.com/JedWatson/react-select/tree/v1.x#creatable-properties)
* [ ] Can we reduce boilerplate in `Select.re` and `SelectMulti.re`?
* [ ] Upgrade to react-select version 2
* [x] `resetValue` / `value` - string | 'a OR string | array('a)
* [x] `filterOptions` - bool | func
* [x] Separate SelectMulti

## Examples

TODO

## Select vs SelectMulti

* Option.arg - `Val` vs `Arr`
* onChange - `option('a)` vs `array('a)`
* onValueClick - `'a` vs `array('a)`
* filterOptions - one extra argument `~current: array('a)`
