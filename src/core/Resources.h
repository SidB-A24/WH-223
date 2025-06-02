#pragma once

#include <vector>
#include <string>

#include "TEngine.h"

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

	namespace gameParameters
	{
		inline float maxPlayerVelocity = 4; //Tiles per second. We can compute this as 4 units per second. So the move delta is (1/60)*4. So in 60 frames, we would have moved 4.
		inline int tileSize = 64; //pixels
	}
}