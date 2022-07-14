project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/ETOD/vendor/spdlog/include",
		"%{wks.location}/ETOD/src",
		"%{wks.location}/ETOD/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"ETOD"
	}

	filter "system:windows"
		systemversion "latest"

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