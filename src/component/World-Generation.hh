#ifndef AERO_SRC_COMPONENT_WORLD_GENERATION_HH
#define AERO_SRC_COMPONENT_WORLD_GENERATION_HH

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>

typedef struct {
	INT32 Seed;
	
} Aero_World_Generation_t, *pAero_World_Generation_t;

VOID ProceduralGeneration();

#endif /* defined(_WIN32) || defined(_WIN64) */
#endif /* AERO_SRC_COMPONENT_WORLD_GENERATION_HH */