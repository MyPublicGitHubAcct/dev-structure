# Include in the Makefile in all projects

CC             = gcc
CXX            = g++

SOURCES := $(wildcard *.cc) $(wildcard drivers/*.cc)
OBJECTS := $(patsubst %.cc, %.o, $(SOURCES))

DIR = $(notdir $(CURDIR))

all: $(TARGET)

%.o: %.cc
	$(CXX) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@

po:
	@echo $(OBJECTS)

ps:
	@echo $(SOURCES)

pp:
	@echo $(PACKAGES)

ptp:
	@echo $(MAKEFILE_LIST)

pcd:
	@echo $(CURDIR)

pd:
	@echo $(DIR)

clean:
	rm -rf $(TARGET) *.o

.PHONY: all clean
