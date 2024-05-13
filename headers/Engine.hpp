//CPP Includes
#include <iostream>
//SFML Includes
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
//BluVEngine Includes
#include "BluVEditor.hpp"
/* Engine Class */
namespace blv{
    class Engine{
        private:
        //Functions
        sf::RenderWindow *engine_Window;
        sf::Event *engine_Event;

        sf::Clock engine_Delta_Clock;
        sf::Time delta_Time_Clock;
        public:
        //Variables
        float delta_Time;
        //Constructor and Destructor
        Engine(int window_Width, int window_Height, const char *window_title);
        ~Engine();
        //Functions
        bool UpdateEvents();

        void Update();
        void Render();

        //Project Variables
        blv_Editor::BluVEditor E_0;
    };

}