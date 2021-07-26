
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
- Remove the namespace singleton thing to use only objects  
- Use exceptions  
- Duckduckgo lite search doesnt work because urls are weird (example: "//duckduckgo.com/l/?uddg=https%3A%2F%2Fgooglesearch.me%2F&amp;rut=4e680418cbfffa14d4e836ec8c198df3eb2782b756b0a18d8c5272d7b839d334") -> needs fixing  
- Content interactive element like system: Can choose content (images, videos or audio) & open it with the command of the user's choice (set in config)  
- yy Yank current url command  
- Add help to all commands (-h prints help in the page\_widget & can be exited with 'q')
