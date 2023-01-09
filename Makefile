#compiler
CC = gcc
#compiler flags
C_FLAGS =  -O3 -g -Wall -Werror=implicit-function-declaration -std=c99 -fno-omit-frame-pointer
#C_FLAGS =   -g -Wall -Werror=implicit-function-declaration -std=c99 -fno-omit-frame-pointer
#debug flags
#C_FLAGS =   -ggdb -Wall -Werror=implicit-function-declaration -std=c99 -fno-omit-frame-pointer
#libraries
C_LIB_LM = -lm
VPATH=./lib
#headers
DIR_HEADERS=./lib/
QHULL=./qhull-2012.1
QHULLIB=./qhull-2012.1/lib
QHULLHDR=./qhull-2012.1/src/libqhull
#general definitions
OBJ1=./lib/my_geom.o ./lib/my_memory.o ./lib/messages.o
OBJ2=./lib/prng.o Alexander.o
OBJ3=KNT_arc.o
OBJ4=KNT_closures.o KNT_qhull.o KNT_simplify.o KNT_identify.o
OBJ5=KNT_lib.o KNT_io.o KNT_manager.o
OBJS=$(OBJ1) $(OBJ2) $(OBJ3) $(OBJ3) $(OBJ4) $(OBJ5) $(QHULLIB)/libqhullstatic.a

all:  KymoKnot_ring.x KymoKnot_linear.x KymoKnot_ring_lammps.x KymoKnot_linear_lammps.x K_close.x

KymoKnot_ring.x: $(OBJS) KymoKnot_ring.c
	$(CC) $(C_FLAGS)  -I $(DIR_HEADERS)    -I $(QHULLHDR) $^  -lm   $(QHULLIB)/libqhullstatic.a -o $@
KymoKnot_linear.x: $(OBJS) KymoKnot_linear.c
	$(CC) $(C_FLAGS)  -I $(DIR_HEADERS)    -I $(QHULLHDR) $^  -lm   $(QHULLIB)/libqhullstatic.a -o $@
KymoKnot_ring_lammps.x: $(OBJS) KymoKnot_ring_lammps.c
	$(CC) $(C_FLAGS)  -I $(DIR_HEADERS)    -I $(QHULLHDR) $^  -lm   $(QHULLIB)/libqhullstatic.a -o $@
KymoKnot_linear_lammps.x: $(OBJS) KymoKnot_linear_lammps.c
	$(CC) $(C_FLAGS)  -I $(DIR_HEADERS)    -I $(QHULLHDR) $^  -lm   $(QHULLIB)/libqhullstatic.a -o $@
K_close.x: $(OBJS) KNTclose.c
	$(CC) $(C_FLAGS)  -I $(DIR_HEADERS)    -I $(QHULLHDR) $^  -lm   $(QHULLIB)/libqhullstatic.a -o $@
K_simplify_ring.x: $(OBJS) KNTring_simplify.c
	$(CC) $(C_FLAGS)  -I $(DIR_HEADERS)    -I $(QHULLHDR) $^  -lm   $(QHULLIB)/libqhullstatic.a -o $@
# dependencies
./lib/%.o:./lib/%.c
./lib/%.o:./lib/%.c
	$(CC) $(C_FLAGS) $< -o $@ -c
%.o:%.c
	$(CC) $(C_FLAGS) -I $(QHULLHDR) -I $(DIR_HEADERS) $< -o $@ -c
$(QHULLIB)/libqhullstatic.a:
	cd $(QHULL); make
clean:
	rm *.o ./lib/*.o
deep-clean:
	rm *.o *.x
	cd $(QHULL); make cleanall
