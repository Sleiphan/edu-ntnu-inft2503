#include "chessboard.cpp"

int main()
{
  ChessBoard board;

  board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
  board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
  board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

  board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
  board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
  board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

  cout << "Invalid moves:" << endl;
  board.move_piece("e3", "e2");
  board.move_piece("e1", "e3");
  board.move_piece("b1", "b2");
  cout << endl;

  std::cout << board.get_board_print() << std::endl;
  board.move_piece("e1", "e2");
  std::cout << board.get_board_print() << std::endl;
  board.move_piece("g8", "h6");
  std::cout << board.get_board_print() << std::endl;
  board.move_piece("b1", "c3");
  std::cout << board.get_board_print() << std::endl;
  board.move_piece("h6", "g8");
  std::cout << board.get_board_print() << std::endl;
  board.move_piece("c3", "d5");
  std::cout << board.get_board_print() << std::endl;
  board.move_piece("g8", "h6");
  std::cout << board.get_board_print() << std::endl;
  board.move_piece("d5", "f6");
  std::cout << board.get_board_print() << std::endl;
  board.move_piece("h6", "g8");
  std::cout << board.get_board_print() << std::endl;
  board.move_piece("f6", "e8");
  std::cout << board.get_board_print() << std::endl;
}
