add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = "."})
set_languages("c23")
set_warnings("all")

target("PWScript")
    set_kind("binary")
    -- add includes
    add_includedirs("include")
    -- add files
    add_headerfiles("src/**.h")
    add_files("src/**.c")
    -- output
    set_targetdir("build/")
    -- only debug
    set_symbols("debug")
    set_optimize("none")
    set_strip("none")

