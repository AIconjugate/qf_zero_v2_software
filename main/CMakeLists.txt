


idf_component_register( 
    #底层路径添加
    SRC_DIRS        "src"   "interfaces/src" "data/src" 
    INCLUDE_DIRS    "inc"  "interfaces/inc" "data/inc" 

    #APP路径添加
    SRC_DIRS        "bottom_apps/btn_event_app" "bottom_apps/hc32_trans_app" 
                    "bottom_apps/usb_trans_app" "bottom_apps/system_app" 
                    "bottom_apps_user/atmospheric_app" "bottom_apps_user/weather_app" 
                    "bottom_apps_user/mems_app" 
                    "ui_apps/test_app" "ui_apps/desktop" "ui_apps/watch_01"
                    "ui_apps/pop_cat_app" "ui_apps/muyu_app" "ui_apps/clock_app"
                    "ui_apps/setting_app" "ui_apps/yuanshen_app"

    INCLUDE_DIRS    "bottom_apps/btn_event_app"  "bottom_apps/hc32_trans_app"  
                    "bottom_apps/usb_trans_app"  "bottom_apps/system_app" 
                    "bottom_apps_user/atmospheric_app" "bottom_apps_user/weather_app" 
                    "bottom_apps_user/mems_app" 
                    "ui_apps/test_app" "ui_apps/desktop" "ui_apps/watch_01"
                    "ui_apps/pop_cat_app" "ui_apps/muyu_app" "ui_apps/clock_app"
                    "ui_apps/setting_app" "ui_apps/yuanshen_app"
                    
)


