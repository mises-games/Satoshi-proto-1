workspace "Satoshi"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Satoshi/vendor/GLFW/include"
IncludeDir["GLAD"] = "Satoshi/vendor/GLAD/include"
IncludeDir["ImGui"] = "Satoshi/vendor/ImGui"

group "Dependencies"

    include "Satoshi/vendor/GLFW"
    include "Satoshi/vendor/GLAD"
    include "Satoshi/vendor/ImGui"

group ""


project "Satoshi"
    location "Satoshi"
    kind "StaticLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp"
    }

    pchheader "stpch.h"
    pchsource "Satoshi/src/stpch.cpp"

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/vendor/json/single_include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.GLAD}",
        "%{prj.name}/src"
    }

    links
    {
        "GLFW",
        "GLAD",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "ST_PLATFORM_MSDOS",
            "ST_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }
    
    filter "configurations:Debug"
        defines "ST_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "ST_RELEASE"
        optimize "On"    
    
    filter "configurations:Dist"
        defines "ST_DIST"
        optimize "On"

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
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Satoshi/vendor/spdlog/include",
        "Satoshi/vendor/json/single_include",
        "Satoshi/src",
        "Satoshi/vendor"
    }

    links
    {
        "Satoshi"
    }
    
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "ST_PLATFORM_MSDOS"
        }
    
    filter "configurations:Debug"
        defines "ST_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "ST_RELEASE"
        optimize "On"    
    
    filter "configurations:Dist"
        defines "ST_DIST"
        optimize "On"