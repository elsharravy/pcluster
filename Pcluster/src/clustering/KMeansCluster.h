#pragma once

#include <vector>

#include <model/Location.h>

namespace pcluster {

	class KMeansCluster {
	public:
		KMeansCluster(Location center);

		void addLocation(const Location& location);
		float recalculateCenter();
		Location getCenter()const;
		void clear();
	private:
		float latitudeSum;
		float longitudeSum;
		int count;
		Location center;
	};

}

