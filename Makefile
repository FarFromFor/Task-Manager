CXX=g++
CXXFLAGS=-Wall -pedantic
SOURCES := $(wildcard src/*.cpp)
OBJECTS := $(SOURCES:src/%.cpp=build/%.o)

all: compile doc

riaboale: $(OBJECTS)
	g++ $^ -o $@

build/%.o: src/%.cpp
	mkdir -p $(@D)
	g++ $(CXXFLAGS) $< -MMD -c -o $@
	
compile: riaboale

clean:
	rm -Rf riaboale Makefile.d save_events.txt build/ doc/ 2>/dev/null
	
run: compile
	./riaboale

doc:
	doxygen Doxyfile
