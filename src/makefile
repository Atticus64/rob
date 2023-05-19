
CXX=g++

OBJ=./../obj
SRC=./

OBJECTS=    $(OBJ)/main.o                   

main: $(OBJECTS) 
	@echo main up to date!

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) -c $< -o $@


