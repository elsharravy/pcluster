#pragma once

#include <iostream>

namespace pcluster {

	class Location {

	public:
		Location(float longitude, float latitude);

		float distance(const Location& location) const;
		friend std::ostream& operator <<(std::ostream& os, const Location& location);

		float getLongitude()const;
		float getLatitude()const;

	private:
		float longitude, latitude;
	};

}
