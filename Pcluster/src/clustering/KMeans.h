#pragma once

#include <vector>

#include <model/Cluster.h>
#include <model/Location.h>
#include <model/ParcelLocker.h>

namespace pcluster {

	std::vector<Location> kmeans(int clustersCount, const std::vector<ParcelLocker>& lockers, int n = 0, float tolerance = 0.0001);
	std::vector<Cluster> clustering(const std::vector<Location>& centroids, const std::vector<ParcelLocker>& lockers);

}