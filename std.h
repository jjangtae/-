//std.h
#pragma once

#pragma comment (linker, "/subsystem:windows")

#include <Windows.h>
#include <tchar.h>
#include <vector>
#include <ctime>
using namespace std;

#include "resource.h"
#include "handler.h"


static POINTS start, end1;
static int shape = 0;
static int color = 0;