open Reshowcase.Entry

// Create a demo
demo(({addCategory}) => {
  addCategory("Title", ({addDemo}) => {
    // Add an example
    addDemo("normal", ({string}) =>
      // Register "handles" from your JSX directly
      <h1> {string("text", "hello")->React.string} </h1>
    )
    addDemo("font-size", ({string, int}) =>
      <h1
        style={ReactDOM.Style.make(
          ~fontSize=
          {
            let size = int("font size", {min: 0, max: 100, initial: 30, step: 1})
            Printf.sprintf("%ipx", size)
          },
          (),
        )}>
        {string("text", "hello")->React.string}
      </h1>
    )
  })
})

demo(({addCategory}) =>
  addCategory("Button", ({addDemo}) =>
    addDemo("normal", ({string, bool}) =>
      <button disabled={bool("disabled", false)}> {string("text", "hello")->React.string} </button>
    )
  )
)

start()