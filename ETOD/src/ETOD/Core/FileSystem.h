#pragma once

#include "ETOD/Core/Buffer.h"

namespace ETOD {

	class FileSystem
	{
	public:
		// TODO: move to FileSystem class
		static Buffer ReadFileBinary(const std::filesystem::path& filepath);
	};

}