#include "RestClient.h"

#include <cpr/api.h>

std::pair<std::string, long > pcluster::RestClient::get(std::string_view url, int page, int per_page, std::string country, std::string province)
{
    cpr::Parameters params;
    params.Add({ "page", std::to_string(page) });
    params.Add({ "per_page", std::to_string(per_page) });
    if (country != "") {
        params.Add({ "country", country });
    }
    if (province != "") {
        params.Add({ "province", province });
    }

    cpr::Response r = cpr::Get(cpr::Url{ url },
        params);

    if (r.error.code != cpr::ErrorCode::OK)
    {
        throw std::runtime_error(
            "HTTP transport error: " + r.error.message);
    }

    return {r.text, r.status_code};
}
