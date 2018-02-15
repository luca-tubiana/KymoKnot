#compiler
CC = gcc
#compiler flags
C_FLAGS =  -O3 -g -Wall -Werror=implicit-function-declaration -std=c99 -fno-omit-frame-pointer
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
OBJ2=./lib/my_random.o Alexander.o
OBJ3=KNT_arc.o
OBJ4=KNT_closures.o KNT_qhull.o KNT_simplify.o KNT_identify.o
OBJ5=KNT_lib.o KNT_io.o KNT_manager.o
OBJS=$(OBJ1) $(OBJ2) $(OBJ3) $(OBJ3) $(OBJ4) $(OBJ5) $(QHULLIB)/libqhullstatic.a

all:  KymoKnot_ring.x KymoKnot_linear.x K_close.x

KymoKnot_ring.x: $(OBJS) KymoKnot_ring.c
	$(CC) $(C_FLAGS)  -I $(DIR_HEADERS)    -I $(QHULLHDR) $^  -lm  -lgsl -lgslcblas $(QHULLIB)/libqhullstatic.a -o $@
KymoKnot_linear.x: $(OBJS) KymoKnot_linear.c
	$(CC) $(C_FLAGS)  -I $(DIR_HEADERS)    -I $(QHULLHDR) $^  -lm  -lgsl -lgslcblas $(QHULLIB)/libqhullstatic.a -o $@
K_close.x: $(OBJS) KNTclose.c
	$(CC) $(C_FLAGS)  -I $(DIR_HEADERS)    -I $(QHULLHDR) $^  -lm  -lgsl -lgslcblas $(QHULLIB)/libqhullstatic.a -o $@
# dependencies
./lib/%.o:./lib/%.c
	$(CC) $(CFLAGS) $< -o $@ -c
%.o:%.c
	$(CC) $(CFLAGS) -I $(QHULLHDR) -I $(DIR_HEADERS) $< -o $@ -c
$(QHULLIB)/libqhullstatic.a:
	cd $(QHULL); make
clean:
	rm *.o
deep-clean:
	rm *.o *.x
	cd $(QHULL); make cleanall
