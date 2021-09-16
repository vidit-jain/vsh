#ifndef VSH_SYSTEMINFO_H
#define VSH_SYSTEMINFO_H
#include <limits.h>
#include <pwd.h>
#include <stdio.h>
#include <unistd.h>

#include "../../globals.h"
#include "../processor/errorHandling.h"
#include "string.h"

void setUsername();
void setSystemName();
String *setHomePath();
String *setCurrentPath();
unsigned int getDepth(String path);
unsigned int inHomeDirectory(String *path);
void shortenPath(String **shortenedPath, String *path);
void expandPath(String **shortenedPath, String *path);
void goToCurrentPath();

#endif // VSH_SYSTEMINFO_H
