#pragma once

#include <windows.h>
#include <inttypes.h>
#include "HelperFunctions.h"

struct mm_info_s {
    HWND* MainWindow;
    int version;
    uint32_t init_hook[2];
    uint32_t draw_hook[2];
};
extern struct mm_info_s mm_info;

void FindMMVersion();
