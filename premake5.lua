workspace("Cream")
startproject("Sanbox")
architecture("x64")

configurations({
	"Debug",
	"Release",
	"Dist",
})

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project("Sandbox")
location("Sandbox")
kind("ConsoleApp")
language("C++")

targetdir("bin/" .. outputdir .. "/%{prj.name}")
objdir("bin-int/" .. outputdir .. "/%{prj.name}")

files({
	"%{prj.name}/src/**.h",
	"%{prj.name}/src/**.cpp",
})

includedirs({
	"Cream/vendor/spdlog/include",
	"Cream/src",
})

links({
	"Cream",
})

filter("system:windows")
cppdialect("C++17")
staticruntime("On")
systemversion("latest")

defines({
	"CM_PLATFORM_WINDOWS",
})

filter("configurations:Debug")
defines("CM_DEBUG")
symbols("On")

filter("configurations:Release")
defines("CM_RELEASE")
optimize("On")

filter("configurations:Dist")
defines("CM_DIST")
optimize("On")
project("Cream")
location("Cream")
kind("SharedLib")
language("C++")

targetdir("bin/" .. outputdir .. "/%{prj.name}")
objdir("bin-int/" .. outputdir .. "/%{prj.name}")

files({
	"%{prj.name}/src/**.h",
	"%{prj.name}/src/**.cpp",
})

includedirs({
	"%{prj.name}/src",
	"%{prj.name}/vendor/spdlog/include",
})

filter("system:windows")
cppdialect("C++17")
staticruntime("On")
systemversion("latest")

defines({
	"CM_PLATFORM_WINDOWS",
	"CM_BUILD_DLL",
})

postbuildcommands({
	("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"),
})

filter("configurations:Debug")
defines("CM_DEBUG")
symbols("On")

filter("configurations:Release")
defines("CM_RELEASE")
optimize("On")

filter("configurations:Dist")
defines("CM_DIST")
optimize("On")
