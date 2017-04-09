# Declaration of variables
CC = g++
CC_FLAGS = -g -w -std=c++11

# File names
EXEC = weather
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC) -lcurl

# To obtain object files
%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@ -lcurl

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)


# SRCS=$(wildcard .cpp)
# OBJS=(SRCS:.cpp=.o)
# all: $(OBJS)

#all:
	#g++ -std=c++11 -c conditions.cpp
	#g++ -std=c++11 -c conditions.cpp
	#g++ -std=c++11 -c my_test.cpp
	#g++ -std=c++11 my_test.o -o conditions.o
	
