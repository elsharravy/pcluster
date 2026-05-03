#include "Location.h"

#include <cmath>

pcluster::Location::Location(float longitude, float latitude) : longitude(longitude), latitude(latitude)
{

}

float pcluster::Location::distance(const Location& location) const
{
	float dLon = location.longitude - longitude;
	float dLat = location.latitude - latitude;

	float distance = sqrt(pow(dLon, 2) + pow(dLat, 2));
	return distance;
}

bool pcluster::Location::operator==(const Location& location) const
{
	if ((latitude == location.latitude) && (longitude == location.longitude)) {
		return true;
	}
	return false;
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
