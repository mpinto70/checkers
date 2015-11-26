+ Simple Checkers

you have to define CHECKERS_ROOT to point to the project root directory

export CHECKERS_ROOT=~/projects/checkers

you have to have boost installed and variable BOOST_ROOT pointing to its root

export BOOST_ROOT=~/Boost

The design of this application allows easy substitution of players and UI.

The main logic of the game is in game::CController

The board logic is in board::CBoard



