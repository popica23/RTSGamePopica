#include "texture_manager.h"
#include <iostream>

void Texture_manager::loadTexture(const std::string& name, const std::string& filename)
{
    /* Load the texture */
    sf::Texture tex;
    if(!tex.loadFromFile(filename)){
    	std::cout<<filename<<" did not load correctly!";
    }

    /* Add it to the list of textures */
    this->textures[name] = tex;

    return;
}

sf::Texture& Texture_manager::getRef(const std::string& texture)
{
    return this->textures.at(texture);
}
