#include "headers/Object.hpp"
//Variables
//Constructor and Destructor
blv::Object::Object(){
    texture = nullptr;
    if(texture != nullptr)
        sprite.setTexture(*texture);
}
blv::Object::~Object(){

}
//Functions
void blv::Object::ChangeTexture(sf::Texture *texture){
    if(texture != nullptr){
        this->texture = texture;
        sprite.setTexture(*texture);
    }
    else
        blv::Log("Failed to change texture : Invalid Texture Pointer");
}
void blv::Object::ChangeTextureRect(sf::IntRect intRect){
    sprite.setTextureRect(intRect);
}

sf::Vector2f blv::Object::GetPosition(){
    return sprite.getPosition();
}
void blv::Object::SetPosition(sf::Vector2f position){
    sprite.setPosition(position);
}

void blv::Object::Move(sf::Vector2f vec2){
    sprite.move(vec2);
}
void blv::Object::Follow(sf::Vector2f target, float k, bool smooth){
    if(smooth){
        sprite.setPosition(sf::Vector2f(sprite.getPosition().x + (target.x - sprite.getPosition().x) * k, sprite.getPosition().y + (target.y - sprite.getPosition().y) * k));
    }else{
        sprite.move(target - sprite.getPosition());
    }
}

void blv::Object::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(sprite);
}