
## Current state
It's usable but there will be a lot of bugs and one needs to find another search engine (duckduckgo lite isn't supported yet due to weird url links)  
Currently working on the document printing, user interactions & config setup  

## Config
Configuration files are under ~/.vim-browser directory  
Example of a valid set of config files can be found under the config\_example directory  

## Document printing
HTML documents are (and will be) printed without any consideration for stylesheets:  
the output will not look like it would in a graphic web browser in any way,
it will only print in a way that is both functionnal & easy to read

## TODO
- Need to add color & check for support of each attribute  
- Inputs handling  
- Duckduckgo lite search doesnt work because urls are weird (example: "//duckduckgo.com/l/?uddg=https%3A%2F%2Fgooglesearch.me%2F&amp;rut=4e680418cbfffa14d4e836ec8c198df3eb2782b756b0a18d8c5272d7b839d334") -> needs fixing  
- Add help to all commands (-h prints help in the page\_widget & can be exited with 'q')  
- Media system should differentiate image, audio and video to be able call a different command for each (3 things to set in media config)  
- Copy paste in page content

## TODO in a long time
- Bookmarks  
- Cookies support  
