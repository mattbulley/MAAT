include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "MAAT"
	architecture "x86_64"
	startproject "MAAT-Editor"

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
	include "MAAT/vendor/GLFW"
	include "MAAT/vendor/Glad"
	include "MAAT/vendor/imgui"
	include "MAAT/vendor/yaml-cpp"
group ""

include "MAAT"
include "Sandbox"
include "MAAT-Editor"