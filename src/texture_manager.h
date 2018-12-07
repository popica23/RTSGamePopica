#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGE_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class Texture_manager{

private:

    /* Array of textures used */
    std::map<std::string, sf::Texture> textures;

    public:

    /* Add a texture from a file */
    void loadTexture(const std::string& name, const std::string &filename);

    /* Translate an id into a reference */
    sf::Texture& getRef(const std::string& texture);

    /* Constructor */


};


#endif // TEXTURE_MANAGER_H
