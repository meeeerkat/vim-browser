#ifndef __MODEL_ELEMENT_H__
#define __MODEL_ELEMENT_H__
#include <string>
#include <vector>

class Element {
    public:
        Element();
        ~Element();
    private:
        std::vector<Element*> children;
};

#endif
