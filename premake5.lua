include "./vendor/premake/premake_customization/solution_items.lua"

workspace "ETOD"
	architecture "x86_64"
	startproject "EToD-Editor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/ETOD/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/ETOD/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/ETOD/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/ETOD/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/ETOD/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/ETOD/vendor/entt/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/ETOD/vendor/yaml-cpp/include"

group "Dependencies"
	include "vendor/premake"
	include "ETOD/vendor/GLFW"
	include "ETOD/vendor/Glad"
	include "ETOD/vendor/imgui"
	include "ETOD/vendor/yaml-cpp"
group ""

include "ETOD"
include "Sandbox"
include "EToD-Editor"
