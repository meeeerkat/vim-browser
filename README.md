
## Current state
Tab & command & loading systems work fine but there is no real output yet  
Currently working on the document parsing & printing

## Config
Configuration files are under ~/.vim-browser directory  
Example of a valid set of config files can be found under the config\_example directory  

## Document printing
HTML documents are (and will be) printed without any consideration for stylesheets:
the output will not look like it would in a graphic web browser in any way,
it will only print in a way that is both functionnal & easy to read

## TODO
- DOCUMENT DISPLAY (Document & Element parsing + PageWidget::diplay)
- Images url don't have the "https:", need to add it if necessary (like they were added for links)
- Need to add color & check for support of each attribute
- Inputs handling
- Replace pointers with references where possible AND MORE GENERALY FOLLOW C++ GUIDELINES
- Remove the namespace singleton thing to use only objects
- Use exceptions
