set( src "src/model/ParcelLocker.h" "src/model/Cluster.h" "src/model/Location.h" "src/model/Location.cpp" "src/model/ParcelLocker.cpp" "src/model/Cluster.cpp" "src/clustering/KMeans.h" "src/clustering/KMeans.cpp" "src/clustering/KMeansCluster.h" "src/clustering/KMeansCluster.cpp" "src/api/RestClient.h")

add_library( Pcluster "${src}"   "src/api/RestClient.cpp"  "src/json/JsonParser.h" "src/json/JsonParser.cpp")

target_compile_features(Pcluster PUBLIC cxx_std_20)

include(FetchContent)

# CPR
set(CPR_BUILD_TESTS OFF)
set(CPR_CURL_USE_LIBPSL OFF)  

FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 1.14.2) 
FetchContent_MakeAvailable(cpr)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz)
FetchContent_MakeAvailable(json)

target_link_libraries(Pcluster PRIVATE cpr::cpr)
target_link_libraries(Pcluster PRIVATE nlohmann_json::nlohmann_json)

target_include_directories( Pcluster PUBLIC src )