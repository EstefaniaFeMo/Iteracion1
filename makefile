EXE=anthill

CFLAGS=-Wall -ansi -pedantic -g -DDEBUG 

CC=gcc

CLIB= -lscreen -L.

.PHONY: clean_objects clean_program clean all

all: anthill space_test set_test character_test inventory_test

anthill: game_loop.o game.o game_actions.o command.o graphic_engine.o space.o game_reader.o object.o player.o character.o set.o
	$(CC) -o $@ $^ $(CLIB)

space_test: space_test.o space.o set.o
	$(CC) -o $@ $^ 

set_test: set_test.o set.o
	$(CC) -o $@ $^

character_test: character_test.o character.o
	$(CC) -o $@ $^

inventory_test: inventory_test.o inventory.o set.o
	$(CC) -o $@ $^ 

#...............................................................................................#

game_loop.o: game_loop.c command.h types.h game.h space.h set.h object.h player.h character.h game_actions.h graphic_engine.h
	$(CC) $(CFLAGS) -c $<

command.o: command.c command.h types.h
	$(CC) $(CFLAGS) -c $<

game.o: game.c game.h command.h types.h space.h set.h object.h player.h character.h game_reader.h
	$(CC) $(CFLAGS) -c $<

game_actions.o: game_actions.c game_actions.h command.h types.h game.h space.h set.h object.h player.h character.h
	$(CC) $(CFLAGS) -c $<

graphic_engine.o: graphic_engine.c graphic_engine.h game.h command.h types.h space.h set.h object.h player.h character.h libscreen.h
	$(CC) $(CFLAGS) -c $<

space.o: space.c space.h types.h set.h
	$(CC) $(CFLAGS) -c $<

game_reader.o: game_reader.c game_reader.h game.h command.h types.h space.h set.h object.h player.h character.h
	$(CC) $(CFLAGS) -c $<

object.o: object.c object.h types.h
	$(CC) $(CFLAGS) -c $<

player.o: player.c player.h types.h
	$(CC) $(CFLAGS) -c $<

character.o: character.c character.h types.h
	$(CC) $(CFLAGS) -c $<

space_test.o: space_test.c space.h types.h set.h space_test.h test.h
	$(CC) $(CFLAGS) -c $<

set.o: set.c set.h types.h
	$(CC) $(CFLAGS) -c $<

set_test.o: set_test.c set.h types.h set_test.h test.h
	$(CC) $(CFLAGS) -c $<

character_test.o: character_test.c character.h types.h character_test.h test.h
	$(CC) $(CFLAGS) -c $<

inventory.o: inventory.c inventory.h types.h set.h
	$(CC) $(CFLAGS) -c $<

inventory_test.o: inventory_test.c inventory_test.h inventory.h types.h  test.h
	$(CC) $(CFLAGS) -c $<
#...............................................................................................#
clean_objects:
	@echo "Cleaning objects..."
	@rm -f *.o

clean_program:
	@echo "Cleaning program..."
	@rm -f anthill space_test set_test character_test inventory_test

clean: clean_objects clean_program
