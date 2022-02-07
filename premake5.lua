workspace "ETOD"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "ETOD/vendor/GLFW/include"
IncludeDir["Glad"] = "ETOD/vendor/Glad/include"

include "ETOD/vendor/GLFW"
include "ETOD/vendor/Glad"

project "ETOD"
	location "ETOD"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "etodpch.h"
	pchsource "ETOD/src/etodpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"
	}

	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ETOD_PLATFORM_WINDOWS",
			"ETOD_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ETOD_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "ETOD_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "ETOD_DIST"
		buildoptions "/MD"
		optimize "On"

	filter { "system:windows", "configurations:Release" }
		buildoptions "/MT"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"ETOD/vendor/spdlog/include",
		"ETOD/src"
	}

	links
	{
		"ETOD"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ETOD_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "ETOD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ETOD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ETOD_DIST"
		optimize "On"

	filter { "system:windows", "configurations:Release" }
		buildoptions "/MT"