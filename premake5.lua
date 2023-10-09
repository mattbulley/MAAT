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

project "MAAT"
	location "MAAT"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.16299.0"

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
		systemversion "10.0.16299.0"

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