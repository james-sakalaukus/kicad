add_definitions(-DPCBNEW)

if (KICAD_SCRIPTING OR KICAD_SCRIPTING_MODULES)
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/scripting)
    find_package(SWIG REQUIRED)
    include(${SWIG_USE_FILE})
endif(KICAD_SCRIPTING OR KICAD_SCRIPTING_MODULES)


###
# Includes
###
include_directories(BEFORE ${INC_BEFORE})
include_directories(
    ./dialogs
    ./autorouter
    ../3d-viewer
    ../common
    ${Boost_INCLUDE_DIR}
    ../polygon
    ../common/dialogs
    ./scripting
    ${INC_AFTER}
    )


###
# Sources
#
set(PCBNEW_DIALOGS
    dialogs/dialog_block_options_base.cpp
    dialogs/dialog_cleaning_options_base.cpp
    dialogs/dialog_cleaning_options.cpp
    dialogs/dialog_copper_zones.cpp
    dialogs/dialog_copper_zones_base.cpp
    dialogs/dialog_design_rules.cpp
    dialogs/dialog_design_rules_base.cpp
    dialogs/dialog_dimension_editor_base.cpp
    dialogs/dialog_display_options.cpp
    dialogs/dialog_display_options_base.cpp
    dialogs/dialog_drc_base.cpp
    dialogs/dialog_drc.cpp
    dialogs/dialog_edit_module_for_BoardEditor.cpp
    dialogs/dialog_edit_module_for_BoardEditor_base.cpp
    dialogs/dialog_edit_module_for_Modedit_base.cpp
    dialogs/dialog_edit_module_for_Modedit.cpp
    dialogs/dialog_edit_module_text.cpp
    dialogs/dialog_edit_module_text_base.cpp
    dialogs/dialog_exchange_modules_base.cpp
    dialogs/dialog_export_vrml_base.cpp
    dialogs/dialog_export_vrml.cpp
    dialogs/dialog_find_base.cpp
    dialogs/dialog_find.cpp
    dialogs/dialog_fp_lib_table_base.cpp
    dialogs/dialog_fp_lib_table.cpp
    dialogs/dialog_freeroute_exchange.cpp
    dialogs/dialog_freeroute_exchange_base.cpp
    dialogs/dialog_gendrill.cpp
    dialogs/dialog_gendrill_base.cpp
    dialogs/dialog_gen_module_position_file_base.cpp
    dialogs/dialog_general_options.cpp
    dialogs/dialog_general_options_BoardEditor_base.cpp
    dialogs/dialog_global_edit_tracks_and_vias.cpp
    dialogs/dialog_global_edit_tracks_and_vias_base.cpp
    dialogs/dialog_global_modules_fields_edition.cpp
    dialogs/dialog_global_modules_fields_edition_base.cpp
    dialogs/dialog_global_pads_edition_base.cpp
    dialogs/dialog_graphic_items_options.cpp
    dialogs/dialog_graphic_items_options_base.cpp
    dialogs/dialog_graphic_item_properties.cpp
    dialogs/dialog_graphic_item_properties_base.cpp
    dialogs/dialog_graphic_item_properties_for_Modedit.cpp
    dialogs/dialog_global_deletion.cpp
    dialogs/dialog_global_deletion_base.cpp
    dialogs/dialog_keepout_area_properties.cpp
    dialogs/dialog_keepout_area_properties_base.cpp
    dialogs/dialog_layers_setup.cpp
    dialogs/dialog_layers_setup_base.cpp
    dialogs/dialog_netlist.cpp
    dialogs/dialog_netlist_fbp.cpp
    dialogs/dialog_pcb_text_properties.cpp
    dialogs/dialog_pcb_text_properties_base.cpp
    dialogs/dialog_non_copper_zones_properties_base.cpp
    dialogs/dialog_pad_properties.cpp
    dialogs/dialog_pad_properties_base.cpp
    dialogs/dialog_pcbnew_config_libs_and_paths.cpp
    dialogs/dialog_pcbnew_config_libs_and_paths_fbp.cpp
    dialogs/dialog_plot_base.cpp
    dialogs/dialog_plot.cpp
    dialogs/dialog_print_for_modedit.cpp
    dialogs/dialog_print_for_modedit_base.cpp
    dialogs/dialog_print_using_printer.cpp
    dialogs/dialog_print_using_printer_base.cpp
    dialogs/dialog_orient_footprints.cpp
    dialogs/dialog_orient_footprints_base.cpp
    dialogs/dialog_mask_clearance.cpp
    dialogs/dialog_mask_clearance_base.cpp
    dialogs/dialog_SVG_print.cpp
    dialogs/dialog_SVG_print_base.cpp
    dialogs/dialog_set_grid_base.cpp
    footprint_wizard.cpp
    footprint_wizard_frame.cpp
    dialogs/dialog_footprint_wizard_list_base.cpp
    dialogs/dialog_footprint_wizard_list.cpp
    )

set(PCBNEW_AUTOROUTER_SRCS
    autorouter/automove.cpp
    autorouter/autoplac.cpp
    autorouter/autorout.cpp
    autorouter/routing_matrix.cpp
    autorouter/dist.cpp
    autorouter/queue.cpp
    autorouter/solve.cpp
    autorouter/graphpcb.cpp
    autorouter/work.cpp
    )

set(PCBNEW_CLASS_SRCS
    tool_modview.cpp
    modview.cpp
    modview_frame.cpp
    pcbframe.cpp
    attribut.cpp
    board_items_to_polygon_shape_transform.cpp
    board_undo_redo.cpp
    block.cpp
    block_module_editor.cpp
    build_BOM_from_board.cpp
    class_pcb_layer_widget.cpp
    class_pcb_layer_box_selector.cpp
    clean.cpp
    connect.cpp
    controle.cpp
    dimension.cpp
    cross-probing.cpp
    deltrack.cpp
    ${PCBNEW_DIALOGS}
    dragsegm.cpp
    drc.cpp
    drc_clearance_test_functions.cpp
    drc_marker_functions.cpp
    edgemod.cpp
    edit.cpp
    editedge.cpp
    editmod.cpp
    editrack.cpp
    editrack-part2.cpp
    edit_pcb_text.cpp
    edit_track_width.cpp
    edtxtmod.cpp
    event_handlers_tracks_vias_sizes.cpp
    export_gencad.cpp
    export_vrml.cpp
    files.cpp
    gen_drill_report_files.cpp
    gen_modules_placefile.cpp
    gendrill_Excellon_writer.cpp
    globaleditpad.cpp
    highlight.cpp
    hotkeys.cpp
    hotkeys_board_editor.cpp
    hotkeys_module_editor.cpp
    initpcb.cpp
    layer_widget.cpp
    librairi.cpp
    loadcmp.cpp
    magnetic_tracks_functions.cpp
    menubar_modedit.cpp
    menubar_pcbframe.cpp
    minimun_spanning_tree.cpp
    mirepcb.cpp
    modedit.cpp
    modedit_onclick.cpp
    modeditoptions.cpp
    modedit_undo_redo.cpp
    moduleframe.cpp
    modules.cpp
    move-drag_pads.cpp
    move_or_drag_track.cpp
    muonde.cpp
    muwave_command.cpp
    netlist.cpp
    netlist_reader_common.cpp
    netlist_reader_firstformat.cpp
    netlist_reader_kicad.cpp
    onleftclick.cpp
    onrightclick.cpp
    pad_edition_functions.cpp
    pcbnew.cpp
    pcbnew_config.cpp
    pcbplot.cpp
    plot_board_layers.cpp
    plot_brditems_plotter.cpp
    print_board_functions.cpp
    printout_controler.cpp
    ratsnest.cpp
    set_grid.cpp
    specctra.cpp
    specctra_export.cpp
    specctra_import.cpp
    specctra_keywords.cpp
    swap_layers.cpp
    tool_modedit.cpp
    tool_onrightclick.cpp
    tool_pcb.cpp
    toolbars_update_user_interface.cpp
    tracepcb.cpp
    tr_modif.cpp
    xchgmod.cpp
    zones_convert_brd_items_to_polygons_with_Boost.cpp
    zones_convert_to_polygons_aux_functions.cpp
    zones_by_polygon.cpp
    zones_by_polygon_fill_functions.cpp
    zone_filling_algorithm.cpp
    zones_functions_for_undo_redo.cpp
    zones_non_copper_type_functions.cpp
    zones_polygons_insulated_copper_islands.cpp
    zones_polygons_test_connections.cpp
    zones_test_and_combine_areas.cpp
    class_footprint_wizard.cpp
    )

set(PCBNEW_SRCS ${PCBNEW_AUTOROUTER_SRCS} ${PCBNEW_CLASS_SRCS} ${PCBNEW_DIALOGS})

###
# We need some extra sources from common
###
set(PCBNEW_COMMON_SRCS
    ../common/dialogs/dialog_page_settings.cpp
    ../common/base_units.cpp
    )

##
# Scripting sources
##
set(PCBNEW_SCRIPTING_DIALOGS
    dialogs/dialog_scripting_base.cpp
    dialogs/dialog_scripting.cpp
    )


set(PCBNEW_SCRIPTING_PYTHON_HELPERS
    ../scripting/wx_python_helpers.cpp
    ../scripting/python_scripting.cpp
    scripting/pcbnew_scripting_helpers.cpp
    scripting/pcbnew_footprint_wizards.cpp
    )

if (KICAD_SCRIPTING)
    set(PCBNEW_SCRIPTING_SRCS
        ${PCBNEW_SCRIPTING_DIALOGS}
        pcbnew_wrap.cxx
        ${PCBNEW_SCRIPTING_PYTHON_HELPERS}
    )
endif(KICAD_SCRIPTING)

##
# Scripting build
##

if (KICAD_SCRIPTING OR KICAD_SCRIPTING_MODULES)

    set(SWIG_FLAGS -I${CMAKE_CURRENT_SOURCE_DIR}/../.. -I${CMAKE_CURRENT_SOURCE_DIR} -I${CMAKE_CURRENT_SOURCE_DIR}/../include -I${CMAKE_CURRENT_SOURCE_DIR}/../scripting )
    if (DEBUG)
        set(SWIG_FLAGS ${SWIG_FLAGS} -DDEBUG)
    endif()

    # collect CFLAGS , and pass them to swig later

    get_directory_property( DirDefs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} COMPILE_DEFINITIONS )
    foreach( d ${DirDefs} )
        set(SWIG_FLAGS ${SWIG_FLAGS} -D${d} )
    endforeach()

    # check if we have IO_MGR and KICAD_PLUGIN available
    if ( USE_NEW_PCBNEW_LOAD OR USE_NEW_PCBNEW_SAVE )
        set(SWIG_FLAGS ${SWIG_FLAGS} -DBUILD_WITH_PLUGIN)
    endif(USE_NEW_PCBNEW_LOAD OR USE_NEW_PCBNEW_SAVE)

    if ( USE_PCBNEW_NANOMETRES )
        set(SWIG_FLAGS ${SWIG_FLAGS} -DUSE_PCBNEW_NANOMETRES)
    endif( USE_PCBNEW_NANOMETRES )

endif(KICAD_SCRIPTING OR KICAD_SCRIPTING_MODULES)

if (KICAD_SCRIPTING)

    set(SWIG_OPTS -python -c++ -outdir ${CMAKE_CURRENT_BINARY_DIR} ${SWIG_FLAGS} )

    add_custom_command( OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/pcbnew_wrap.cxx
        DEPENDS scripting/pcbnew.i
        DEPENDS scripting/board.i
        DEPENDS scripting/board_item.i
        DEPENDS scripting/module.i
        DEPENDS scripting/plugins.i
        DEPENDS scripting/units.i
        DEPENDS ../scripting/dlist.i
        DEPENDS ../scripting/kicad.i
        DEPENDS ../scripting/wx.i
        DEPENDS ../scripting/kicadplugins.i

        COMMAND ${SWIG_EXECUTABLE} ${SWIG_OPTS} -o ${CMAKE_CURRENT_BINARY_DIR}/pcbnew_wrap.cxx  scripting/pcbnew.i
        COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/../scripting/fixswigimports.py ${CMAKE_CURRENT_BINARY_DIR}/pcbnew.py
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )

endif(KICAD_SCRIPTING)

###
# _pcbnew DLL/DSO file creation
###

if ((KICAD_SCRIPTING OR KICAD_SCRIPTING_MODULES) AND NOT WIN32 AND NOT APPLE)
    set ( PCBNEW_EXTRA_LIBS "rt" )
endif()


if (KICAD_SCRIPTING_MODULES)

    set(CMAKE_SWIG_FLAGS ${SWIG_FLAGS})
    set_source_files_properties(scripting/pcbnew.i PROPERTIES CPLUSPLUS ON)
    swig_add_module(pcbnew python scripting/pcbnew.i ${PCBNEW_SCRIPTING_PYTHON_HELPERS} ${PCBNEW_SRCS} ${PCBNEW_COMMON_SRCS})
    swig_link_libraries(pcbnew
        3d-viewer
        pcbcommon
        common
        pcad2kicadpcb
        polygon
        bitmaps
        ${wxWidgets_LIBRARIES}
        ${OPENGL_LIBRARIES}
        ${GDI_PLUS_LIBRARIES}
        ${PYTHON_LIBRARIES}
        ${PCBNEW_EXTRA_LIBS}
        )

endif (KICAD_SCRIPTING_MODULES)

###
# Windows resource file
###
if(WIN32)
    if(MINGW)
        # PCBNEW_RESOURCES variable is set by the macro.
        mingw_resource_compiler(pcbnew)
    else(MINGW)
        set(PCBNEW_RESOURCES pcbnew.rc)
    endif(MINGW)
endif(WIN32)

###
# Set properties for APPLE on pcbnew target
###
if(APPLE)
    set(PCBNEW_RESOURCES pcbnew.icns pcbnew_doc.icns)
    set_source_files_properties("${CMAKE_CURRENT_SOURCE_DIR}/pcbnew.icns"
                                PROPERTIES MACOSX_PACKAGE_LOCATION Resources)
    set_source_files_properties("${CMAKE_CURRENT_SOURCE_DIR}/pcbnew_doc.icns"
                                PROPERTIES MACOSX_PACKAGE_LOCATION Resources)
    set(MACOSX_BUNDLE_ICON_FILE pcbnew.icns)
    set(MACOSX_BUNDLE_GUI_IDENTIFIER org.kicad-eda.pcbnew)
    set(MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
endif(APPLE)

# Create a C++ compilable string initializer containing html text into a *.h file:
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/dialogs/dialog_freeroute_exchange_help_html.h
    COMMAND ${CMAKE_COMMAND}
        -DinputFile=${CMAKE_CURRENT_SOURCE_DIR}/dialogs/dialog_freeroute_exchange_help.html
        -DoutputFile=${CMAKE_CURRENT_SOURCE_DIR}/dialogs/dialog_freeroute_exchange_help_html.h
        -P ${CMAKE_MODULE_PATH}/Html2C.cmake
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/dialogs/dialog_freeroute_exchange_help.html
    COMMENT "creating ${CMAKE_CURRENT_SOURCE_DIR}/dialogs/dialog_freeroute_exchange_help_html.h
       from ${CMAKE_CURRENT_SOURCE_DIR}/dialogs/dialog_freeroute_exchange_help.html"
    )

set_source_files_properties( dialogs/dialog_freeroute_exchange.cpp
    PROPERTIES
        OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/dialogs/dialog_freeroute_exchange_help_html.h
    )


# auto-generate specctra_lexer.h and specctra_keywords.cpp
make_lexer(
    ${CMAKE_CURRENT_SOURCE_DIR}/specctra.keywords
    ${CMAKE_CURRENT_SOURCE_DIR}/specctra_lexer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/specctra_keywords.cpp
    DSN
    )


###
# Create the pcbnew executable
###
add_executable(pcbnew WIN32 MACOSX_BUNDLE
    ${PCBNEW_SRCS}
    ${PCBNEW_COMMON_SRCS}
    ${PCBNEW_SCRIPTING_SRCS}
    ${PCBNEW_RESOURCES}
    )

###
# Set properties for APPLE on pcbnew target
###
if(APPLE)
    set_target_properties(pcbnew PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
endif(APPLE)

###
# Link executable target pcbnew with correct libraries
###

target_link_libraries(pcbnew
    3d-viewer
    pcbcommon
    common
    pcad2kicadpcb
    polygon
    bitmaps
    ${wxWidgets_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${GDI_PLUS_LIBRARIES}
    ${PYTHON_LIBRARIES}
    ${PCBNEW_EXTRA_LIBS}
    )

###
# Add pcbnew as install target
###
install(TARGETS pcbnew
    DESTINATION ${KICAD_BIN}
    COMPONENT binary)


if(KICAD_SCRIPTING)
    add_custom_target(FixSwigImportsScripting ALL
        COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/../scripting/fixswigimports.py ${CMAKE_CURRENT_BINARY_DIR}/pcbnew.py
        DEPENDS pcbnew
        COMMENT "Fixing swig_import_helper in Kicad scripting"
        )

    install(FILES ${CMAKE_BINARY_DIR}/pcbnew/pcbnew.py DESTINATION ${PYTHON_DEST})
endif(KICAD_SCRIPTING)

if (KICAD_SCRIPTING_MODULES)
    add_custom_target(FixSwigImportsModuleScripting ALL
        COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/../scripting/fixswigimports.py ${CMAKE_CURRENT_BINARY_DIR}/pcbnew.py
        DEPENDS _pcbnew
        COMMENT "Fixing swig_import_helper in Kicad scripting modules"
        )

    install(FILES ${CMAKE_BINARY_DIR}/pcbnew/pcbnew.py DESTINATION ${PYTHON_DEST})

    if (WIN32)
        install(FILES ${CMAKE_BINARY_DIR}/pcbnew/_pcbnew.pyd DESTINATION ${PYTHON_DEST})
    else(WIN32)
        install(FILES ${CMAKE_BINARY_DIR}/pcbnew/_pcbnew.so DESTINATION ${PYTHON_DEST})
    endif(WIN32)

endif(KICAD_SCRIPTING_MODULES)


# The specctra test fails to build properly using MS Visual Studio.
if(NOT MSVC)
    # This one gets made only when testing.
    add_executable(specctra_test EXCLUDE_FROM_ALL specctra_test.cpp specctra.cpp)
    target_link_libraries(specctra_test common ${wxWidgets_LIBRARIES})
endif(NOT MSVC)

# This one gets made only when testing.
add_executable(layer_widget_test WIN32 EXCLUDE_FROM_ALL
    layer_widget.cpp
    )
target_link_libraries(layer_widget_test common ${wxWidgets_LIBRARIES})
