#pragma once

#include <string>
#include <string_view>

#include <model/Location.h>

namespace pcluster {

	class ParcelLocker {

	public:
		ParcelLocker(std::string name, Location location);

		Location getLocation() const;
		std::string_view getName() const;


	private:
		std::string name;
		Location location;
	};

}

