#pragma once

#include <vector>

#include <model/Location.h>
#include <model/ParcelLocker.h>

namespace pcluster {

	std::vector<Location> kmeans(int clustersCount, const std::vector<ParcelLocker>& lockers, int n = 0, float tolerance = 0.0001);

}