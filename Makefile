CXX = g++
CXXFLAGS = -std=c++11 -pthread
TARGET = carrera

$(TARGET): carrera.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) carrera.cpp

clean:
	rm -f $(TARGET)