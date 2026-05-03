set( src "src/model/ParcelLocker.h" "src/model/Cluster.h" "src/model/Location.h" "src/model/Location.cpp" "src/model/ParcelLocker.cpp" "src/model/Cluster.cpp" )

add_library( Pcluster "${src}" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Pcluster PROPERTY CXX_STANDARD 20)
endif()

include(FetchContent)

# CPR
set(CPR_BUILD_TESTS OFF)
set(CPR_CURL_USE_LIBPSL OFF)  

FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 1.14.2) 
FetchContent_MakeAvailable(cpr)

target_link_libraries(Pcluster PRIVATE cpr::cpr)

target_include_directories( Pcluster PUBLIC src )  