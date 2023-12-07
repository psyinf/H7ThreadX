# TODO

* re-direct Core/Src/stm32h7xx_it.c handler functions to a application provided callback
** either via startup script's (startup_stm32h743xihx.s) linkage
** or via installing functions in the handler implementation
** this probably needs to go to foundation or another library
* Add linker-dependency chart to understand and document lib dependencies
* Solve thread-function from member functions
* Add facilities to auto-generate lauch-file from template (probably via cmake.in) 

# LongTerm
* Integrate FileSystem
* Demo with Display
* Make universal for multiple boards
