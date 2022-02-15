#include "model/nodes/hidden_input.hpp"
#include "app.hpp"


namespace Nodes {

    HiddenInput::HiddenInput(const GumboElement *el, BuildData &build_data)
        : Input(el, build_data, false)
    {

    }

    void HiddenInput::interact(App *app, PrintingOptions::InteractionType)
    {

    }

}
