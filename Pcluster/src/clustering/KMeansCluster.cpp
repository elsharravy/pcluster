#include "KMeansCluster.h"

pcluster::KMeansCluster::KMeansCluster(Location center) : center(center)
{
}

void pcluster::KMeansCluster::addLocationUpdateCenter(const Location& location)
{
	float lat = center.getLatitude();
	float lon = center.getLongitude();

	size_t locCount = locations.size();
	float newLat = (lat * locCount + location.getLatitude()) / (locCount+1) ;
	float newLon = (lon * locCount + location.getLongitude()) / (locCount+1) ;

	Location newCenter(newLon, newLat);
	center = newCenter;

	locations.push_back(location);
}

pcluster::Location pcluster::KMeansCluster::getCenter() const
{
	return center;
}
