LIB_Filter			=	$(wildcard $(1)/*.cxx)

LIB_Audio_Win32		:=	$(call LIB_Filter, lib/audio)
LIB_Codec_Win32		:=	$(call LIB_Filter, lib/codec)
LIB_Graphics_Win32	:=	$(call LIB_Filter, lib/graphics)
LIB_System_Win32	:=	$(call LIB_Filter, lib/system)
LIB_Window_Win32	:=	$(call LIB_Filter, lib/window)

.PHONY: static-lib-Win64 dynamic-lib-Win64

# Build static library
static-lib-Win64:
	@echo Building static library ...

# Build dynamic library
dynamic-lib-Win64:
	@echo Building dynamic library ...