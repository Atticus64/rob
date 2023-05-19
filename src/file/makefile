
CXX=g++

OBJ=./../../obj
SRC=./

OBJECTS=    $(OBJ)/csv.o                     \
			$(OBJ)/file.o         \

vulkan_utils: $(OBJECTS) 
	@echo file up to date!

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) -c $< -o $@
