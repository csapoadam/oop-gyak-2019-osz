#pragma once

#include <ctime>
#include <string>

class DateTime {
	time_t secondsSince1970;
public:
	DateTime() : secondsSince1970(time(nullptr)) {
	}
	std::string toString() {
		char time_val[26];
		struct tm res;
		gmtime_s(&res, &secondsSince1970);
		asctime_s(time_val, 26, &res);
		return std::string(time_val);
	}
};