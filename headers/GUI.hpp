#ifndef BLV_GUI_H
#define BLV_GUI_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "Input.hpp"
#include "Object.hpp"
#include "Utility.hpp"

namespace blv{
    class Button : public Object {
        protected:
        //Variables
        bool is_Hovered;
        bool is_Pressed;
        bool is_Selected;

        int width;
        int height;
        
        public:
        //Variables
        uint32_t id;
        //Constructor and Destructor
        Button();
        Button(uint32_t id, int width, int height, sf::Texture *texture);
        ~Button();
        //Functions
        void SetParameters(uint32_t id, int width, int height, sf::Texture *texture);
        virtual void Update(sf::RenderWindow &window);

        bool GetSelected();
        void SetSelected(bool value);

        bool Hovered();
        bool Pressed();
    };

    class Button2T : public Button{
        private:
        public:
        //Variables
        //Constructor and Destructor
        Button2T(uint32_t id, int width, int height, sf::Texture *texture);
        ~Button2T();
        //Functions
        void Update(sf::RenderWindow &window);

        bool On();
    };

    class Button3T : public Button{
        private:
        public:
        //Variables
        //Constructor and Destructor
        Button3T();
        Button3T(uint32_t id, int width, int height, sf::Texture *texture);
        ~Button3T();
        //Functions
        void Update(sf::RenderWindow &window);
    };

    class ButtonContainer{
        private:
        //Variables
        sf::Vector2f position;
        std::vector<Button*> button_Container;
        bool one_Selectable;
        bool dynamic_Sort;
        bool horizontal;
        public:
        //Variables
        uint32_t offset;
        //Constructor and Destructors
        ButtonContainer(uint32_t offset = 48, bool horizontal = true , bool dynamic_Sort = false, bool one_Selectable = true);
        ~ButtonContainer();
        //Functions
        void Update(sf::RenderWindow &window);
        void AddButton(blv::Button &button);

        sf::Vector2f GetPosition();
        void SetPosition(sf::Vector2f position);
    };

    class Slide{
        private:
        //Variables
        sf::Vector2f origin_Position;
        sf::Vector2f target_Position;

        sf::Vector2f current_Position;
        float k;
        //Functions
        void GoToTarget();
        void ReturnToOrigin();
        public:
        //Variables
        bool go_To_Target;
        //Constructor and Destructor
        Slide(sf::Vector2f origin_Position = sf::Vector2f(0, 0), sf::Vector2f target_Position = sf::Vector2f(0, 0)
        , float k = 0.1f);
        ~Slide();
        //Functions
        sf::Vector2f GetPosition();

        void Update();
    };

}

#endif