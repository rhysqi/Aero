#ifndef AERO_MATH_HH
#define AERO_MATH_HH

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>

namespace Aero_Math {
	CONST FLOAT PI = 3.14159265358979323846f;

	namespace Geometry {
		
	}

	// Matrix definition
	namespace Matrix {
		PVOID Translate2D(PFLOAT fX, PFLOAT fY);
		PVOID Translate3D(PFLOAT fX, PFLOAT fY, PFLOAT fZ);

		PVOID Rotate2D(PFLOAT fDegreeX, PFLOAT fDegreeY);
		PVOID Rotate3D(PFLOAT fDegreeX, PFLOAT fDegreeY, PFLOAT fDegreeZ);

		PVOID Scale2D(PFLOAT fScaleX, PFLOAT fScaleY);
		PVOID Scale3D(PFLOAT fScaleX, PFLOAT fScaleY, PFLOAT fScaleZ);

		PVOID Transform2D(PFLOAT fX, PFLOAT fY, PFLOAT fDegree, PFLOAT fScaleX, PFLOAT fScaleY);
		PVOID Transform3D(PFLOAT fX, PFLOAT fY, PFLOAT fZ, PFLOAT fDegreeX, PFLOAT fDegreeY, FLOAT fDegreeZ, FLOAT fScaleX, FLOAT fScaleY, FLOAT fScaleZ);

		PVOID Inverse2D(PFLOAT fX, PFLOAT fY, PFLOAT fDegree, PFLOAT fScaleX, PFLOAT fScaleY);
		PVOID Inverse3D(PFLOAT fX, PFLOAT fY, PFLOAT fZ, PFLOAT fDegreeX, PFLOAT fDegreeY, FLOAT fDegreeZ, FLOAT fScaleX, FLOAT fScaleY, FLOAT fScaleZ);

		PVOID Identity2D(PFLOAT fX, PFLOAT fY);
		PVOID Identity3D(PFLOAT fX, PFLOAT fY, PFLOAT fZ);
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
		typedef struct {
			FLOAT fX;
			FLOAT fY;
			FLOAT fZ;
			FLOAT fW;
		} Quaternion_t, *pQuaternion_t;

		PVOID Add(pQuaternion_t q1, pQuaternion_t q2);
		PVOID Subtract(pQuaternion_t q1, pQuaternion_t q2);
		PVOID Multiply(pQuaternion_t q1, pQuaternion_t q2);
		PVOID Divide(pQuaternion_t q1, pQuaternion_t q2);

		PVOID Inverse(pQuaternion_t q);
		PVOID Normalize(pQuaternion_t q);
		PVOID Conjugate(pQuaternion_t q);

		PVOID DotProduct(pQuaternion_t q1, pQuaternion_t q2);
		PVOID CrossProduct(pQuaternion_t q1, pQuaternion_t q2);

		PVOID Interpolate(pQuaternion_t q1, pQuaternion_t q2, FLOAT fT);
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

		PVOID Add2D(pVector2D_t v1, pVector2D_t v2);
		PVOID Subtract2D(pVector2D_t v1, pVector2D_t v2);
		PVOID Multiply2D(pVector2D_t v1, pVector2D_t v2);
		PVOID Divide2D(pVector2D_t v1, pVector2D_t v2);

		PVOID DotProduct2D(pVector2D_t v1, pVector2D_t v2);
		PVOID CrossProduct2D(pVector2D_t v1, pVector2D_t v2);
		PVOID Normalize2D(pVector2D_t v);

		PVOID Add3D(pVector3D_t v1, pVector3D_t v2);
		PVOID Subtract3D(pVector3D_t v1, pVector3D_t v2);
		PVOID Multiply3D(pVector3D_t v1, pVector3D_t v2);
		PVOID Divide3D(pVector3D_t v1, pVector3D_t v2);

		PVOID DotProduct3D(pVector3D_t v1, pVector3D_t v2);
		PVOID CrossProduct3D(pVector3D_t v1, pVector3D_t v2);
		PVOID Normalize3D(pVector3D_t v);
	}
}

#endif /* defined(_WIN32) || defined(_WIN64) */
#endif /* AERO_MATH_HH */