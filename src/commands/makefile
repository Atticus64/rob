CXX=g++

OBJ=./../../obj
SRC=./

OBJECTS=    $(OBJ)/actions.o                   

commands: $(OBJECTS) 
	@echo commands up to date!

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) -c $< -o $@

