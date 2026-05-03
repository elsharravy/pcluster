#include "Location.h"

#include <cmath>

pcluster::Location::Location(float longitude, float latitude) : longitude(longitude), latitude(latitude)
{

}

float pcluster::Location::distance(const Location& location) const
{
	float dLon = location.longitude - longitude;
	float dLat = location.latitude - latitude;

	float distance = sqrt(pow(dLon, 2) + pow(dLon, 2));
	return distance;
}

float pcluster::Location::getLongitude() const
{
	return longitude;
}

float pcluster::Location::getLatitude() const
{
	return latitude;
}

std::ostream& pcluster::operator<<(std::ostream& os, const Location& location)
{
	return os << "Longitude: " << location.longitude << " Latitude: " << location.latitude;
}
