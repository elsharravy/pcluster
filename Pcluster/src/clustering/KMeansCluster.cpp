#include "KMeansCluster.h"

pcluster::KMeansCluster::KMeansCluster(Location center) : center(center), count(0), latitudeSum(0), longitudeSum(0)
{
	
}

void pcluster::KMeansCluster::addLocation(const Location& location)
{
	latitudeSum += location.getLatitude();
	longitudeSum += location.getLongitude();

	++count;
}

float pcluster::KMeansCluster::recalculateCenter()
{
	if (count == 0) {
		return 0;
	}
	Location newCenter(longitudeSum / count, latitudeSum / count);
	float distanceChange = center.distance(newCenter);
	center = newCenter;
	return distanceChange;
}

pcluster::Location pcluster::KMeansCluster::getCenter() const
{
	return center;
}

void pcluster::KMeansCluster::clear()
{
	latitudeSum = 0;
	longitudeSum = 0;
	count = 0;
}
