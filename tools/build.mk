include tools/config.mk
include tools/lib.mk
include tools/setup.mk

.PHONY: buildware-Win64-pe  buildware-Win64-lib
buildware-Win64-pe: buildware-Win64-lib
	@echo Building project ...

buildware-Win64-lib: setup-Win64
	@echo Building static Library ...
	