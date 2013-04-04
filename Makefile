include config.mk

export 32BIT

MODULE_CONFIG= $(foreach module, $(MODULES), $(module)/src/config.mk)

include $(MODULE_CONFIG)

INC_FLAGS= $(foreach incdir, $(INC_DIRS), -I$(incdir))
LIB_FLAGS= $(foreach libdir, $(LIB_DIRS), -L$(libdir))
EXT_LIBS= $(foreach libname, $(LIB_NAMES), -l$(libname))
OBJS= $(patsubst %.cpp, %.o, $(SRCS))

%.o: %.cpp
	$(CPPC) -c $(CPP_FLAGS) $(INC_FLAGS) $< -o $@

all: $(BIN)

$(BIN): $(OBJS)
	$(CPPC) $(CPP_FLAGS) -o $@ $(OBJS) $(LIB_FLAGS) $(EXT_LIBS) `pkg-config --cflags --libs $(ALLEGRO_LIBS)`

prebuild:
	make -C Cpp2DGameEngine

clean:
	rm -f -R $(DIST) $(OBJS) $(BIN)

cleanall: clean
	make -C Cpp2DGameEngine clean

release: $(BIN)
	rm -Rf $(DIST)
	mkdir $(DIST)
	cp $(word 1, $?) $(DIST)/.
