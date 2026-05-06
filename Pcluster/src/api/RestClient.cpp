#include "RestClient.h"

#include <cpr/api.h>

std::pair<std::string, long > pcluster::RestClient::get(std::string_view url, int page, int per_page)
{
    cpr::Response r = cpr::Get(cpr::Url{ url },
        cpr::Parameters{ {"page", std::to_string(page) }, {"per_page", std::to_string(per_page) }, {"fields", "name,location"}});

    if (r.error.code != cpr::ErrorCode::OK)
    {
        throw std::runtime_error(
            "HTTP transport error: " + r.error.message);
    }

    return {r.text, r.status_code};
}
