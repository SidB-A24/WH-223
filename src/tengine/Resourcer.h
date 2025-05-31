#pragma once
#include <raylib.h>
#include <unordered_map>
#include <memory>

namespace Engine
{
	class Resourcer
	{
	public:
		Resourcer();
		static Resourcer& Instance();

		~Resourcer();

	public:
		std::weak_ptr<Texture2D> load_texture(const char* filePath, const char* textureID);
		std::weak_ptr<Texture2D> fetch_texture(const char* textureID);
		void unload_texture(const char* textureID);
		
		
	private:
		std::unordered_map < const char*, std::shared_ptr<Texture2D> > m_texturePool;
	};
}