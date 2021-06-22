

## Single object model
There are a lot of object like structures that are instanciated only once (controler, model, widgets, ...)
To simplify, these structures have their only instantiation in the .c file and are unknown to any other file which allows user to call these functions without passing a structure as the first parameter.
This is only for easier usage and these objects can be easily converted to normal object-like C structures

## Naming pattern:
Functions are prefixed in the same way as in lexbor (path\_to\_file\_function\_name)  

## Widgets (& other components') connection
Widgets & other components are used together to attain a goal in functions under the commands/ directory.  
Even if these functions are only used by the program and never actually used by the user directly.  
Hence, components *are* (SHOULD BE) very abstract and (almost ?) unrelated, only linked by external functions

## TODO
