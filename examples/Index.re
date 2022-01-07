
open Reshowcase.Entry;


demo(({addCategory}) => {
  addCategory("Title", ({addDemo}) => {
    addDemo("Basic Usage", _ =>
     <BasicUsageSelect />
    )
  })
})

start()