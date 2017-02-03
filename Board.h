//=============================================================
/**
 * Board.h
 * 2017-02-02 016:19
 * KelsenH
 *
 */
//=============================================================

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Knight.h"

/**
 * @class Board
 *
 * Representation of a chess board 
 */
class Board 
{
    public:
      
      //Default constructor
      Board (void);

      /**
       * Position initializing constructor for knight 
       * 
       * @param[in] x_position  y_position
       */
      Board (int x_position, int y_position);

      /**
       * Uses a for loop to iterate through possible
       * knight moves. If the space has already been visited
       * or is off of the board, they are not included.
       */
      void getPossibleMoves (void);

      /**
       * Moves the knight to specified x and y 
       *
       * @param[in] x_position  y_position
       */
      void moveKnight (int x_position, int y_position);

      //Print the board in an easy to see format
      void printBoard (void);

      /**
      * Outputs a nicely formatted look at the current
      * board contents to a file 
      *
      * @param[in] fileName
      */
      void writeBoard (std::string fileName);

      /**
      * Warndoff's heuristic for choosing the next place
      * chooses place with least amount of next possible moves
      */
      void warndoff (void);

      /**
      * Reset all board values to 0
      * Also can be used to initialize board
      */
      void reset (void);

    private:
      //Board matrix
      int board [8][8];

      Knight knight;
      
      //2d array of possible moves
      int possible_moves [8][2];
      
      //Holds row of chosen moves
      int chosen_moves [8];

};

#endif