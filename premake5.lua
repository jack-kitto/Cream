workspace("Cream")
startproject("Sanbox")
architecture("x64")

configurations({
	"Debug",
	"Release",
	"Dist",
})

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Cream/vendor/GLFW/include"
IncludeDir["Glad"] = "Cream/vendor/Glad/include"
IncludeDir["imgui"] = "Cream/vendor/imgui/"

include("Cream/vendor/GLFW/")
include("Cream/vendor/Glad/")
include("Cream/vendor/imgui/")

------------------ SANDBOX ------------------
project("Sandbox")
---------------------------------------------
location("Sandbox")
kind("ConsoleApp")
language("C++")
staticruntime("on")

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
buildoptions("/MDd")
symbols("On")

filter("configurations:Release")
defines("CM_RELEASE")
buildoptions("/MD")
optimize("On")

filter("configurations:Dist")
buildoptions("/MD")
defines("CM_DIST")
optimize("On")

------------------ CREAM ------------------
project("Cream")
-------------------------------------------
location("Cream")
kind("SharedLib")
language("C++")
staticruntime("on")
targetdir("bin/" .. outputdir .. "/%{prj.name}")
objdir("bin-int/" .. outputdir .. "/%{prj.name}")
pchheader("cmpch.h")
pchsource("Cream/src/cmpch.cpp")

files({
	"%{prj.name}/src/**.h",
	"%{prj.name}/src/**.cpp",
})

includedirs({
	"%{prj.name}/src",
	"%{prj.name}/vendor/spdlog/include",
	"%{IncludeDir.GLFW}",
	"%{IncludeDir.Glad}",
	"%{IncludeDir.ImGui}",
})

links({
	"GLFW",
	"Glad",
	"opengl32.lib",
	"dwmapi.lib",
	"ImGui",
})

filter("system:windows")
cppdialect("C++17")
staticruntime("On")
systemversion("latest")

defines({
	"CM_PLATFORM_WINDOWS",
	"CM_BUILD_DLL",
	"CM_ENABLE_ASSERTS",
	"GLFW_INCLUDE_NONE",
})

postbuildcommands({
	("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"),
})

filter("configurations:Debug")
defines("CM_DEBUG")
buildoptions("/MDd")
symbols("On")

filter("configurations:Release")
defines("CM_RELEASE")
buildoptions("/MD")
optimize("On")

filter("configurations:Dist")
defines("CM_DIST")
buildoptions("/MD")
optimize("On")
