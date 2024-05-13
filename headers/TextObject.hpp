#ifndef BLV_TEXTOBJECT_H
#define BLV_TEXTOBJECT_H

#include <SFML/Graphics.hpp>

namespace blv{
    class Text : public sf::Drawable{
        protected:
        //Variables
        sf::Text text;
        public:
        //Variables
        //Constructor and Destructor
        Text();
        Text(const char *str);
        ~Text();
        //Functions
        sf::Vector2f GetPosition();
        void SetPosition(sf::Vector2f pos);

        void SetText(const char* str);
        void SetFont(sf::Font &font);
        void SetTextColour(sf::Color color);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
}

#endif