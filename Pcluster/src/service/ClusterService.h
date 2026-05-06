#pragma once

#include <vector>

#include "model/ParcelLocker.h"

namespace pcluster {

	class ClusterService {
	public:
		std::vector<ParcelLocker> getParcelLockersFromRestApi( int limit, std::string country, std::string province);

	};

}

