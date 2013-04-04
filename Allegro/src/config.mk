M_DIR=Allegro
M_SRCS=Missile.cpp A5HitBox.cpp
SRCS:= $(SRCS) $(addprefix $(M_DIR)/src/,$(M_SRCS))
