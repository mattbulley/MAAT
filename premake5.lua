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

include "MAAT/vendor/GLFW"

project "MAAT"
	location "MAAT"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "mtpch.h"
	pchsource "MAAT/src/mtpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MAAT_PLATFORM_WINDOWS",
			"MAAT_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "MAAT_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "MAAT_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "MAAT_DIST"
		optimize "On"

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
		"MAAT/vendor/spdlog/include",
		"MAAT/src"
	}

	links
	{
		"MAAT"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MAAT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MAAT_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "MAAT_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "MAAT_DIST"
		optimize "On"