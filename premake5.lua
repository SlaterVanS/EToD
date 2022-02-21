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
IncludeDir["ImGui"] = "ETOD/vendor/imgui"
IncludeDir["glm"] = "ETOD/vendor/glm"
IncludeDir["stb_image"] = "ETOD/vendor/stb_image"


include "ETOD/vendor/GLFW"
include "ETOD/vendor/Glad"
include "ETOD/vendor/imgui"

project "ETOD"
	location "ETOD"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "etodpch.h"
	pchsource "ETOD/src/etodpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"ETOD_PLATFORM_WINDOWS",
			"ETOD_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "ETOD_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ETOD_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "ETOD_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"ETOD/src",
		"ETOD/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"ETOD"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"ETOD_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "ETOD_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "ETOD_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "ETOD_DIST"
		optimize "on"