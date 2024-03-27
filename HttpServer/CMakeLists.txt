# CMakeList.txt : CMake project for HttpServer, include source and define
# project specific logic here.
#

# Add source to this project's executable.
file(GLOB_RECURSE SOURCE_FILES 
	"src/*.cpp" 
	"includes/*.hpp"
)

add_executable (HttpServer "./src/main.cpp" ${SOURCE_FILES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET HttpServer PROPERTY CXX_STANDARD 17)
endif()

include_directories(CAFFINE
	${CMAKE_SOURCE_DIR}/HttpServer/includes
)

if(WIN32)
  target_link_libraries(HttpServer wsock32 ws2_32)
endif()