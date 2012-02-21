/////////////////////////////////////////
//
// pocode application configuration
//
/////////////////////////////////////////


#include "poApplication.h"
#include "SeedFillApp.h"

poObject *createObjectForID(uint uid) {
	return new SeedFillApp();
}

void setupApplication() {
	applicationCreateWindow(0, WINDOW_TYPE_NORMAL, "SeedFill", 100, 100, 1024, 768);
}

void cleanupApplication() {
}