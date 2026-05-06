#pragma once

#include <vector>

#include <nlohmann/json_fwd.hpp>

#include <model/ParcelLocker.h>

namespace pcluster {

	class JsonParser {

	public:
		static bool parseLockers(std::vector<pcluster::ParcelLocker>& lockers, const nlohmann::json& json, int limit);

	};

}
