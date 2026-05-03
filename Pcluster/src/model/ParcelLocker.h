#pragma once

#include <string>

#include <model/Location.h>

namespace pcluster {

	class ParcelLocker {

	public:
		ParcelLocker(std::string name, Location location);

		Location getLocation() const;


	private:
		std::string name;
		Location location;
	};

}

