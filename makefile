OUT=rob
CC=g++

# make rebind
MAKE=make -sC

S=./src
O=./obj/*

MOD=	              \
					  $(S)/		  \
					  $(S)/commands \
					  $(S)/file 	  \
					  $(S)/parse    \

$(OUT): $(MOD) 
	$(CC) $(O) -o $@ 
	@echo rob is up to date!

.PHONY: MODULES $(MOD)

MODULES: $(MOD)

$(MOD):
	$(MAKE) $@
