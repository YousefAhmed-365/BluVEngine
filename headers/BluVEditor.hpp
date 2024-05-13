#ifndef BLV_BLUVEDITOR_H
#define BLV_BLUVEDITOR_H

#include <SFML/Graphics.hpp>

#include "GUI.hpp"
#include "Input.hpp"
#include "Object.hpp"
#include "ResManager.hpp"
#include "TextObject.hpp"
#include "Utility.hpp"

namespace blv_Editor {
    class BluVEditor{
        public:
        //Variables
        static blv::ResMnager resManager;
        //Constructor and Destructor
        BluVEditor();
        ~BluVEditor();
        //Functions
        void Editing();
        void InitRes();
        //Main Functions
        void Update(sf::RenderWindow &window, float delta_Time);
        void Render(sf::RenderWindow &window);
    };
}

#endif