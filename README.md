

## Single object model
There are a lot of object like structures that are instanciated only once (controler, model, widgets, ...)
To simplify, these structures have their only instantiation in the .c file and are unknown to any other file which allows user to call these functions without passing a structure as the first parameter.
This is only for easier usage and these objects can be easily converted to normal object-like C structures


## TODO
### Structure
- Better compartmentalisation by making widgets fully enclosed modules with event callbacks that are set in the controller
- Maybe make the "page" module have it's own functions to load & stuff and the model (which still needs to be unique to keep the same curl session) is only known by the page module
