CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic

app: main.cpp Distortion.cpp Distortion.h
	$(CXX) $(CXXFLAGS) main.cpp Distortion.cpp -o app

clean:
	rm -f app
