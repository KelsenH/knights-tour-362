//=============================================================
/**
 * Board.h
 * 2017-02-02 16:19
 * KelsenH
 *
 */
//=============================================================

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Knight.h"
#include <vector>
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
      bool getPossibleMoves (void);

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
      bool warnsdoff (void);

      /**
      * Chooses first available move from possible moves
      * Executes the movement of the knight, and marks the spot
      */
      bool choose_move (void);

      /**
      * Reset all board values to 0
      * Also can be used to initialize board
      */
      void reset (void);

      void reset_chosen_move_amt (void)
      {
        chosen_move_amt = 0;
      }

      int get_knight_moves (void) 
      {
        return knight_moves;
      }

    private:
      //Board matrix
      int board [8][8];

      Knight knight;
      
      //2d array of possible moves
      int possible_moves [8][2];

      int possible_move_amt;
      
      //Holds row of chosen moves
      std::vector <int> chosen_moves;

      int chosen_move_amt;

      //Amount of moves knight has made
      int knight_moves;

};

#endif
