#include "headers/GUI.hpp"
/* Button Class */
//Variables
//COnstructor and Destructor
blv::Button::Button(){
    this->id = 0;

    this->width = width;
    this->height = height;

    is_Hovered = false;
    is_Pressed = false;
}
blv::Button::Button(uint32_t id, int width, int height, sf::Texture *texture){
    this->id = id;

    this->width = width;
    this->height = height;
    
    if(texture != nullptr)
        sprite.setTexture(*texture);
    /*else
        blv::Log("Failed to set texture to sprite : Invalid Texture Pointer");
    */
    is_Hovered = false;
    is_Pressed = false;

    sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(width, height)));
}
blv::Button::~Button(){

}
//Functions
void blv::Button::SetParameters(uint32_t id, int width, int height, sf::Texture *texture){
    this->id = id;

    this->width = width;
    this->height = height;
    
    if(texture != nullptr)
        sprite.setTexture(*texture);
    /*else
        blv::Log("Failed to set texture to sprite : Invalid Texture Pointer");
    */
    is_Hovered = false;
    is_Pressed = false;

    sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(width, height)));
}
void blv::Button::Update(sf::RenderWindow &window){
    sf::Vector2f mouse_Position = window.mapPixelToCoords((sf::Vector2i)sf::Mouse::getPosition(window));

    is_Hovered = sprite.getGlobalBounds().contains(mouse_Position);
    if(is_Hovered)
        is_Pressed = blv::Input::MousePressed(blv::Input::left);
}

bool blv::Button::GetSelected(){
    return is_Selected;
}
void blv::Button::SetSelected(bool value){
    is_Selected = value;
}

bool blv::Button::Hovered(){
    return is_Hovered;
}
bool blv::Button::Pressed(){
    return is_Pressed;
}
/* Button2T Class */
//Variables
//Constructor and Destructor
blv::Button2T::Button2T(uint32_t id, int width, int height, sf::Texture *texture){
    this->id = id;

    this->width = width;
    this->height = height;

    if(texture != nullptr)
        sprite.setTexture(*texture);
    else
        blv::Log("Failed to set texture to sprite : Invalid Texture Pointer");


    sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(width, height)));

    is_Selected = false;
}
blv::Button2T::~Button2T(){

}
//Functions
void blv::Button2T::Update(sf::RenderWindow &window){
    Button::Update(window);
    if(is_Pressed){
        is_Selected = !is_Selected;
    }

    if(is_Selected)
        sprite.setTextureRect(sf::IntRect(sf::Vector2i(width, 0), sf::Vector2i(width, height)));
    else 
        sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(width, height)));
}

bool blv::Button2T::On(){
    return is_Selected;
}
/* Button3T Class */
//Variables
//Constructor and Destructor
blv::Button3T::Button3T(){
    this->id = 0;

    this->width = 48;
    this->height = 48;

    is_Selected = false;

    if(texture != nullptr)
        sprite.setTexture(*texture);
    /*else
        blv::Log("Failed to set texture to sprite : Invalid Texture Pointer");
    */

    sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(width, height)));
}
blv::Button3T::Button3T(uint32_t id, int width, int height, sf::Texture *texture){
    this->id = id;

    this->width = width;
    this->height = height;

    is_Selected = false;

    if(texture != nullptr)
        sprite.setTexture(*texture);
    else
        blv::Log("Failed to set texture to sprite : Invalid Texture Pointer");
        

    sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(width, height)));
}
blv::Button3T::~Button3T(){

}
//Functions
void blv::Button3T::Update(sf::RenderWindow &window){
    Button::Update(window);
    if(is_Pressed){
        is_Selected = !is_Selected;
    }
    /* 
    Important note : If the button is pressed repeatedly fasy, then it will flicker its selected state
    So keep in mind that this may be need to be fixed if it became a big issue with the user.

    The button will stop flickering its selected state if it's pressed again.
    */
    if(!is_Hovered && !is_Selected)
        sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(width, height)));
    else if(is_Hovered && !is_Selected)
        sprite.setTextureRect(sf::IntRect(sf::Vector2i(width, 0), sf::Vector2i(width, height)));
    else
        sprite.setTextureRect(sf::IntRect(sf::Vector2i(width + width, 0), sf::Vector2i(width, height)));
}
/* ButtonContainer Class */
//Variables
//Constructor and Destructor
blv::ButtonContainer::ButtonContainer(uint32_t offset, bool horizontal, bool dynamic_Sort, bool one_Selectable){

    position = sf::Vector2f(0.0f, 0.0f);

    this->one_Selectable = one_Selectable;
    this->dynamic_Sort = dynamic_Sort;

    this->offset = offset;
    this->horizontal = horizontal;
}
blv::ButtonContainer::~ButtonContainer(){
    
}
//Functions
void blv::ButtonContainer::Update(sf::RenderWindow &window){
    std::vector<bool> old_Selected(button_Container.size());
    if(one_Selectable){
        for(int i = 0; i < button_Container.size(); i++){
            old_Selected[i] = button_Container[i]->GetSelected();
        }
    }
    for(int b = 0; b < button_Container.size(); b++){
        if(horizontal)
            button_Container[b]->SetPosition(position + sf::Vector2f( offset * b, 0.0f));
        else
            button_Container[b]->SetPosition(position + sf::Vector2f(0.0f, b * offset));
        button_Container[b]->Update(window);
    }

    if(one_Selectable){
        std::vector<bool> new_Selected(button_Container.size());
        for(int i = 0; i < button_Container.size(); i++){
            new_Selected[i] = button_Container[i]->GetSelected();
        }
        /*
        The two loops under this comment :
        First loop : Checks if there's a change between old and new buttons selected states
        and if there's then it will set the current button's selected state to true and
        erase_Rest variable to true to allow the second loop to run. if there isn't any change
        then nothing will happen.

        Second loop : Checks if a new and an old button's selected state are true, if true then it
        will set the current buttons's selected state to false and exit the loop.

        Remember : it's impossible for the user to change more than one button at once
        so that's why the two loops break as soon as their condition is true.
        */
        bool erase_Rest = false;
        for(int i = 0; i < button_Container.size(); i++){
            if(new_Selected[i] && !old_Selected[i]){
                new_Selected[i] = true;
                button_Container[i]->SetSelected(true);
                erase_Rest = true;
                break;
            }
        }
        for(int i = 0; i < button_Container.size(); i++){
            if(erase_Rest){
                if(new_Selected[i] && old_Selected[i]){
                    new_Selected[i] = false;
                    button_Container[i]->SetSelected(false);
                    break;
                }
            }
        }
    }
}
void blv::ButtonContainer::AddButton(Button &button){
    button_Container.push_back(&button);
}

sf::Vector2f blv::ButtonContainer::GetPosition(){
    return position;
}
void blv::ButtonContainer::SetPosition(sf::Vector2f position){
    this->position = position;
}
/* Slide Class */
//Variables
//Constructor and Destructor
blv::Slide::Slide(sf::Vector2f origin_Position, sf::Vector2f target_Position, float k){
    this->origin_Position = origin_Position;
    this->target_Position = target_Position;

    current_Position = origin_Position;

    this->k = k;

    go_To_Target = false;
}

blv::Slide::~Slide(){

}
//Functions
void blv::Slide::GoToTarget(){
    sf::Vector2f dir = target_Position - current_Position;
    current_Position += dir * k;
}

void blv::Slide::ReturnToOrigin(){
    sf::Vector2f dir = origin_Position - current_Position;
    current_Position += dir * k;
}

sf::Vector2f blv::Slide::GetPosition(){
    return current_Position;
}

void blv::Slide::Update(){
    if(go_To_Target)
        GoToTarget();
    else
        ReturnToOrigin();
}