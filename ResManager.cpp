#include "headers/ResManager.hpp"
/* Texture_Token Struct */
//Constructor and Destructor
blv::Texture_Token::Texture_Token(uint32_t id, sf::Texture &texture){
    this->id = id;
    this->texture = texture;
}
blv::Texture_Token::~Texture_Token(){
    
}
/* ResManager Class */
//Assets To Load
//Variables
sf::Font blv::ResMnager::default_Font;
sf::Texture blv::ResMnager::texture_Template;
std::vector<blv::Texture_Token> blv::ResMnager::textures_Tokens;
void blv::ResMnager::InitLoading(){
    default_Font.loadFromFile("Assets/Fonts/Pixolletta8px.ttf");
}
//Constructor and Destructor
blv::ResMnager::ResMnager(){
    InitLoading();
}
blv::ResMnager::~ResMnager(){

}
//Functions
void blv::ResMnager::CreateTexture(uint32_t id, const char* path){
    if(texture_Template.loadFromFile(path))
        CreatTextureToken(id, texture_Template);
}
bool blv::ResMnager::CreatTextureToken(uint32_t id, sf::Texture &texture){
    bool repeated_ID = false;
    for(auto &e: textures_Tokens){
        if(id == e.id){
            repeated_ID = true;
            break;
        }
    }
    if(!repeated_ID){
        textures_Tokens.push_back(blv::Texture_Token(id, texture));
        return true;
    }
    else
        blv::Log("Failed to create a texture token : Repeated ID");

    return false;
}
sf::Texture *blv::ResMnager::FindTexture(uint32_t id){
    for(auto &e : textures_Tokens){
        if(id == e.id){
            return &e.texture;
            break;
        }
    }
    blv::Log("Failed to find texture : Invalid ID");
    return nullptr;
}