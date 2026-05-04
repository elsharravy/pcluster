#pragma once

#include <vector>

#include <model/ParcelLocker.h>
#include <model/Location.h>

namespace pcluster {

	class Cluster {
	public:
		Cluster(Location center);

		void addLocker(const ParcelLocker& locker);
		std::vector<ParcelLocker> getLockers() const;
	private:
		std::vector<ParcelLocker> lockers;
		Location center;
	};

}

