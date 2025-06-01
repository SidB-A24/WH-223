#pragma once

#include <vector>
#include <string>

namespace WH_223
{
	namespace gameResources
	{
		inline std::vector<const char*> tileMaps = 
		{
			"testing"
		}; //Names of the file without .csv

		inline std::vector<const char*> assetSubDirectories =
		{
			"environment",
			"other",
			"player"
		}; //Names of the sub directory folders within the assets folder.
	}
}