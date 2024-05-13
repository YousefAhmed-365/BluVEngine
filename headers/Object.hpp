#ifndef BLV_OBJECT_H
#define BLV_OBJECT_H

#include <SFML/Graphics.hpp>

#include "Utility.hpp"

namespace blv{
    class Object : public sf::Drawable {
        protected:
        //Variables
        sf::Texture *texture;
        public:
        //Variables
        sf::Sprite sprite;
        //Constructor and Destructor
        Object();
        ~Object();
        //Functions
        void ChangeTexture(sf::Texture *texture);
        void ChangeTextureRect(sf::IntRect intRect);

        sf::Vector2f GetPosition();
        void SetPosition(sf::Vector2f position);

        void Move(sf::Vector2f vec2);
        void Follow(sf::Vector2f target, float k = 0.02f, bool smooth = true);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };

    // To Do : Trigger Class
    /*class Trigger : public Object{
        private:
        //Variables
        bool activated;
        bool one_Time_Trigger;
        public:
        //Variables
        //Constructor and Destructor
        Trigger(bool one_Time_Trigger);
        ~Trigger();
        //Functions
        bool IsActivated();
    };*/
}
#endif