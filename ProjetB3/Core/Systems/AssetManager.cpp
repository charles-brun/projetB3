#include "AssetManager.h"

std::string* SAssetManager::GetTexturePath(const int& classID, const std::string& stateName, const int& frame) const
{
    if (textureData.contains(classID))
    {
        for (auto texture: textureData.find(classID)->second)
        {
            if (texture.name == stateName && frame < texture.frames.size())
            {
                return &texture.frames[frame];
            }
        }
    }
    return nullptr;
}

sf::Texture* SAssetManager::GetTextureAsset(const int& classID, const std::string& stateName, const int& frame) const
{
    if (loadedTextures.contains(classID))
    {
        for (const auto& texture: loadedTextures.find(classID)->second)
        {
            if (texture->name == stateName && frame < texture->frames.size())
            {
                return texture->frames[frame];
            }
        }
    }
    return nullptr;
}

void SAssetManager::LoadClassTextures(int classID)
{
    if (loadedTextures.contains(classID))
    {
        return;
    }
    if (textureData.contains(classID))
    {
        std::vector<TextureAsset*> textureAssets = {};
        for (const auto& state: textureData.find(classID)->second)
        {
            std::vector<sf::Texture*> frames;
            for (const auto& frame: state.frames)
            {
                sf::Texture* texture = new sf::Texture();
                if (!texture->loadFromFile(frame))
                {
                    continue;
                }
                frames.push_back(texture);
            }
            textureAssets.push_back(new TextureAsset(state.name, frames));
        }
        loadedTextures.insert(std::pair(classID, textureAssets));
    }
}

SAssetManager::~SAssetManager()
{
    for (const auto& classTexture : loadedTextures)
    {
        for (auto asset : classTexture.second)
        {
            delete asset;
        }
    }
}
