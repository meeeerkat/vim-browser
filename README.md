

## Single object model
There are a lot of object like structures that are instanciated only once (controler, model, widgets, ...)
These classes have a static getter function (that returns a static attribute of the only instanciated object)
Trying to instanciate 2 launches an assert

## Widgets (& other components') connection
Widgets & other components are used together to attain a goal in functions under the commands/ directory.  
Even if these functions are only used by the program and never actually used by the user directly.  
Hence, components *are* (SHOULD BE) very abstract and (almost ?) unrelated, only linked by external functions

## TODO
