workspace "MAAT"
	architecture "x64"
	startproject "MAAT-Editor"

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
IncludeDir["stb_image"] = "MAAT/vendor/stb_image"
IncludeDir["entt"] = "MAAT/vendor/entt/include"
IncludeDir["yaml_cpp"] = "MAAT/vendor/yaml-cpp/include"
IncludeDir["ImGuizmo"] = "MAAT/vendor/ImGuizmo"

group "Dependencies"
	include "MAAT/vendor/GLFW"
	include "MAAT/vendor/Glad"
	include "MAAT/vendor/imgui"
	include "MAAT/vendor/yaml-cpp"
group ""

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
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",

		"%{prj.name}/vendor/ImGuizmo/ImGuizmo.h",
		"%{prj.name}/vendor/ImGuizmo/ImGuizmo.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.yaml_cpp}",
		"%{IncludeDir.ImGuizmo}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"yaml-cpp",
		"opengl32.lib"
	}

	filter "files:MAAT/vendor/ImGuizmo/**.cpp"
	flags { "NoPCH" }

	filter "system:windows"
		systemversion "latest"

		defines
		{
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
		"MAAT/src",
		"MAAT/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"MAAT"
	}

	filter "system:windows"
		systemversion "latest"

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

project "MAAT-Editor"
	location "MAAT-Editor"
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
		"MAAT/src",
		"MAAT/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.ImGuizmo}"
	}

	links
	{
		"MAAT"
	}

	filter "system:windows"
		systemversion "latest"

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