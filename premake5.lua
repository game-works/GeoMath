local output_dir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

workspace "MathProject"

	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

project "MathProject"
	kind "Makefile"
	language "C++"
	objdir("bin-obj/" .. output_dir .. "/%{prj.name}")
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
		"%{prj.name}/include/imgui",
		"%{prj.name}/include/imgui-sfml"
	}
	configuration { "linux", "gmake" }
  	buildoptions {"-Wall", "-Wextra", "-Wpedantic"}

	filter "configurations:Debug"
		defines "DebugMode"
		symbols "On"
		targetdir "bin/debug"

	filter "configurations:Release"
		defines "Release"
		symbols "On"
		targetdir "bin/release"
