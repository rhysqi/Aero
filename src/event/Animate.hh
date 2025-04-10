#ifndef AERO_SRC_EVENT_ANIMATE_HH
#define AERO_SRC_EVENT_ANIMATE_HH

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>

VOID Linear(FLOAT fSpeed);

VOID EaseIn_Miliseconds(FLOAT fSpeed, FLOAT fAcceleration, UINT uIntervalMS);
VOID EaseOut_Miliseconds(FLOAT fSpeed, FLOAT fAcceleration, UINT uIntervalMS);
VOID EaseInOut_Miliseconds(FLOAT fSpeed, FLOAT fAcceleration, UINT uIntervalMS);

VOID BounceIn_Miliseconds(FLOAT fSpeed, FLOAT fBounceFactor, UINT uIntervalMS);
VOID BounceOut_Miliseconds(FLOAT fSpeed, FLOAT fBounceFactor, UINT uIntervalMS);
VOID BounceInOut_Miliseconds(FLOAT fSpeed, FLOAT fBounceFactor, UINT uIntervalMS);

VOID ElasticIn_Miliseconds(FLOAT fSpeed, FLOAT fElasticFactor, UINT uIntervalMS);
VOID ElasticOut_Miliseconds(FLOAT fSpeed, FLOAT fElasticFactor, UINT uIntervalMS);
VOID ElasticInOut_Miliseconds(FLOAT fSpeed, FLOAT fElasticFactor, UINT uIntervalMS);

VOID BackIn_Miliseconds(FLOAT fSpeed, FLOAT fBackFactor, UINT uIntervalMS);
VOID BackOut_Miliseconds(FLOAT fSpeed, FLOAT fBackFactor, UINT uIntervalMS);
VOID BackInOut_Miliseconds(FLOAT fSpeed, FLOAT fBackFactor, UINT uIntervalMS);

VOID SineIn_Miliseconds(FLOAT fSpeed, FLOAT fSineFactor, UINT uIntervalMS);
VOID SineOut_Miliseconds(FLOAT fSpeed, FLOAT fSineFactor, UINT uIntervalMS);
VOID SineInOut_Miliseconds(FLOAT fSpeed, FLOAT fSineFactor, UINT uIntervalMS);

#endif /* defined(_WIN32) || defined(_WIN64) */
#endif /* AERO_SRC_EVENT_ANIMATE_HH */