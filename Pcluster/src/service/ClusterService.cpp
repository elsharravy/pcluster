#include "ClusterService.h"

#include <utility>

#include <nlohmann/json.hpp>

#include <api/RestClient.h>
#include <json/JsonParser.h>

std::vector<pcluster::ParcelLocker> pcluster::ClusterService::getParcelLockersFromRestApi(int limit, std::string country, std::string province)
{
	std::vector<pcluster::ParcelLocker> lockers;

	int page = 1;
	constexpr int perPage = 500;

	std::string endpointURL = "https://api-global-points.easypack24.net/v1/points";

	while (true) {
		auto response = RestClient::get(endpointURL, page, perPage, country, province);

		auto json = nlohmann::json::parse(response.first);

		if (!JsonParser::parseLockers(lockers, json, limit)) {
			return lockers;
		}

		if (page >= json["total_pages"]) {
			break;
		}

		++page;
	}

	return lockers;
}
