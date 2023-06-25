


idf_component_register( 
    SRC_DIRS "src" "ui_apps/fonts" "ui_apps/imgs" "ui_apps/src" "interfaces/src" "data/src" "bottom_apps/src" 
    # "ui_apps/apps" 
    INCLUDE_DIRS "include" "ui_apps/include" "interfaces/include" "bottom_apps/include" "data/inc" 
    # REQUIRES driver lvgl interfaces esp_lcd spi_flash drivers
)
