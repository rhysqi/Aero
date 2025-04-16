include tools/build.mk
include tools/config.mk
include tools/lib.mk

.PHONY: clean buildworld buildworld-test

buildworld: setup-build
	@echo Building Project ...

buildworld-test:
	@echo Building Test ...
	$(CX_Com) -c $(LIB_System_Win32)