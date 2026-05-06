#include "JsonParser.h"

#include <nlohmann/json.hpp>

void pcluster::JsonParser::parseLockers(std::vector<pcluster::ParcelLocker>& lockers, const nlohmann::json& json)
{
    if (!json.contains("items") || !json["items"].is_array()) {
        return;
    }

    for (const auto& item : json["items"])
    {
        std::string name = item.value("name", "unknown");

        if (!item.contains("location") || !item["location"].is_object())
            continue;

        const auto& loc = item["location"];

        if (!loc.contains("latitude") || !loc["latitude"].is_number())
            continue;

        if (!loc.contains("longitude") || !loc["longitude"].is_number())
            continue;

        float latitude = loc["latitude"];
        float longitude = loc["longitude"];

        ParcelLocker locker(name, Location(longitude, latitude));
        lockers.push_back(locker);
    }
}
