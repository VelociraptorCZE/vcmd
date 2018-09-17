/* vcmd v0.4
 * Copyright (C) Simon Raichl 2018
 * MIT License
 * Use this as you want, share it as you want, do basically whatever you want with this :)
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#include <string.h>
#include <dirent.h> 

#include "config.h"
#include "sub.h"
#include "commands.h"


#include "core.h"
