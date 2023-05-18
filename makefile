OUT=rob
CC=g++

S=./src
O=./obj

OBJ= 	$(O)/main.o		\
		$(O)/file.o		\
		$(O)/parse/args.o		\
		$(O)/commands/actions.o		\


$(OUT): $(OBJ) 
	$(CC) $(OBJ) -o $@


$(O)/%.o: $(S)/%.cpp 
	$(CC) $< -c -o $@
