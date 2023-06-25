


idf_component_register( 
    #底层路径添加
    SRC_DIRS        "src" "ui_apps/fonts" "ui_apps/imgs" "ui_apps/src" "interfaces/src" "data/src" 
    INCLUDE_DIRS    "inc" "ui_apps/inc" "interfaces/inc" "data/inc" 

    #APP路径添加
    SRC_DIRS        "bottom_apps/btn_event_app" "bottom_apps/hc32_trans_app" 
                    "bottom_apps/usb_trans_app" "bottom_apps/system_app" 
                    "ui_apps/test_app"

    INCLUDE_DIRS    "bottom_apps/btn_event_app"  "bottom_apps/hc32_trans_app"  
                    "bottom_apps/usb_trans_app"  "bottom_apps/system_app" 
                    "ui_apps/test_app"
)


