#ifndef AERO_SRC_EVENT_ANIMATE_HH
#define AERO_SRC_EVENT_ANIMATE_HH

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>

typedef struct {
	FLOAT fSpeed;
	FLOAT fEasingFactor;
	UINT uDuration;
	UINT uInterval;
} Aero_Easing_Data_t, *pAero_Easing_Data_t;

PVOID Linear(FLOAT fSpeed);

PVOID EaseIn_Miliseconds(pAero_Easing_Data_t Easing_Data);
PVOID EaseOut_Miliseconds(pAero_Easing_Data_t Easing_Data);
PVOID EaseInOut_Miliseconds(pAero_Easing_Data_t Easing_Data);

PVOID BounceIn_Miliseconds(pAero_Easing_Data_t Easing_Data);
PVOID BounceOut_Miliseconds(pAero_Easing_Data_t Easing_Data);
PVOID BounceInOut_Miliseconds(pAero_Easing_Data_t Easing_Data);

PVOID ElasticIn_Miliseconds(pAero_Easing_Data_t Easing_Data);
PVOID ElasticOut_Miliseconds(pAero_Easing_Data_t Easing_Data);
PVOID ElasticInOut_Miliseconds(pAero_Easing_Data_t Easing_Data);

PVOID BackIn_Miliseconds(pAero_Easing_Data_t Easing_Data);
PVOID BackOut_Miliseconds(pAero_Easing_Data_t Easing_Data);
PVOID BackInOut_Miliseconds(pAero_Easing_Data_t Easing_Data);

PVOID SineIn_Miliseconds(pAero_Easing_Data_t Easing_Data);
PVOID SineOut_Miliseconds(pAero_Easing_Data_t Easing_Data);
PVOID SineInOut_Miliseconds(pAero_Easing_Data_t Easing_Data);

PVOID ExponentialIn_Miliseconds(pAero_Easing_Data_t Easing_Data);
PVOID ExponentialOut_Miliseconds(pAero_Easing_Data_t Easing_Data);
PVOID ExponentialInOut_Miliseconds(pAero_Easing_Data_t Easing_Data);

#endif /* defined(_WIN32) || defined(_WIN64) */
#endif /* AERO_SRC_EVENT_ANIMATE_HH */