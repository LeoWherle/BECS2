add_rules("mode.debug", "mode.release")
   set_optimize("fastest")

add_requires("raylib")
set_languages("c++20")

add_rules("plugin.vsxmake.autoupdate")
add_rules("plugin.compile_commands.autoupdate")

target("game")
    set_kind("binary")
    add_files("src/*.cpp")
    add_packages("raylib")
    add_defines("DEBUG")
