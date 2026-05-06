#include "JsonFileSaver.h"

#include <fstream>

#include <nlohmann/json.hpp>

namespace pcluster {

	void to_json(nlohmann::json& j, const Location& l)
	{
		j = {
			{"longitude", l.getLongitude()},
			{"latitude", l.getLatitude()}
		};
	}

	void to_json(nlohmann::json& j, const ParcelLocker& pl)
	{
		j = {
			{"Name", pl.getName()},
			{"Location", pl.getLocation()}
		};
	}

	void to_json(nlohmann::json& j, const pcluster::Cluster& c)
	{
		j = nlohmann::json{
			{"Center", c.getCenter()},
			{ "ParcelLockers", c.getLockers()}
		};
	}

}


void pcluster::JsonFileSaver::saveClustersToFile(std::string_view filePath,const std::vector<Cluster>& clusters)
{
	std::ofstream file(std::string(filePath) , std::ios::out | std::ios::trunc);

	if (!file) {
		throw std::runtime_error("Failed to open file");
	}

		nlohmann::json json = clusters;
		file << json.dump(4);

	file.close();
}
