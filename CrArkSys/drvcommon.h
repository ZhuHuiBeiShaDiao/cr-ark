#pragma once


#define _ANSISTRING(text) #text
#define ANSISTRING(text) _ANSISTRING(text)

#define _WIDESTRING(text) L##text
#define WIDESTRING(text) _WIDESTRING(text)

#define PRESET_UNICODE_STRING(symbol, buffer) \
        UNICODE_STRING symbol = \
            { \
            sizeof(WIDESTRING(buffer)) - sizeof(WCHAR), \
            sizeof(WIDESTRING(buffer)), \
            WIDESTRING(buffer) \
            };

#define CREATE_XVER(maj,min,build) maj ## , ## min ## , 0, ## build
#define CREATE_FVER(maj,min,build) maj ## . ## min ## .0. ## build
#define CREATE_PVER(maj,min,build) maj ## . ## min

#if DBG
	#ifdef ADVANCED_DEBUG
	#define DebugPrint DbgPrint("[%s] %s (line: %d)\n", __##FILE##__, __##FUNCTION##__, __##LINE##__); DbgPrint
	#else
	#define DebugPrint DbgPrint
	#endif
#else
#define DebugPrint /##/DbgPrint
#endif
