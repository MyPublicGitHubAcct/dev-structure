# Include in the Makefile in all projects

CC             := gcc
CXX            := g++
CFLAGS         := -Wall
CXXFLAGS       := -std=c++11 -Wall
LDFLAGS         = -lcriterion

# Directories
SRC_DIR := .
BUILD_DIR := build
BIN_DIR := bin
INCLUDE_DIRS :=

TEST_DIR := tests

# Criterion
CRITERION_INCLUDE := /opt/homebrew/Cellar/criterion/2.4.2/include
CRITERION_LIBRARY := /opt/homebrew/Cellar/criterion/2.4.2/lib

# Source files
SRCS := \
	$(wildcard $(SRC_DIR)/*.cc) \
	$(filter-out $(SRC_DIR)/$(TEST_DIR)/$(EXCLD_TESTS), $(wildcard $(SRC_DIR)/*/*.cc))

OBJS := $(patsubst $(SRC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(SRCS))

# Test source files
TEST_SRCS := $(wildcard $(SRC_DIR)/*/*.cc)
TEST_OBJS := $(patsubst $(SRC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(TEST_SRCS))

# Executables
TARGET := $(BIN_DIR)/$(TARGET)
TEST_TARGET := $(TARGET)_tests

all: $(TARGET) $(TEST_TARGET)

# Build the executable
$(TARGET): $(filter-out $(BUILD_DIR)/$(TEST_DIR)/*.o, $(OBJS))
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) $^ -o $@

# Build the test executable
$(TEST_TARGET): $(TEST_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ -I$(CRITERION_INCLUDE) $^ -L$(CRITERION_LIBRARY) $(LDFLAGS)

# Build object files from CC source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -c $< -o $@

# Build object files from C source files
# $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
# 	@mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

# Build test object files from CC source files
$(BUILD_DIR)/$(TEST_DIR)/%.o: $(SRC_DIR)/$(TEST_DIR)/%.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -c $< -o $@

# Build test object files from C source files
# $(BUILD_DIR)/%.o: $(TEST_DIR)/%.c
# 	@mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

# Run executable
run: $(TARGET)
	@$(TARGET)

# Run tests
test: $(TEST_TARGET)
	@$(TEST_TARGET)

# Variable values
info:
	$(info )
	$(info Makefiles   =  $(MAKEFILE_LIST))
	$(info -------------)
	$(info CURDIR      =  $(CURDIR))
	$(info SRC_DIR     =  $(SRC_DIR))
	$(info SRCS        =  $(SRCS))
	$(info OBJS        =  $(OBJS))
	$(info TARGET      =  $(TARGET))
	$(info -------------)
	$(info TEST_SRCS   =  $(TEST_SRCS))
	$(info TEST_OBJS   =  $(TEST_OBJS))
	$(info TEST_TARGET =  $(TEST_TARGET))
	$(info -------------)
	$(info EXCLD_TESTS =  $(SRC_DIR)/$(TEST_DIR)/$(EXCLD_TESTS))
	$(info )

# Project cleaning
rmbuild:
	rm -r $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all run test info rmbuild clean
