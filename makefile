include tools/build.mk
include tools/config.mk
include tools/lib.mk

.PHONY: clean buildworld

buildworld:
	@echo Building Project ...

buildworld-test:
	@echo Building Test ...

	$(CXX) \
	$(OPT_F) $(OPT_Fno) $(OPT_M) $(OPT_Mno) $(OPT_W) \
	$(OPT_Wno) $(OPT_Wl) $(OPT_Uni) \
	$(LIB_CXX) -o $(TARGET) $(SRC)