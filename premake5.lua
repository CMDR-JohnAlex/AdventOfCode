workspace "AdventOfCode"
	startproject "2023"

	flags { "MultiProcessorCompile" }

	configurations { "Debug", "Release" }
	platforms { "x64" }

	filter { "platforms:x64" }
		architecture "x86_64"

	targetdir "build"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"





project "2023"
	location "2023"
	kind "ConsoleApp"
	language "C++"
		cppdialect "C++17"
		staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.c",
		"%{prj.name}/**.hpp",
		"%{prj.name}/**.cpp"
	}

	includedirs
	{
		"%{prj.name}"
	}

	postbuildcommands
	{
	}

	filter "configurations:Debug"
		defines "AOC_BUILD_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "AOC_BUILD_RELEASE"
		optimize "on"

	-- Windows
	filter "system:windows"
		systemversion "latest"

		defines
		{
			"AOC_PLATFORM_WINDOWS"
		}

	filter { "system:windows", "configurations:Release" }
		buildoptions "/MT"

	-- Linux (NOT TESTED)
	filter "system:linux"

		defines
		{
			"AOC_PLATFORM_LINUX"
		}