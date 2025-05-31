#include "Resourcer.h"
#include "Logger.h"

#include <raylib.h>
#include <memory>

namespace Engine
{
	static Resourcer* s_Instance = nullptr;

	Resourcer::Resourcer()
	{
		s_Instance = this;
	}

	Resourcer& Resourcer::Instance()
	{
		if (s_Instance)
		{
			return *s_Instance;
		}
		else
		{
			Logger::Instance().error("<Resourcer> The Resourcer cannot be retrieved without initializing.");

			throw;
		}
	}

	Resourcer::~Resourcer()
	{

	}
	std::weak_ptr<Texture2D> Resourcer::load_texture(const char* filePath, const char* textureID)
	{
		Image image;

		try
		{
			image = LoadImage(filePath);
		} 
		catch (...) //File Not Found Error
		{
			Logger::Instance().warn("Invalid file path for loading texture");
		}
		
		std::shared_ptr<Texture2D> texture = std::make_shared<Texture2D>(LoadTextureFromImage(image));
		m_texturePool.insert({ textureID, texture });

		std::weak_ptr<Texture2D> weakTexture = texture;

		return weakTexture;
	}

	std::weak_ptr<Texture2D> Resourcer::fetch_texture(const char* textureID)
	{
		std::weak_ptr<Texture2D> texture;

		if (m_texturePool.find(textureID) != m_texturePool.end())
		{
			texture = m_texturePool[textureID];
		}
		else
		{
			Logger::Instance().error("Invalid Texture ID. No such texture in texture pool.");
			throw 1;
		}

		return texture;
	}
	void Resourcer::unload_texture(const char* textureID)
	{
		if (m_texturePool.find(textureID) != m_texturePool.end())
		{
			
			UnloadTexture(*m_texturePool[textureID]);
		}
		else
		{
			Logger::Instance().error("Invalid Texture ID. No such texture in texture pool.");
			throw 1;
		}
	}
}

