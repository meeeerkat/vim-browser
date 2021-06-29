
## Config
Configuration files are under ~/.vim-browser directory
Example of a valid set of config files can be found under the config\_example directory

## Single object model
There are a lot of object like structures that are instanciated only once (controler, model, widgets, ...)
These classes have a static getter function (that returns a static attribute of the only instanciated object)
Trying to instanciate 2 launches an assert

## Widgets (& other components') connection
Widgets & other components are used together to attain a goal in functions under the commands/ directory.  
Even if these functions are only used by the program and never actually used by the user directly.  
Hence, components *are* (SHOULD BE) very abstract and (almost ?) unrelated, only linked by external functions

## TODO
- DOCUMENT DISPLAY (Document & Element parsing + PageWidget::diplay)
- Opening a page then another on the same tab before the first one was loaded cancels the first page's downloading
- A single libcurl easy\_handle shouldn't be used in multiple threads at once (currently the program crashes it 2 documents are loading at once)
