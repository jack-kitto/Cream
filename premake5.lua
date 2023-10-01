outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

workspace("Cream")
architecture("x64")

configurations({
	"Debug",
	"Release",
	"Dist",
})

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
	"%{prj.name}/vendor/spdlog/include",
})

filter("system.windows")
cppdialect("C++17")
staticruntime("On")
systemversion("10.0")

defines({ "CM_PLATFORM_WINDOWS", "CM_BUILD_DLL" })

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
	"%{prj.name}/vendor/spdlog/include",
	"Cream/src",
})

links({
	"Cream",
})

filter("system.windows")
cppdialect("C++17")
staticruntime("On")
systemversion("10.0")

defines({ "CM_PLATFORM_WINDOWS", "CM_BUILD_DLL" })

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
