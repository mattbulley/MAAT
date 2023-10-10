workspace "MAAT"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Include directories relative to the root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "MAAT/vendor/GLFW/include"
IncludeDir["Glad"] = "MAAT/vendor/Glad/include"
IncludeDir["ImGui"] = "MAAT/vendor/imgui"
IncludeDir["glm"] = "MAAT/vendor/glm"

include "MAAT/vendor/GLFW"
include "MAAT/vendor/Glad"
include "MAAT/vendor/imgui"

project "MAAT"
	location "MAAT"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "mtpch.h"
	pchsource "MAAT/src/mtpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
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
		"%{IncludeDir.glm}"
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
			"MAAT_PLATFORM_WINDOWS",
			"MAAT_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "MAAT_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "MAAT_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "MAAT_DIST"
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
		"MAAT/vendor/spdlog/include",
		"MAAT/vendor/glm",
		"MAAT/src",
		"MAAT/vendor"
	}

	links
	{
		"MAAT"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"MAAT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MAAT_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "MAAT_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "MAAT_DIST"
		runtime "Release"
		optimize "on"