include tools/config.mk
include tools/lib.mk
include tools/setup.mk

.PHONY: buildware-win32-elf  buildware-win32-lib
buildware-win32-lib: setup-win32
	@echo Building Library ...
	$(CXX)

buildware-win32-elf: buildware-win32-lib
	@echo Building ELF
	$(CXX)
