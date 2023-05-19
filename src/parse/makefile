
CXX=g++

OBJ=./../../obj
SRC=./

OBJECTS=    $(OBJ)/args.o                   

parse: $(OBJECTS) 
	@echo parse up to date!

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) -c $< -o $@


