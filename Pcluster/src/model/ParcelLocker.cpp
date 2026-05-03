#include "ParcelLocker.h"

pcluster::ParcelLocker::ParcelLocker(std::string name, Location location) : name(name), location(location)
{
}

pcluster::Location pcluster::ParcelLocker::getLocation() const
{
	return location;
}
