#include "etodpch.h"
#include "VersionConsole.h"

using namespace ETOD;

namespace ETOD {

	std::string VersionConsoleToEntryPoint()
	{
		#define ETOD_BUILD_ID "v0.0."+ main_version + dot_version + local_version + space_version + test_version

		std::string local_version = read_local_version();
		std::string main_version = "0";
		std::string test_version = " alpha";
		std::string dot_version = ".";
		std::string space_version = " ";

		return ETOD_BUILD_ID;
	}
}