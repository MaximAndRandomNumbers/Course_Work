#pragma once
#include <string>
using namespace std;

class GlobalData {
	
	GlobalData() = default;
	~GlobalData() = default;

	GlobalData& operator=(const GlobalData&) = delete;
	GlobalData(const GlobalData&) = delete;

public:
	const size_t MAX_NUMBER_OF_PARAMS = 4;
	const string* PARAMETERS_IN_ORDER = new string[MAX_NUMBER_OF_PARAMS]{ "artist", "album", "year", "genre" };
	size_t numberOfParams;
	string* params;
	string SourceDirectory;
	string DistDirectory;

	static GlobalData& getObject() {
		static GlobalData a;
		return a;
	}
};
