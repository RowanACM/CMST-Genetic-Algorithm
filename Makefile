SRC_DIR := src

OBJ_DIR := obj
_OBJ    := CMST.o fitness.o selection.o crossover.o mutation.o
OBJECTS := $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -c -Iinc -o $@ $<

CMST: $(OBJECTS)
	gcc -o $@ $^ -Iinc

clean:
	rm *.gch *~ *.o CMST
