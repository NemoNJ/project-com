#define WHITE_SQUARE 0xDB
#define BLACK_SQUARE 0xFF

void printBoard(Game& game)
{
   cout << "   A     B     C     D     E     F     G     H\n\n";

   for (int iLine = 7; iLine >= 0; iLine--)
   {
      if ( iLine%2 == 0)
      {
         // Line starting with BLACK
         printLine(iLine, BLACK_SQUARE, WHITE_SQUARE, game);
      }

      else
      {
         // Line starting with WHITE
         printLine(iLine, WHITE_SQUARE, BLACK_SQUARE, game);
      }
   }
} 

void printLine(int iLine, int iColor1, int iColor2, Game& game)
{
   // Define the CELL variable here. 
   // It represents how many horizontal characters will form one squarite
   // The number of vertical characters will be CELL/2
   // You can change it to alter the size of the board 
   // (an odd number will make the squares look rectangular)
   int CELL = 6;

   // Since the width of the characters BLACK and WHITE is half of the height, 
   // we need to use two characters in a row.
   // So if we have CELL characters, we must have CELL/2 sublines
   for (int subLine = 0; subLine < CELL/2; subLine++)
   {
      // A sub-line is consisted of 8 cells, but we can group it
      // in 4 iPairs of black&white
      for (int iPair = 0; iPair < 4; iPair++)
      {
         // First cell of the pair
         for (int subColumn = 0; subColumn < CELL; subColumn++)
         {
            // The piece should be in the "middle" of the cell
            // For 3 sub-lines, in sub-line 1
            // For 6 sub-columns, sub-column 3
            if ( subLine == 1 && subColumn == 3)
            {
               cout << char(game.getPieceAtPosition(iLine, iPair*2) != 0x20 ? 
                             game.getPieceAtPosition(iLine, iPair*2) : iColor1);
            }
            else
            {
               cout << char(iColor1);
            }
         }

         // Second cell of the pair
         for (int subColumn = 0; subColumn < CELL; subColumn++)
         {
            // The piece should be in the "middle" of the cell
            // For 3 sub-lines, in sub-line 1
            // For 6 sub-columns, sub-column 3
            if ( subLine == 1 && subColumn == 3)
            {
               cout << char(game.getPieceAtPosition(iLine,iPair*2+1) != 0x20 ? 
                              game.getPieceAtPosition(iLine,iPair*2+1) : iColor2);
            }
            else
            {
               cout << char(iColor2);
            }
         }
      }
   }
}
bool isMoveValid(Chess::Position present, Chess::Position future, 
Chess::EnPassant* S_enPassant, Chess::Castling* S_castling)

struct Round
{
  string white_move;
  string black_move;
};
std::deque<Round> rounds;

// How many rounds are stored?
rounds.size()

// Access a round
rounds[i].white_move.c_str()

// Clear the container
rounds.clear();

// Insert or remove elements
rounds.pop_back();
rounds.push_back(round);

// Save the captured pieces
std::vector<char> white_captured;
std::vector<char> black_captured;

cout << "WHITE captured: ";
for (unsigned i = 0; i < game.white_captured.size(); i++)
{
   cout << char(game.white_captured[i]) << " ";
}

cout << "black captured: ";
for (unsigned i = 0; i < game.black_captured.size(); i++)
{
   cout << char(game.black_captured[i]) << " ";
}
bool Game::isCheckMate() 

[Chess console] Saved at: Fri Feb  9 00:07:43 2018
E2-E4 | C7-C5
C2-C3 | D7-D5
void saveGame(void)
{
   string file_name;
   cout << "Type file name to be saved (no extension): ";

   getline(cin, file_name);
   file_name += ".dat";

   std::ofstream ofs(file_name);
   if (ofs.is_open())
   {
      // Write the date and time of save operation
      auto time_now = std::chrono::system_clock::now();
      std::time_t end_time = std::chrono::system_clock::to_time_t(time_now);
      ofs << "[Chess console] Saved at: " << std::ctime(&end_time);

      // Write the moves
      for (unsigned i = 0; i < current_game->moves.size(); i++)
      {
         ofs << current_game->rounds[i].white_move.c_str() << 
                " | " << current_game->moves[i].black_move.c_str() << "\n";
      }

      ofs.close();
      createNextMessage("Game saved as " + file_name + "\n");
   }
   else
   {
      cout << "Error creating file! Save failed\n";
   }

   return;
}
void printChessPiecesUnicode()
{
   _setmode(_fileno(stdout), _O_WTEXT);
   std::wcout << L'\u2654' << ' ' <<  L'\u2655' << ' ' << L'\u2656' << ' ' 
              << L'\u2657' << ' ' << L'\u2658' << ' ' << L'\u2659' << endl;
   std::wcout << L'\u265A' << ' ' <<  L'\u265B' << ' ' << L'\u265C' << ' ' 
              << L'\u265D' << ' ' << L'\u265E' << ' ' << L'\u265F' << endl;
}