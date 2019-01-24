INC := -I/usr/local/include/eigen3 -I/usr/include/eigen3
INC += -I./include
CC := g++
FLAGS := -g -Wall -std=c++11 -fno-omit-frame-pointer -fsanitize=address
LFLAGS := -lfftw3

SOURCE := $(wildcard ./src/*.cc)
OBJS := $(patsubst %.cc, %.o, $(SOURCE))
TEST_SRC := $(wildcard ./unit_test/*.cc)
TEST_EXE := $(patsubst %.cc, %.out, $(TEST_SRC))

.PHONY: all clean
.SECONDARY: $(OBJS)

all: $(TEST_EXE)

./unit_test/%.out: ./unit_test/%.cc  $(OBJS)
	$(CC) -o $@ $< $(OBJS) \
		$(INC) \
		$(FLAGS) \
		$(LFLAGS)
	$@ > $@.log
	cat $@.log

./src/%.o: ./src/%.cc ./include/*.hpp
	$(CC) -o $@ -c $< \
		$(INC) \
		$(FLAGS)

clean:
	@rm -rf $(OBJS) ./unit_test/*.out* ./unit_test/*.log
