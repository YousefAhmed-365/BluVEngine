#include <iostream>

#include "headers/Engine.hpp"

int main(){

    blv::Engine main_Engine(1280/2, 720/2, "BluVEngine");

    while (main_Engine.UpdateEvents())
    {
        main_Engine.Update();
    }
}