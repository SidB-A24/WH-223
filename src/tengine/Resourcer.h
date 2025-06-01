#pragma once
#include <raylib.h>
#include <unordered_map>
#include <memory>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

namespace TEngine
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

		std::weak_ptr<std::vector<std::vector<std::string>>> load_csv(const char* filePath, const char* csvDataID);
		std::weak_ptr<std::vector<std::vector<std::string>>> fetch_csv(const char* csvDataID);
		void unload_csv(const char* csvDataID);
		
		
	private:
		std::unordered_map < const char*, std::shared_ptr<Texture2D> > m_texturePool;

		std::unordered_map <const char*, std::shared_ptr<
			std::vector<std::vector<std::string>>
			>> m_csvPool; //Pool of csv data. Can be used by games for various functions. 

		//TODO: Implement JSON data parsing in the future as required.
	};
}