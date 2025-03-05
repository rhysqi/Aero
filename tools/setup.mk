# Build setup
BIN		:=	bin
BUILD	:=	build

.PHONY: setup-win32
setup-win32:
	# Check build folder
	@if not exist $(BUILD) ( \
		mkdir $(BUILD) & echo Directory $(BUILD) created. \
	) else ( \
		echo Directory $(BUILD) already exists. \
	)

	@if not exist $(BUILD)\\graphics ( \
		mkdir $(BUILD)\\graphics & echo Directory $(BUILD)\\graphics created. \
	) else ( \
		echo Directory $(BUILD)\\graphics already exists. \
	)

	@if not exist $(BUILD)\\system ( \
		mkdir $(BUILD)\\system & echo Directory $(BUILD)\\system created. \
	) else ( \
		echo Directory $(BUILD)\\system already exists. \
	)

	@if not exist $(BUILD)\\security ( \
		mkdir $(BUILD)\\security & echo Directory $(BUILD)\\security created. \
	) else ( \
		echo Directory $(BUILD)\\security already exists. \
	)

	# Check bin folder
	@if not exist $(BIN) ( \
		mkdir $(BIN) & echo Directory $(BIN) created. \
	) else ( \
		echo Directory $(BIN) already exists. \
	)

	@if not exist $(BIN)\\lib ( \
		mkdir $(BIN)\\lib & echo Directory $(BIN)\\lib created. \
	) else ( \
		echo Directory $(BIN)\\lib already exists. \
	)

setup-unix:
