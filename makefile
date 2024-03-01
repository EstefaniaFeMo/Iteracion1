EXE=anthill

CFLAGS=-Wall -ansi -pedantic -g -DDEBUG

CC=gcc

CLIB= -lscreen -L.

.PHONY: clean_objects clean_program clean all

all: anthill space_test

anthill: game_loop.o game.o game_actions.o command.o graphic_engine.o space.o game_reader.o object.o player.o character.o
	$(CC) -o $@ $^ $(CLIB)

space_test: space_test.o space.o set.o

#...............................................................................................#

game_loop.o: game_loop.c command.h game.h space.h types.h game_actions.h graphic_engine.h object.h player.h game_reader.h
	$(CC) $(CFLAGS) -c $<

command.o: command.c command.h
	$(CC) $(CFLAGS) -c $<

game.o: game.c game.h game_reader.h command.h space.h types.h object.h player.h
	$(CC) $(CFLAGS) -c $<

game_actions.o: game_actions.c game_actions.h command.h game.h space.h types.h object.h player.h game_reader.h
	$(CC) $(CFLAGS) -c $<

graphic_engine.o: graphic_engine.c graphic_engine.h game.h command.h space.h types.h libscreen.h object.h player.h game_reader.h
	$(CC) $(CFLAGS) -c $<

space.o: space.c space.h types.h set.h
	$(CC) $(CFLAGS) -c $<

game_reader.o: game_reader.c game_reader.h game.h types.h command.h space.h object.h player.h
	$(CC) $(CFLAGS) -c $<

object.o: object.c object.h types.h
	$(CC) $(CFLAGS) -c $<

player.o: player.c player.h types.h
	$(CC) $(CFLAGS) -c $<

character.o: character.c character.h types.h
	$(CC) $(CFLAGS) -c $<

space_test.o: space_test.c space_test.h test.h space.h types.h set.h
	$(CC) $(CFLAGS) -c $<

set.o: set.c set.h types.h
	$(CC) $(CFLAGS) -c $<

#...............................................................................................#
clean_objects:
	@echo "Cleaning objects..."
	@rm -f *.o

clean_program:
	@echo "Cleaning program..."
	@rm -f anthill space_test

clean: clean_objects clean_program
