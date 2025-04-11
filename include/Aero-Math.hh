#ifndef AERO_MATH_HH
#define AERO_MATH_HH

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>

namespace Aero_Math {
	// Matrix definition
	namespace Matrix {
		PVOID Translate2D(FLOAT fX, FLOAT fY);
		PVOID Translate3D(FLOAT fX, FLOAT fY, FLOAT fZ);

		PVOID Rotate2D(FLOAT fDegreeX, FLOAT fDegreeY);
		PVOID Rotate3D(FLOAT fDegreeX, FLOAT fDegreeY, FLOAT fDegreeZ);

		PVOID Scale2D(FLOAT fScaleX, FLOAT fScaleY);
		PVOID Scale3D(FLOAT fScaleX, FLOAT fScaleY, FLOAT fScaleZ);

		PVOID Transform2D(FLOAT fX, FLOAT fY, FLOAT fDegree, FLOAT fScaleX, FLOAT fScaleY);
		PVOID Transform3D(FLOAT fX, FLOAT fY, FLOAT fZ, FLOAT fDegreeX, FLOAT fDegreeY, FLOAT fDegreeZ, FLOAT fScaleX, FLOAT fScaleY, FLOAT fScaleZ);
	}

	// Trigonometry definition
	namespace Trigonometry {
		FLOAT Sine(FLOAT fDegree);
		FLOAT Cosine(FLOAT fDegree);
		FLOAT Tangent(FLOAT fDegree);

		FLOAT ArcSine(FLOAT fValue);
		FLOAT ArcCosine(FLOAT fValue);
		FLOAT ArcTangent(FLOAT fValue);
	}

	// Quaternion definition
	namespace Quaternion {
		
	}

	// Vector definition
	namespace Vector {
		typedef struct {
			FLOAT fX;
			FLOAT fY;
		} Vector2D_t, *pVector2D_t;

		typedef struct {
			FLOAT fX;
			FLOAT fY;
			FLOAT fZ;
		} Vector3D_t, *pVector3D_t;

		pVector2D_t Add2D(pVector2D_t v1, pVector2D_t v2);
	}
}

#endif /* defined(_WIN32) || defined(_WIN64) */
#endif /* AERO_MATH_HH */