#include "Cluster.h"

pcluster::Cluster::Cluster(Location center) : center(center)
{
}

void pcluster::Cluster::addLocker(const ParcelLocker& locker)
{
	lockers.push_back(locker);
}

std::vector<pcluster::ParcelLocker> pcluster::Cluster::getLockers() const
{
	return lockers;
}
