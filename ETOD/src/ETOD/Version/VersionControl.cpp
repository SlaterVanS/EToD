#include "etodpch.h"
#include "VersionControl.h"
#include <ETOD/Core/Application.h>

#pragma comment(lib,"wininet.lib")

namespace ETOD {

	std::string read_local_version() {
		std::ifstream file(".etodver");
		if (!file.is_open()) {

			ETOD_CORE_ERROR("本地版本控制文件丢失，请前往官网获取版本修复工具！");
			ETOD_CORE_ERROR("官网地址：www.slatervans.com");

			Application::Get().Close();

			return "";
		}
		std::string local_version;
		getline(file, local_version);
		file.close();
		return local_version;
	}

	std::string get_latest_version() {
		HINTERNET hInternet = InternetOpen(L"User-Agent", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
		if (!hInternet)
		{
			return "";
		}

		HINTERNET hUrl = InternetOpenUrl(hInternet, L"https://apis.slatervans.com/version/version.txt", NULL, 0, INTERNET_FLAG_RELOAD, 0);
		if (!hUrl)
		{
			InternetCloseHandle(hInternet);
			return "";
		}

		char buffer[1024];
		DWORD bytesRead;
		std::string latest_version;

		while (InternetReadFile(hUrl, buffer, sizeof(buffer), &bytesRead) && bytesRead != 0)
		{
			latest_version.append(buffer, bytesRead);
		}

		InternetCloseHandle(hUrl);
		InternetCloseHandle(hInternet);

		return latest_version;
	}

}