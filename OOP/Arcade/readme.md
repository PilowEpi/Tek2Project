Arcade is a retro gaming platform; a program that lets the user choose a game to play and keeps a register of player scores.

This platform can be used to play different games with different grahpical interfaces. With that, you can change the grahpical during the game (ex: starting in ncurses then swipe to sfml).

You can also create your own grahpical interfaces and implement your own retro game using the same interface as Arcade's interface. To do so you need to use IGameModule functions for game or IDisplayModule functions for grahpical.


Launch
============

To launch the Arcade project :

```
make
./arcade path_to_lib.so (lib/arcade_ncurses (for exemple))
```

To see technical/User documentation

```
doxygen doc/Doxyfile
```
and open the index.html file in your browser.


Arcade
============

You now in the menu of the arcade projet. To play a game, you need to choose a graphical lib, your username and the game. You can also see the current leaderboard of every game.

### KeyBindings

Z : up

S : down

D : right

Q : left

Up Arrow : Up

Down Arrow : Down

right Arrow : right

left Arrow : left

T : Return to the menu

L : Previous Graphical Lib

O : Next Graphical Lib

P : Previous Game

M : Next Game

R : Reset the Game

### Available Game

* Nibbler
* Snake
* Qix
* Centipede
* Pacman

### Available grahpical interfaces

* SFML
* SDL2
* ncurses
* Xlib
* Allegro5
* Irrlicht

- - -

###Project made by Mathias D. / Louis C. / Mathieu R.###
Group name : 
 - `A la votre`

Group that's collaborated with us :

 - No u
    * Maxime D. (maxime.deroulou@epitech.eu)
    * Florent L.