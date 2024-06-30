#pragma once

#define MOUSE_SENSITY_DEFAULT 0.7

void app_mouse_install();

float app_mouse_get_sensity(void);
void app_mouse_set_sensity(float sensity);
uint8_t app_mouse_get_act();
