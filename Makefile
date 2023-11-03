CXX=g++
CXXFLAGS=-std=c++17 -Wpedantic -Wall -Wextra -Werror -Weffc++ -Wzero-as-null-pointer-constant
OPTIMIZE=-O2
SOURCES=Window.cpp Game.cpp main.cpp
OBJS=$(SOURCES:.cpp=.o)
TARGET=spacerace
LIBRARIES=-l sfml-system -l sfml-window -l sfml-graphics

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LIBRARIES)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(OPTIMIZE) -c $< -o $@

debug: $(SOURCES)
	$(CXX) $(CXXFLAGS) -g $(SOURCES) -o $(TARGET)-debug

clean:
	/bin/rm -f $(OBJS)
	/bin/rm -f $(TARGET)-debug
	/bin/rm -f $(TARGET)
