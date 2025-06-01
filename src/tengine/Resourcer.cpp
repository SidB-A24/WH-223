#include "Resourcer.h"
#include "Logger.h"

#include <raylib.h>
#include <memory>


namespace TEngine
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

	//TEXTURE METHODS
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
		std::weak_ptr<Texture2D> weakTexture;

		if (m_texturePool.find(textureID) != m_texturePool.end())
		{
			weakTexture = m_texturePool[textureID];
		}
		else
		{
			Logger::Instance().error("Invalid Texture ID. No such texture in texture pool.");
			throw 1;
		}

		return weakTexture;
	}

	void Resourcer::unload_texture(const char* textureID)
	{
		if (m_texturePool.find(textureID) != m_texturePool.end())
		{
			UnloadTexture(*m_texturePool[textureID]);
			m_texturePool.erase(textureID); //Removing that element so that fetch doesn't return some nullptr mess.
		}
		else
		{
			Logger::Instance().error("Invalid Texture ID. No such texture in texture pool.");
			throw 1;
		}
	}


	//CSV METHODS
	std::weak_ptr<std::vector<std::vector<std::string>>> Resourcer::load_csv(const char* filePath, const char* csvDataID)
	{
		//Yes, redefining the variables each iteration does add some overhead but it's so minute that it's not worth worrying about, and the ease of readability is more important here.
		std::vector<std::vector<std::string>> csvData;

		std::ifstream csvFileStream;
		try
		{
			csvFileStream.open(filePath);
		}
		catch (...) //File Not Found Error
		{
			Logger::Instance().error("Invalid file path for loading CSV data.");
		}

		std::string rowData;

		while (std::getline(csvFileStream, rowData)) //Grabs one line at a time from the fileStream and assigns it to the string.
		{
			std::vector<std::string> row;
			std::string dataPoint;
			
			//std::stringstream rowDataStream(rowData);Shorthand for :
			std::stringstream rowDataStream;
			rowDataStream.str(rowData);

			while (std::getline(rowDataStream, dataPoint, ',')) //Fetches one substring at a time from stringStream based on delim: ','. Notice the similarity with fileStream? The stream objects all work in a similar fashion. Go C++!!!!!
			{
				row.push_back(dataPoint);
			}

			csvData.push_back(row);
		}

		std::shared_ptr<std::vector<std::vector<std::string>>> csvDataPtr = std::make_shared <std::vector<std::vector<std::string>>>(csvData); //Making a smart pointer of the data for storage. This way, retrieval doesn't add mega overhead. 
		
		m_csvPool.insert({csvDataID, csvDataPtr});

		std::weak_ptr<std::vector<std::vector<std::string>>> weakCsvDataPtr = csvDataPtr; //Returning a weak pointer of the CSV data.
		return weakCsvDataPtr;
	}

	std::weak_ptr<std::vector<std::vector<std::string>>> Resourcer::fetch_csv(const char* csvDataID)
	{
		std::weak_ptr<std::vector<std::vector<std::string>>> weakCsvDataPtr;

		if (m_csvPool.find(csvDataID) != m_csvPool.end())
		{
			weakCsvDataPtr = m_csvPool[csvDataID];
		}
		else
		{
			Logger::Instance().error("Invalid CSV data ID. No such data in data pool.");
			throw 1;
		}

		return weakCsvDataPtr;
	}

	void Resourcer::unload_csv(const char* csvDataID)
	{
		m_csvPool.erase(csvDataID); //This does nothing if there is no csvDataID key assigned to a value in the hashmap.

		if (m_csvPool.find(csvDataID) == m_csvPool.end())
		{
			Logger::Instance().warn("No matching data in csv data pool for deletion. Continuing.");
		}

	}

}

