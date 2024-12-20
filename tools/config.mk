# C/C++ Standard settings
CXX			=	clang++
CXX_LIB		=	${CXX} -c
CXSTD		=	-std=c++11 -stdlib=libc++ -nostdlib++

CXFLAGS		=	-O3
CXFLAGS		+=	-fstack-protector-strong -fvectorize -fslp-vectorize \
				-fcoroutines -fstrict-enums -fsplit-lto-unit \
				-fstrict-float-cast-overflow -fstrict-vtable-pointers \
				-fconvergent-functions -fenable-matrix

CXFLAGS		+=	-fno-fixed-point -fno-strict-aliasing -fno-exceptions \
				-fno-spell-checking -fno-rtti -fno-rtti-data -fno-access-control \
				-fno-addrsig -fno-autolink

CXFLAGS		+=	-mstack-arg-probe -mstackrealign -msoft-float \
				-mlvi-cfi -mlvi-hardening

CXFLAGS		+=	-Wall -Wabi -WClass-convertion -WDeprecated -Wformat-security \
				-Wc++11-compat -Wunused -Wuninitialized -Wextra

CXFLAGS		+=	-Wno-pedantic
CXFLAGS		+=	-v -H

# Win32
CXARGS_W32	=	-mwindows -m64 -D_WIN32 \
				-Wl",/DYNAMICBASE:YES" -Wl",/LARGEADDRESSNAME:YES"