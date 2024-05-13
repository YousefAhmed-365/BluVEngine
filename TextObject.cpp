#include "headers/TextObject.hpp"
/* Text Class */
//Variables
//Constructor and Destructor
blv::Text::Text(){

}
blv::Text::Text(const char *str){
    SetText(str);
}
blv::Text::~Text(){

}
//Function
sf::Vector2f blv::Text::GetPosition(){
    return text.getPosition();
}
void blv::Text::SetPosition(sf::Vector2f pos){
    text.setPosition(pos);
}

void blv::Text::SetText(const char *str){
    text.setString(str);
}
void blv::Text::SetFont(sf::Font &font){
    text.setFont(font);
}
void blv::Text::SetTextColour(sf::Color color){
    text.setFillColor(color);
}

void blv::Text::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(text);
}