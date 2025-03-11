CC		:=	clang
CXX		:=	clang++

OPT_F	=	-fcrash-diagnostics  -fdirectives-only -fenable-matrix \
			-fstrict-float-cast-overflow -fstrict-vtable-pointers \
			-fstrict-enums -fsplit-lto-unit \
			-fstack-protector-strong -fvectorize

OPT_Fno	=	-fno-autolink -fno-builtin -fno-cxx-modules \
			-fno-convergent-functions -fno-coverage-mapping \
			-fno-experimental-library -fno-exceptions \
			-fno-strict-aliasing

OPT_M	=	-mavx -mavx2 -msse -msse4.2 \
			-mlvi-cfi -mseses \
			-mstack-arg-probe -mstackrealign

OPT_Mno	=	-mno-sse2 -mno-sse3
			
OPT_W	=	-Wall -Wabi -Wclass-conversion -Wdeprecated -Wformat-security \
			-Wunused -Wuninitialized -Wextra

OPT_Wno	=	-Wno-pedantic

OPT_Wl	=	-Wl",/DYNAMICBASE" -Wl",/LARGEADDRESSAWARE" -Wl",/NODEFAULTLIB" \
			-Wl",/ENTRY:wWinMain" -Wl",/SUBSYSTEM:WINDOWS"

OPT_Uni	=	

OPT		=	$(OPT_F) $(OPT_Fno) $(OPT_M) $(OPT_Mno) \
			$(OPT_W) $(OPT_Wno) $(OPT_Wl) $(OPT_Uni)

CC_Com	=	$(CC) $(OPT)
CX_Com	=	$(CXX) $(OPT)

