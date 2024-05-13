#include "headers/Input.hpp"
#include <iostream>

/* Input Clas */
//Variables
bool blv::Input::lock_Mouse = false;
bool blv::Input::lock_Key[128];
//Constructor and Destructor
blv::Input::Input(){

}
blv::Input::~Input(){

}
//Functions
bool blv::Input::KeyDown(Key key){
    return sf::Keyboard::isKeyPressed((sf::Keyboard::Key)key);
}
bool blv::Input::KeyPressed(Key key){
    if(sf::Keyboard::isKeyPressed((sf::Keyboard::Key)key) && !lock_Key[key]){
        lock_Key[key] = true;
        return true;
    }
    else if(!sf::Keyboard::isKeyPressed((sf::Keyboard::Key)key) && lock_Key[key]){
        lock_Key[key] = false;
    }
    return false;
}
bool blv::Input::KeyReleased(Key key){
    if(sf::Keyboard::isKeyPressed((sf::Keyboard::Key)key) && !lock_Key[key]){
        lock_Key[key] = true;
    }
    else if(!sf::Keyboard::isKeyPressed((sf::Keyboard::Key)key) && lock_Key[key]){
        lock_Key[key] = false;
        return true;
    }
    return false;
}

bool blv::Input::MouseDown(MouseButton button){
    return sf::Mouse::isButtonPressed((sf::Mouse::Button)button);
}
bool blv::Input::MousePressed(MouseButton button){
    if(sf::Mouse::isButtonPressed((sf::Mouse::Button)button) && !lock_Mouse){
        lock_Mouse = true;
        return true;
    }
    else if(!sf::Mouse::isButtonPressed((sf::Mouse::Button)button) && lock_Mouse){
        lock_Mouse = false;
    }
    return false;
}
bool blv::Input::MouseReleased(MouseButton button){
    if(sf::Mouse::isButtonPressed((sf::Mouse::Button)button) && !lock_Mouse){
        lock_Mouse = true;
    }
    else if(!sf::Mouse::isButtonPressed((sf::Mouse::Button)button) && lock_Mouse){
        lock_Mouse = false;
        return true;
    }
    return false;
}