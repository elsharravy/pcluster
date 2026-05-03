#pragma once

#include <vector>

#include <model/Location.h>

namespace pcluster {

	class KMeansCluster {
	public:
		KMeansCluster(Location center);

		void addLocationUpdateCenter(const Location& location);
		Location getCenter()const;
	private:
		std::vector<Location> locations;
		Location center;
	};

}

