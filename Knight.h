//=============================================================
/**
 * Knight.h
 * 2017-02-02 09:02
 * KelsenH
 *
 */
//=============================================================

#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>

/**
 * @class Knight
 *
 * Acts as a knight from chess to be used on a board
 */
class Knight 
{
  public:

    //Default constructor
    Knight (void);
    
    /**
     * Position initializing constructor
     *
     * @param[in] x_position  y_position
     */
    Knight (int x_position, int y_position);

    /**
     * Sets the x position of the knight
     * Makes sure it is not negative or greater
     * than the allowed board space
     *
     * @param[in] x_position
     */
    void set_x (int x_position);

    /**
     * Sets the y position of the knight
     * Makes sure it is not negatice or greater
     * than the allowed board space
     *
     * @param[in] y_position
     */
    void set_y (int y_position);

    /**
     * Sets both the x and y of the knight by
     * calling the set_x and set_y methods to
     * make sure the bounds are checked
     *
     * @param[in] x_position  y_position
     */
    void set_pos (int x_position, int y_position);

    /**
     * Returns the x_position of the knight
     *
     *@return x_position_
     */
    int get_x_pos (void);

    /**
     * Returns the y_position of the knight
     *
     * @return y_position_
     */
    int get_y_pos (void);

  private:

    //X Position
    int x_position_;

    //Y Position
    int y_position_;

};

#endif
