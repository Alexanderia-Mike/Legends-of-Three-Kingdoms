# Legends of Three Kingdoms

Author: Lou Chenfei
Creating date: Nov 18 2018


### How to start: 

First, type `make` to compile the program, and an executable called `plait` will be generated.

Then, you could decide whether you would like to initialize the cards using the file `the_cards5.txt`, or using the arguments in the terminal.
- if you choose to use `the_cards5.txt` to initialize, you would need to follow the following formats:
```
[CARD_NAME] [CARD_NUMBER]
...
```
One example is the file "the_cards5.txt".

- if you choose to use arguments in the terminal, one example is the following command:
```
./playit strike 9 dodge 9 peach 5 wine 3 dismantle 4 snatch 5 borrowed_sword 3 arrow_barrage 2 barbarian_invasion 3 peach_garden 4 something_for_nothing 5 bountiful_harvest 2 lightning 3 drown_in_happiness 4 starvation 2 binocular 3 bow 4 horse 3
```

Then, you would need to choose whether you hope the program to initialize the players randomly (by typing "yes" or "no"). If you typed "no", you would need to initialize the players manually by typing in the number of players, their names, initial health, identities and countries one by one.

After that, you'll be asked whether you would like to use demo-mode (1 for yes and 0 for no). In the demo mode, you only need to type enters and the program will simulate the behaviors of different players randomly. Otherwise, as users you will need to make decisions by typing numbers in the terminal following the detailed prompts given by the program.

PS: Remember to reveal identity!! Or the game will not come to an end because the game will only reach an end when all the live players revealed their identities!!



### Known bugs:
1. This program cannot deal with "duel" card, so please don't type this kind of card in to it.



### The idea of this program:
Use array of cards, double-linked list of players and a series of process to realize the effect of cards. Almost all functions use pointers to deal with the cards.
The necessary notation has been written in the code, and I think it is necessary to write all of them here again.

