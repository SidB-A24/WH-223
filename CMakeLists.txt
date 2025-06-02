# CMakeList.txt : CMake project for WH_223, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("WH_223")

# Add source to this project's executable.
add_executable (WH_223 "src/WH_223.cpp" "src/WH_223.h" 
"src/core/Game.cpp" "src/core/Game.h" 
"src/core/Labyrinth.h" "src/core/Labyrinth.cpp" 
"src/core/Resources.h" 
"src/entity/Entity.h" "src/entity/Entity.cpp" 
"src/entity/Player.h" "src/entity/Player.cpp" 
"src/entity/Narrator.h" "src/entity/Narrator.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET WH_223 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

# Dependencies
include(FetchContent)

#Now for TEngine
FetchContent_Declare(
    TEngine
    GIT_REPOSITORY https://github.com/SidB-A24/TEngine.git
    GIT_TAG master
)

FetchContent_MakeAvailable(TEngine)

target_link_libraries(${PROJECT_NAME} TEngine)