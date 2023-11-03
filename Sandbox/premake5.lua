project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/MAAT/vendor/spdlog/include",
		"%{wks.location}/MAAT/src",
		"%{wks.location}/MAAT/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
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