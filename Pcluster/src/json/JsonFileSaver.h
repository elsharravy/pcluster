#pragma once

#include <string_view>

#include <model/Cluster.h>

namespace pcluster {

	class JsonFileSaver {

	public:
		static void saveClustersToFile(std::string_view filePath,const std::vector<Cluster>& clusters );

	};

}
