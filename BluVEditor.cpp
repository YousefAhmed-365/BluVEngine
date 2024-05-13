#include <iostream>
#include "headers/BluVEditor.hpp"
//Variables
blv::ResMnager blv_Editor::BluVEditor::resManager;

sf::View editor_View(sf::Vector2f(1280.0f * 0.5f, 720 * 0.5f), sf::Vector2f(1280, 720));

enum class Editor_State {
    Edit, Preview
};

Editor_State editor_State = Editor_State::Edit;

//Constructor and Destructor
blv_Editor::BluVEditor::BluVEditor(){
    InitRes();
}
blv_Editor::BluVEditor::~BluVEditor(){
    
}
//Rescources
void blv_Editor::BluVEditor::InitRes(){
    //Buttons
    resManager.CreateTexture(101, "Assets/Textures/GUI/Button2T_Template.png");
    resManager.CreateTexture(102, "Assets/Textures/GUI/Button3T_Template.png");
    //Editor GUI Back Elements
    resManager.CreateTexture(201, "Assets/Textures/GUI/Bottom_Menu.png");
}
//Editor GUI Elements
//Functions
void blv_Editor::BluVEditor::Editing(){

}
//Main Functions
void blv_Editor::BluVEditor::Update(sf::RenderWindow &window, float delta_Time){

}
void blv_Editor::BluVEditor::Render(sf::RenderWindow &window){
    if(editor_State == Editor_State::Edit){
        //View
        window.setView(editor_View);
        //Center Circle
        window.draw(sf::CircleShape(50.0f));
    }
}