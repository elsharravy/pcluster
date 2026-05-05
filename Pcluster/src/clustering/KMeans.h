#pragma once

#include <vector>

#include <model/Cluster.h>
#include <model/Location.h>
#include <model/ParcelLocker.h>

namespace pcluster {

	std::vector<Location> kmeans(int clustersCount, const std::vector<ParcelLocker>& lockers, int maxIterations = 100, float tolerance = 0.001);
	std::vector<Cluster> clustering(const std::vector<Location>& centroids, const std::vector<ParcelLocker>& lockers);

}