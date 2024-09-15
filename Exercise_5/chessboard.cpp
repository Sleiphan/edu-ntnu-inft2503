#ifndef CUSTOM_CHESSBOARD
#define CUSTOM_CHESSBOARD

#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class ChessBoard
{
public:
  enum class Color
  {
    WHITE,
    BLACK
  };

  class Piece
  {
  public:
    Piece(Color color) : color(color) {}
    virtual ~Piece() {}

    Color color;
    std::string color_string() const
    {
      if (color == Color::WHITE)
        return "white";
      else
        return "black";
    }

    /// Return color and type of the chess piece
    virtual std::string type() const = 0;

    virtual char type_short() const = 0;

    /// Returns true if the given chess piece move is valid
    virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
  };

  class King : public Piece
  {
  public:
    King(Color color) : Piece(color) {}
    ~King() {}

    std::string type() const
    {
      return color_string().append(" king");
    }

    char type_short() const
    {
      return color == Color::WHITE ? 'K' : 'k';
    }

    bool valid_move(int from_x, int from_y, int to_x, int to_y) const
    {
      bool valid_x = abs(to_x - from_x) <= 1;
      bool valid_y = abs(to_y - from_y) <= 1;

      return valid_x & valid_y;
    }
  };

  class Knight : public Piece
  {
  public:
    Knight(Color color) : Piece(color) {}
    ~Knight() {}

    std::string type() const
    {
      return color_string().append(" knight");
    }

    char type_short() const
    {
      return color == Color::WHITE ? 'J' : 'j'; // Using the knight's letter "j" from playing cards
    }

    bool valid_move(int from_x, int from_y, int to_x, int to_y) const
    {
      int length_x = abs(to_x - from_x);
      int length_y = abs(to_y - from_y);
      int sum = length_x + length_y;

      bool valid = true;
      valid &= length_x > 0;
      valid &= length_y > 0;
      valid &= sum == 3;

      return valid;
    }
  };

  ChessBoard()
  {
    // Initialize the squares stored in 8 columns and 8 rows:
    squares.resize(8);
    for (auto &square_column : squares)
      square_column.resize(8);
  }

  std::string get_board_print() const
  {
    const int column_count = (int)squares.size();
    const int row_count = (int)squares[0].size();
    const int string_size = 2 + column_count * 3 + row_count * (3 + 3 * column_count) + 1;
    char *res = new char[string_size];

    int current_pos = 0;
    res[current_pos++] = ' ';

    // Print letters
    for (char letter = 'A'; letter < 'A' + column_count; ++letter, current_pos += 3)
      sprintf(&res[current_pos], "  %c", letter);
    res[current_pos++] = '\n';

    // Print rest of board
    for (int y = 0; y < row_count; ++y)
    {
      sprintf(&res[current_pos], "%d ", y + 1);
      current_pos += 2;

      for (int x = 0; x < column_count; ++x, current_pos += 3)
      {
        char letter = squares[x][y].get() ? squares[x][y]->type_short() : ' ';
        sprintf(&res[current_pos], "[%c]", letter);
      }
      res[current_pos++] = '\n';
    }

    res[current_pos++] = '\0';

    if (current_pos > string_size)
    {
      std::cerr << "Access voilation inside Chessboard::get_board_print()" << std::endl;
      exit(1);
    }

    std::string result(res);
    delete[] res;

    return result;
  }

  /// 8x8 squares occupied by 1 or 0 chess pieces
  vector<vector<unique_ptr<Piece>>> squares;

  /// Move a chess piece if it is a valid move.
  /// Does not test for check or checkmate.
  bool move_piece(const std::string &from, const std::string &to)
  {
    int from_x = from[0] - 'a';
    int from_y = stoi(string() + from[1]) - 1;
    int to_x = to[0] - 'a';
    int to_y = stoi(string() + to[1]) - 1;

    auto &piece_from = squares[from_x][from_y];
    if (piece_from)
    {
      if (piece_from->valid_move(from_x, from_y, to_x, to_y))
      {
        cout << piece_from->type() << " is moving from " << from << " to " << to << endl;
        auto &piece_to = squares[to_x][to_y];
        if (piece_to)
        {
          if (piece_from->color != piece_to->color)
          {
            cout << piece_to->type() << " is being removed from " << to << endl;
            if (auto king = dynamic_cast<King *>(piece_to.get()))
              cout << king->color_string() << " lost the game" << endl;
          }
          else
          {
            // piece in the from square has the same color as the piece in the to square
            cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
            return false;
          }
        }
        piece_to = move(piece_from);
        return true;
      }
      else
      {
        cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
        return false;
      }
    }
    else
    {
      cout << "no piece at " << from << endl;
      return false;
    }
  }
};

#endif // CUSTOM_CHESSBOARD