M_DIR=Allegro
M_SRCS=Missile.cpp 
SRCS:= $(SRCS) $(addprefix $(M_DIR)/src/,$(M_SRCS))
