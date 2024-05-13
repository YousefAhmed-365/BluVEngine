#include "headers/Engine.hpp"
/* Engine Class */
//Variables
//Construcotr and Destructor
blv::Engine::Engine(int window_Width, int window_Height, const char *window_title){
    engine_Window = new sf::RenderWindow(sf::VideoMode(window_Width, window_Height), window_title, sf::Style::Close);
    engine_Window->setFramerateLimit(60);

    engine_Event = new sf::Event;
}
blv::Engine::~Engine(){
    delete engine_Window;
    engine_Window = NULL;

    delete engine_Event;
    engine_Event = NULL;
}
//Functions
bool blv::Engine::UpdateEvents(){
    while (engine_Window->pollEvent(*engine_Event))
    {
        switch (engine_Event->type)
        {
        case sf::Event::Closed:
            engine_Window->close();
            return false;
            break;
        
        default:
            break;
        }
    }
    return true;
}

void blv::Engine::Update(){
    delta_Time_Clock = engine_Delta_Clock.restart();
    delta_Time = delta_Time_Clock.asSeconds();

    E_0.Update(*engine_Window, delta_Time);

    engine_Window->clear(sf::Color(23.5f, 24.0f, 25.0f));
    Render();
    engine_Window->display();
}
void blv::Engine::Render(){
    E_0.Render(*engine_Window);
}