CC := clang++ -std=c++17
TARGET := main
SRC := src/t_$(n).cpp
EXECUTABLES := $(wildcard t_*)

all: main run clean

main: $(SRC)
	@$(CC) -o $(TARGET) $(SRC)

run: main
	@./$(TARGET) < input.txt

clean:
	@rm -f $(TARGET)

clean_dir:
	@rm -f $(filter-out %.cpp, $(EXECUTABLES))