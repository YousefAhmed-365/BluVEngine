#ifndef BLV_RESMANAGER_H
#define BLV_RESMANAGER_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "Utility.hpp"

namespace blv{
    struct Texture_Token{
        //Variables
        uint32_t id;
        sf::Texture texture;
        //Constructor and Destructor
        Texture_Token(uint32_t id, sf::Texture &texture);
        ~Texture_Token();
    };

    class ResMnager{
        private:
        //Variables
        static sf::Texture texture_Template;
        static std::vector<Texture_Token> textures_Tokens;
        //Functions
        static void InitLoading();
        public:
        //Variables
        static sf::Font default_Font;
        //Constructor and Destructor
        ResMnager();
        ~ResMnager();
        //Functions
        static void CreateTexture(uint32_t id, const char *path);
        static bool CreatTextureToken(uint32_t id, sf::Texture &texture);
        static sf::Texture *FindTexture(uint32_t id);
    };
}

#endif