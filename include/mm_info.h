#pragma once

#include <windows.h>
#include <inttypes.h>
#include "HelperFunctions.h"

struct mm_info_s {
    HWND* MainWindow;
    int version;
};
extern struct mm_info_s mm_info;

void FindMMVersion();
