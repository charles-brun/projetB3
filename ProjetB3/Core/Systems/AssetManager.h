#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include "../Entities/Actor.h"
#include "../Entities/Player.h"
#include "../Entities/Block.h"
#include "../../Utils/ClassManager.h"
#include "../../Utils/Singleton.h"

class SAssetManager
{
public:
    inline DECLARE_SINGLETON(SAssetManager)
    struct TextureData
    {
        std::string name;
        std::vector<std::string> frames;
        TextureData(const std::string& p_name, std::vector<std::string> p_frames) : name(p_name), frames(p_frames) {}
    };
    struct TextureAsset
    {
        std::string name;
        std::vector<sf::Texture*> frames;
        TextureAsset(const std::string& p_name, std::vector<sf::Texture*> p_frames) : name(p_name), frames(p_frames) {}
        ~TextureAsset()
        {
            for (const auto asset : frames)
            {
                delete asset;
            }
        }
    };
    std::map<int, std::vector<TextureData>> textureData
    {
        {EPlayer::StaticClass()->GetId(), {TextureData("idle", {"hero.png"})}},
        {EBlock::StaticClass()->GetId(), {TextureData("idle", {"block.png"})}}
    };
    std::map<int, std::vector<TextureAsset*>> loadedTextures;

    std::string* GetTexturePath(const int& classID, const std::string& stateName, const int& frame) const;
    sf::Texture* GetTextureAsset(const int& classID, const std::string& stateName, const int& frame) const;
    void LoadClassTextures(int classID);
    std::string font_path = "munro.ttf";
    sf::Font font;
    ~SAssetManager();
};
