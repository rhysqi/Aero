# Build setup
BIN_DIR		:=	bin
BUILD_DIR	:=	build

.PHONY: setup-build
setup-build:
	@echo Setting up setup directory...
	
	@if exist "$(BIN_DIR)" ( \
		@echo Directory $(BIN_DIR) already exists. \
	) else ( \
		@echo Creating directory $(BIN_DIR)... && \
		@mkdir $(BIN_DIR) \
	)

	@if exist "$(BUILD_DIR)" ( \
		@echo Directory $(BUILD_DIR) already exists. \
	) else ( \
		@echo Creating directory $(BUILD_DIR)... && \
		@mkdir $(BUILD_DIR) \
	)
