INC := -I/usr/local/include/eigen3
INC += -I./include
CC := g++
FLAGS := -g -Wall -std=c++11 -fno-omit-frame-pointer -fsanitize=address
LFLAGS := -lfftw3

SOURCE := $(wildcard ./src/*.cc)
OBJS := $(patsubst %.cc, %.o, $(SOURCE))

.PHONY: all clean
.SECONDARY: $(OBJS)

all: main.out

main.out: $(OBJS)
	$(CC) -o $@ \
		$(OBJS) \
		$(FLAGS) \
		$(LFLAGS)

./src/%.o: ./src/%.cc ./include/*.hpp
	$(CC) -o $@ -c $< \
		$(INC) \
		$(FLAGS)

clean:
	@rm -rf $(OBJS) ./*.out*
