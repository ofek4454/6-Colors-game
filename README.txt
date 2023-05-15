--------------------------------
OOP2 ex04

--------------------------------
Submitted by:
Ofek Gorgi - 209179548
Bar Kobi - 316114206

--------------------------------
Exercise description:
In the exercise we have built a 6-Colors game.
6 Colors Game is a captivating puzzle game that challenges your strategic
thinking and color-matching skills. In each level, you are presented with a
grid filled with colorful tiles. Your objective is to clear the board by
connecting tiles of the same color in groups of six or more.
By strategically selecting and swapping tiles, you can create chain reactions
and unleash powerful combos to earn higher scores.
With its intuitive gameplay, visually pleasing design, and increasingly
challenging levels, 6 Colors Game offers hours of addictive entertainment
for puzzle enthusiasts of all ages.

--------------------------------
File list:

- Board.h/.cpp -                 manage the tiles, create the board and connect the edges on the graph

- ColorBth.h/.cpp -              Handle the buttons of choosing color.

- Consts.h/.cpp -                Save all the game constants like board size and screen size.

- Controller.h/.cpp              The manager of the game - the main class that uses all the
                                 almost all the classes to control,design and make sure that
                                 the game is following the rules.

- Graph.h/.cpp                   Data struct that contains GraphNode, responsible to the neighbors lists.

- GraphNode.h/.cpp               One node in the graph, represent a pad in the graph.

- HexagonBoard.h/.cpp            Create a board with hexagons.

- MainMenu.h/.cpp                Shows main menu with multiple options.

- Pad.h/.cpp                     represent a pad in the board, with neighbors and color.

- ResourceManager.h/.cpp         Hold all the resources of the game, e.g. font.

- GreedyPlayerLongDistance.txt   A player that calculate the next move according to all
                                 the available pads.

- GreedyPlayerSmallDistance.h    A player that calculate the next move according to just
                                 his neighbors.

- Player.h                       Base class to all the players.

- RandomPlayer.h                 A player that choose color randomly.

- UserPlayer.h                   The user player, plays according to the user color choose.

--------------------------------
Data structures:
Graph -                          Data struct that contains GraphNode, responsible to the neighbors lists.

--------------------------------
Algorithms:
GreedyPlayerLongDistance -       The algorithm of the greedy long distance player is to sum all the available
                                 colors from the player pads and choose the highest.

GreedyPlayerSmallDistance -      The algorithm of the greedy short distance player is to sum all the neighbors
                                 by color and choose the highest.

Connect the pads neighbors -     The method of connecting the neighbors is creating two vectors of all the possible
                                 neighbors for each odd and even row pad, by connecting their x and y with the vector
                                 of coordinates and if got a valid "Vector2u" that has value then i can add the neighbor

--------------------------------
Known bugs:

--------------------------------
Other notes: