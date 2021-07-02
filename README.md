
## Config
Configuration files are under ~/.vim-browser directory  
Example of a valid set of config files can be found under the config\_example directory  

## Single object model
There are a lot of object like structures that are instanciated only once (controller, model, widgets, ...)  
They actually are namespaces

## Widgets (& other components') connection
Widgets & other components are used together to attain a goal in functions under the commands/ directory.  
Even if these functions are only used by the program and never actually used by the user directly.  
Hence, components *are* (SHOULD BE) very abstract and (almost ?) unrelated, only linked by external functions.  

## TODO
- Remove display\_document\_callback from TabsWidget::close (TabsWidget::open doesn't have it anymore) because it should be done in the Commands::close function
- Close command has a weird behavior (closes the wrong tab ?)
- DOCUMENT DISPLAY (Document & Element parsing + PageWidget::diplay)
- Opening a page then another on the same tab before the first one was loaded cancels the first page's downloading
- A single libcurl easy\_handle shouldn't be used in multiple threads at once (currently the program crashes it 2 documents are loading at once)
