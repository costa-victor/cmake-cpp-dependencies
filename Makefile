BUILD_DIR := build
EXECUTABLE_NAME := app

install_all: clean installHeaderOnly installA installB installC
all: install_all runc

clean:
	@echo "Deleting the project_libraries folder..."
	rm -rf .project_libraries

installHeaderOnly:
	@echo "installHeaderOnly..."
	cd headerOnlyLib && rm -rf $(BUILD_DIR) && mkdir $(BUILD_DIR) && cd $(BUILD_DIR) && cmake .. && cmake --build . --target install

installA:
	@echo "installA..."
	cd someLibA && rm -rf $(BUILD_DIR) && mkdir $(BUILD_DIR) && cd $(BUILD_DIR) && cmake .. && cmake --build . --target install

installB:
	@echo "installAB.."
	cd someLibB && rm -rf $(BUILD_DIR) && mkdir $(BUILD_DIR) && cd $(BUILD_DIR) && cmake .. && cmake --build . --target install

installC:
	@echo "installC..."
	cd someLibC && rm -rf $(BUILD_DIR) && mkdir $(BUILD_DIR) && cd $(BUILD_DIR) && cmake .. && cmake --build . --target install

runApp:
	@echo "Run..."
	cd App && rm -rf $(BUILD_DIR) && mkdir $(BUILD_DIR) && cd $(BUILD_DIR) && cmake .. && cmake --build . && ./$(EXECUTABLE_NAME)

runHeaderOnlyLib:
	@echo "Run..."
	cd headerOnlyLib/example && rm -rf $(BUILD_DIR) && mkdir $(BUILD_DIR) && cd $(BUILD_DIR) && cmake .. && cmake --build . && ./$(EXECUTABLE_NAME)

runA:
	@echo "Run..."
	cd someLibA/example && rm -rf $(BUILD_DIR) && mkdir $(BUILD_DIR) && cd $(BUILD_DIR) && cmake .. && cmake --build . && ./$(EXECUTABLE_NAME)

runB:
	@echo "Run..."
	cd someLibB/example && rm -rf $(BUILD_DIR) && mkdir $(BUILD_DIR) && cd $(BUILD_DIR) && cmake .. && cmake --build . && ./$(EXECUTABLE_NAME)

runC:
	@echo "Run..."
	cd someLibC/example && rm -rf $(BUILD_DIR) && mkdir $(BUILD_DIR) && cd $(BUILD_DIR) && cmake .. && cmake --build . && ./$(EXECUTABLE_NAME)

.PHONY: clean installHeaderOnly installA installB installC runApp runHeaderOnlyLib runA runB runC