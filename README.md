
## Current state
This project is on hold for now.  
Usable for mostly text based websites such as Wikipedia.  
Search engine support isn't working (duckduckgo lite will do the search but using :interact to click on the link will not redirect to the right page)  
-> Need to write the urls directly   
The lack of javascript support will break most websites.  
There might be some bugs and one needs to find another search engine (duckduckgo lite isn't supported yet due to weird url links)  

## Config
The configuration file is ~/.vim-browser.yaml, an example can be found in the top directory.  
/!\ Without a configuration file, the programm will exit with an error (containing the path where the config file is expected) but *with a badly formatted configuration file, the program will crash*.  

## How to build it
make
### Dependencies
- libvim (see https://github.com/meeeerkat/vim-base) (should be in libvim directory)
- ncurses
- glib2.0
- gumbo-parser
- yaml-cpp
- libcurl

## How will this be different to lynx ?
- It already has multi-tabs support
- It's vim-like
- It's content oriented and doesn't/won't care at all about any CSS (only the HTML structure matters)
- I hope to make user interactions more efficient (by choosing the input/link following qutebrowser's way among other things, a basic version of this system is already functionnal (interact command))


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
- Throw error message for YAML parsing errors in config files  
- Free all the used memory when quitting (valgrind debug)  
- Need to print html pages in a much prettier way

## TODO in a long time
- Bookmarks  
- Config relative paths entries should be understood properly (~ sign isn't modified yet)  
