//=============================================================
/**
 * Board.h
 * 2017-02-13 15:46
 * KelsenH
 *
 */
//=============================================================
class Case
{
  public:
    Case (int x_pos, int y_pos)
    : x_pos_ (x_pos),
      y_pos_ (y_pos),
      next_case_ (0)  
    {
 
    }

    ~Case (void) 
    {
      delete next_case_;
    }

    int get_x_pos (void)
    {
      return x_pos_;
    }

    int get_y_pos (void)
    {
      return y_pos_;
    }

    void set_next_case (int x, int y) 
    {
      next_case_ = new Case (x, y);
    }

    Case * get_next_case (void)
    {
      return next_case_;
    }

  private:
    int x_pos_;
    int y_pos_;
    Case * next_case_;
};