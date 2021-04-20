workspace "Satoshi"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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
        "%{prj.name}/src"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "ST_PLATFORM_MSDOS",
            "ST_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
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
        "Satoshi/src"
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