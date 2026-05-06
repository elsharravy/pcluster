#include "RestClient.h"

#include <cpr/api.h>

std::pair<std::string, long > RestClient::get(std::string_view url, int page, int per_page)
{
    cpr::Response r = cpr::Get(cpr::Url{ url },
        cpr::Authentication{ "user", "pass", cpr::AuthMode::BASIC },
        cpr::Parameters{ {"page", std::to_string(page) }, {"per_page", std::to_string(page) }});
    return std::make_pair<>(r.text, r.status_code);
}
