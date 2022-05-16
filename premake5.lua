include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

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

group "Dependencies"
	include "vendor/premake"
	include "EToD/vendor/GLFW"
	include "EToD/vendor/Glad"
	include "EToD/vendor/imgui"
	include "EToD/vendor/yaml-cpp"
group ""

include "EToD"
include "Sandbox"
include "EToD-Editor"