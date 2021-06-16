

## Single object model
There are a lot of object like structures that are instanciated only once (controler, model, widgets, ...)
To simplify, these structures have their only instantiation in the .c file and are unknown to any other file which allows user to call these functions without passing a structure as the first parameter.
This is only for easier usage and these objects can be easily converted to normal object-like C structures
