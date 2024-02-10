# Include in the Makefile in all projects

CC             := gcc
CXX            := g++

CXXFLAGS       := -std=c++11 -Wall

# Directories
SRC_DIR := .
BUILD_DIR := build
BIN_DIR := bin

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cc) $(wildcard $(SRC_DIR)/*/*.cc) $(wildcard $(SRC_DIR)/*/*/*.cc)
OBJS := $(patsubst $(SRC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(SRCS))

# Executable
TARGET := $(BIN_DIR)/$(TARGET)

all: $(TARGET)

# Build the executable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) $^ -o $@

# Build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -c $< -o $@

# Checking values
ps:
	@echo $(SRCS)

po:
	@echo $(OBJS)

ptp:
	@echo $(MAKEFILE_LIST)

pcd:
	@echo $(CURDIR)

# Project cleaning
rmbuild:
	rm -r $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all rmbuild clean ps po ptp pcd
