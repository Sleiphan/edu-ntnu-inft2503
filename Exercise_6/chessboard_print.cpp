#include "chessboard.cpp"

class ChessBoardPrint
{
public:
  ChessBoardPrint(ChessBoard &board)
  {
    board.post_move_cb = [](const ChessBoard::Piece &p, const std::string &from, const std::string &to)
    { cout << p.type() << " is moving from " << from << " to " << to << endl; };

    board.cannot_move_cb = [](const ChessBoard::Piece &piece, const std::string &from, const std::string &to)
    { cout << "can not move " << piece.type() << " from " << from << " to " << to << endl; };

    board.piece_removed_cb = [](const ChessBoard::Piece &piece, const std::string &from)
    { cout << piece.type() << " is being removed from " << from << endl; };

    board.piece_not_found_cb = [](const std::string &from)
    { std::cout << "no piece at " << from << std::endl; };

    board.lost_game_cb = [](const std::string &faction)
    { cout << faction << " lost the game" << endl; };
  }
};