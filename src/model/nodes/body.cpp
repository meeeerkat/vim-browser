#include "model/nodes/body.hpp"


namespace Nodes {

    Body::Body(BuildData &build_data)
        : Element(build_data)
    {}
 
    Body::Body(const GumboElement* el, BuildData &build_data)
        : Element(el, build_data)
    {}
    
    void Body::printw(WINDOW *window, PrintingOptions &printing_options)
    {
        Element::printw(window, printing_options);
        Element::print_children(window, printing_options);
    }
}
