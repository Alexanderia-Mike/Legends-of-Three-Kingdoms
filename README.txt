Author: Lou Chenfei
Creating date: Nov 18 2018



The prerequisite usage: 
1. the program is only guaranteed to run successfully on Mac OS computers with Xcode.

2. There are two ways to initialize the cards, first is to read from the file, then you must set the working directory to open the file. The method is: open Xcode, click "Product" button on the upper command bar, click "scheme", click "edit scheme", and in "Run" field, "option" field, choose "use custom working directory", and choose the directory of "Legends of the Tree Kingdoms".

3. If you want to initialize the cards by argument through command line, then here is a sample input (so that you don't need to type again):

gcc fate.c horse.c lightning.c listtitle.c arrowbarrage.c main.c ask\ for\ help.c pause.c attackrange.c peach.c barbarian.c peachgarden.c binoculars.c playcard.c borrowedsword.c players.c bountifulharvest.c bow.c cards.c returncards.c cardsinitialwithargument.c reveal.c shuffle.c changehealth.c shufflediscard.c checksuccess.c snatch.c create\ list\ of\ players.c somethingfornothing.c deal\ the\ cards.c starvation.c discard.c strike.c dismantle.c testifyfate.c distance.c dodge.c wine.c drowninhappiness.c -o plait!

./playit! strike 9 dodge 9 peach 5 wine 3 dismantle 4 snatch 5 borrowed_sword 3 arrow_barrage 2 barbarian_invasion 3 peach_garden 4 something_for_nothing 5 bountiful_harvest 2 lightning 3 drown_in_happiness 4 starvation 2 binocular 3 bow 4 horse 3



Known bugs:
1. This program cannot deal with "duel" card, so please don't type this kind of card in to it.



The idea of this program:
Use array of cards, double-linked list of players and a series of process to realize the effect of cards. Almost all functions use pointers to deal with the cards.
The necessary notation has been written in the code, and I think it is necessary to write all of them here again.



How to play?
First choose whether to initialize the players randomly by the computer. If no, you are supposed to type in the number of players, their names, initial health, identities and countries.

Then you will be asked to determine whether to use demo-mode, 1 for yes and 0 for no. So just choose as you want.

After that, the game starts. If you are in. A demo-mode, just type enter to continue the game. Otherwise, you should make decisions by typing in numbers (the specific usage is clearly clarified in the output of the program).

Remember to reveal identity!! Or the game will not come to an end because the game will only reach an end when all the live players revealed their identities!!


