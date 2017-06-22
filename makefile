All:
	@echo "Compiling Dictionay Project..."
	@g++ -Wall -std=c++11 src/driver_dictionary.cpp -I include/ -o bin/prog
	#@echo "Running Dictionay Project..."
	#@./bin/prog
clean:
	@echo "Cleaning..."
	@rm bin/*
