set_project("dawn2")
set_version("1.0.0")
set_languages("c17","cxx17")

local platform
if is_arch("arm.*") then
    platform = "mac64"
else
    platform = "win64"
end

local vendor = {
    sdl2 = os.scriptdir() .. "/vendor/sdl2/" .. platform
}

target("dawn")
    set_kind("binary")
    set_extension(".app")
    add_rules("mode.debug", "mode.release")
    add_files("src/**.cpp")
    add_includedirs(vendor["sdl2"] .. "/include")
    add_linkdirs(vendor["sdl2"] .. "/lib")
    add_links("SDL2_image", "SDL2_mixer", "SDL2_ttf", "SDL2", "SDL2main")
    add_syslinks("m", "iconv", "objc")
    -- add_frameworks(
    --     "CoreAudio",
    --     "AudioToolbox",
    --     "CoreHaptics", -- weak
    --     "GameController", -- weak
    --     "ForceFeedback",
    --     "CoreVideo",
    --     "Cocoa",
    --     "Carbon",
    --     "IOKit",
    --     "QuartzCore", -- weak
    --     "Metal") -- weak