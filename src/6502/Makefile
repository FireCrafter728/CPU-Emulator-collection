SOURCES_CPP=$(shell find . -name "*.cpp")
OBJECTS_CPP=$(patsubst %.cpp, $(obj)/6502/%.obj, $(SOURCES_CPP))

build: $(bin)/cec-6502

$(bin)/cec-6502: $(OBJECTS_CPP)
	$(LD) -o $@ $^

$(obj)/6502/%.obj: %.cpp
	$(CXX) $(CXXFLAGS) -I Include -c -g -o $@ $<
	echo "6502: Compiled -> $<"