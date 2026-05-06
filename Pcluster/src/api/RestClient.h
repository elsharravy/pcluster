#pragma once

#include <string>
#include <string_view>
#include <utility>

class RestClient {
public:
	static std::pair<std::string, long > get(std::string_view url, int page, int per_page);
 };