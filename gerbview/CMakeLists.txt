add_definitions(-DGERBVIEW)

###
# Includes
###

include_directories(BEFORE ${INC_BEFORE})
include_directories(
    ../pcbnew
    dialogs
    ../3d-viewer
    ../polygon
    ${INC_AFTER}
    )


###
# Sources
###

set(DIALOGS_SRCS
    dialogs/gerbview_dialog_display_options_frame_base.cpp
    dialogs/gerbview_dialog_display_options_frame.cpp
    dialogs/dialog_layers_select_to_pcb_base.cpp
    dialogs/dialog_print_using_printer.cpp
    dialogs/dialog_print_using_printer_base.cpp
    dialogs/dialog_select_one_pcb_layer.cpp
    dialogs/dialog_show_page_borders.cpp
    dialogs/dialog_show_page_borders_base.cpp
    )

set(GERBVIEW_SRCS
    block.cpp
    class_am_param.cpp
    class_aperture_macro.cpp
    class_DCodeSelectionbox.cpp
    class_gbr_screen.cpp
    class_gbr_layout.cpp
    class_GERBER.cpp
    class_gerber_draw_item.cpp
    class_gerbview_layer_widget.cpp
    class_gbr_layer_box_selector.cpp
    controle.cpp
    dcode.cpp
    draw_gerber_screen.cpp
    events_called_functions.cpp
    excellon_read_drill_file.cpp
    export_to_pcbnew.cpp
    files.cpp
    gerbview.cpp
    gerbview_config.cpp
    gerbview_frame.cpp
    hotkeys.cpp
    initpcb.cpp
    locate.cpp
    menubar.cpp
    onleftclick.cpp
    onrightclick.cpp
    pcbplot.cpp
    readgerb.cpp
    rs274_read_XY_and_IJ_coordinates.cpp
    rs274d.cpp
    rs274x.cpp
    select_layers_to_pcb.cpp
    toolbars_gerber.cpp
    )

###
# We need some extra sources from common and pcbnew
###
set(GERBVIEW_EXTRA_SRCS
    ../common/base_screen.cpp
    ../common/base_units.cpp
    ../common/class_layer_box_selector.cpp
    ../common/class_page_info.cpp
    ../pcbnew/layer_widget.cpp
    ../pcbnew/printout_controler.cpp
)

###
# Windows resource file
###
if(WIN32)
    if(MINGW)
        # GERBVIEW_RESOURCES variable is set by the macro.
        mingw_resource_compiler(gerbview)
    else(MINGW)
        set(GERBVIEW_RESOURCES gerbview.rc)
    endif(MINGW)
endif(WIN32)

###
# Apple resource files
###
if(APPLE)
    set(GERBVIEW_RESOURCES gerbview.icns gerbview_doc.icns)
    set_source_files_properties("${CMAKE_CURRENT_SOURCE_DIR}/gerbview.icns"
                                PROPERTIES MACOSX_PACKAGE_LOCATION Resources)
    set_source_files_properties("${CMAKE_CURRENT_SOURCE_DIR}/gerbview_doc.icns"
                                PROPERTIES MACOSX_PACKAGE_LOCATION Resources)
    set(MACOSX_BUNDLE_ICON_FILE gerbview.icns)
    set(MACOSX_BUNDLE_GUI_IDENTIFIER org.kicad-eda.gerbview)
endif(APPLE)

###
# Create the gerbview executable
###
add_executable(gerbview WIN32 MACOSX_BUNDLE
               ${GERBVIEW_SRCS}
               ${DIALOGS_SRCS}
               ${GERBVIEW_EXTRA_SRCS}
               ${GERBVIEW_RESOURCES})

###
# Set properties for APPLE on gerbview target
###
if(APPLE)
    set_target_properties(gerbview PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
endif(APPLE)

###
# Link executable target gerbview with correct libraries
###
target_link_libraries(gerbview common polygon bitmaps
                      ${OPENGL_LIBRARIES}
                      ${wxWidgets_LIBRARIES}
                      ${GDI_PLUS_LIBRARIES})

###
# Add gerbview as install target
###
install(TARGETS gerbview
        DESTINATION ${KICAD_BIN}
        COMPONENT binary)
