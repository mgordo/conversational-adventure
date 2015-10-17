# conversational-adventure
A C based engine for conversational adventures, with one sample adventure. 
Authors: C. Carrascal, M. Gordo and A. Jimenez.

All you need to do to get it running is run 'make all' in the directory you download it. Unzip your adventure in the same directory, run './game' and you're good to go. A list of games will appear, select the one you want to play.


A game consists of 3 xml documents: one for the dialogue, one for the rules, and one for the world and objects. The documentation on how to create new xml files for new games can be found in the other documentation files within this folder.

The technical documentation was generated with doxygen and can be accesed with the index.html file within the html folder. 


As a sample, this project comes with its own adventure, 'Draco Dormiend Nunquam Titilandus', in which you become a Gryffindor student and you need to pass your potions exam. The very same morning of the exam, you wake up in the common room only to find you've been robbed. 

You will need to find all your ingredients and your book in order to have a shot a the exam...

The commands that you can use are:
IR (direction): Moves the player in the specified direction: north, south, east, west, up, down (norte, sur, este, oeste, arriba y abajo)


COGER (object): Put in the player's inventory the specified object


DEJAR (object) : Drop to the current location the specified object


ENCIENDE (object): In object can be turned on, turn on said object


APAGA (object): If an object is turned on, turn it off


METER (object1) en (object2): Puts object1 into object2


SACAR (object1) de (object2): takes out object1 from object2


EXAMINAR (something): Gives a detailed description of something you wish to examine. It could be an object, your current location (lugar) or your inventory (inventario)


ABRIR (direction): opens a door in the specified direction, if there is a door to be opened


PEDIR (object) a (npc): If an npc has a specific object, ask said npc to give it to yous.


DAR (object) a (npc):  give an object in your inventory to an npc. Warning: keep track of an object if you give it away! There is no way to examine a npc's inventory


DECIR (sentence) a (npc): speak a sentence to a certain npc. The sentence must be surrounded by the character (')


FIN: Ends the game and closes the program

Hope you enjoy playing it as much as I did developing it!
