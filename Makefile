
#
CPP := g++
CPP_FLAGS := -Wall -m64 -gdwarf-2 -std=c++17 -c

#
REPO_PATH := $(abspath .)

#
BIN_NAME := main
BIN := ./$(BIN_NAME)

#
default:	help
.PHONY: default

#
help:
	@echo "***** Find the Largest Number *****"
	@echo
	@echo "make help         ==> This help menu"
	@echo
	@echo "make build        ==> Rebuild your project"
	@echo "make run          ==> Run your project"
	@echo "make debug        ==> Debug your project"
	@echo
	@echo "make clean        ==> Clean temporary build files"
	@echo
.PHONY: help

#
build:	$(BIN)
.PHONY: build

#
run:	build
	$(BIN)
.PHONY: run

#
debug:	build
	gdb $(BIN_NAME) -x gdb-commands.txt
.PHONY: debug

#
clean:
	-rm *.o
	-rm $(BIN)
.PHONY: clean

#
$(BIN):	Card.o Hand.o Participant.o Player.o Dealer.o Deck.o Blackjack_Game.o main.o
	$(CPP) *.o -o $(BIN)

#
Card.o:	Card.cpp 
	$(CPP) $(CPP_FLAGS) "$<" -o "$@"

#
Hand.o:	Hand.cpp 
	$(CPP) $(CPP_FLAGS) "$<" -o "$@"

#
Participant.o:	Participant.cpp 
	$(CPP) $(CPP_FLAGS) "$<" -o "$@"

#
Player.o:	Player.cpp 
	$(CPP) $(CPP_FLAGS) "$<" -o "$@"

#
Dealer.o:	Dealer.cpp 
	$(CPP) $(CPP_FLAGS) "$<" -o "$@"

#
Deck.o:	Deck.cpp 
	$(CPP) $(CPP_FLAGS) "$<" -o "$@"

#
Blackjack_Game.o:	Blackjack_Game.cpp 
	$(CPP) $(CPP_FLAGS) "$<" -o "$@"

#
main.o: main.cpp 
	$(CPP) $(CPP_FLAGS) "$<" -o "$@"