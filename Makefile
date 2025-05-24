CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
SRCS = main.cpp book.cpp member.cpp library.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = library_management

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: all
	./$(TARGET)

.PHONY: all clean run
