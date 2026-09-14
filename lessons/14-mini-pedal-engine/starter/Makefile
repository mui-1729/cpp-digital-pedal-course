CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic

app: main.cpp PedalEngine.h
	$(CXX) $(CXXFLAGS) main.cpp -o app

test: tests.cpp PedalEngine.h
	$(CXX) $(CXXFLAGS) tests.cpp -o tests
	./tests

clean:
	rm -f app tests
