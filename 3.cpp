#include<iostream>
#include<cstdlib>   // for rand(), srand()
#include<ctime>     // for time()
using namespace std;

// ─────────────────────────────────────────
//  BASE CLASS : Game
// ─────────────────────────────────────────
class Game {
private:
    char board[3][3];
    char turn;
    char winner;

public:
    // ── Constructor
    Game() {
        resetGame();
    }

    // ── Destructor
    ~Game() {
        cout << "\n[Destructor] Game object destroyed.\n";
    }

    // ── resetGame(): Reset board to initial state
    void resetGame() {
        char pos = '1';
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = pos++;
        turn   = 'X';
        winner = ' ';
        cout << "\nGame has been reset.\n";
    }

    // ── printBoard(): Display current board
    void printBoard() {
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            cout << " " << board[i][0]
                 << " | " << board[i][1]
                 << " | " << board[i][2] << "\n";
            if (i < 2)
                cout << "-----------\n";
        }
        cout << "\n";
    }

    // ── makeMove(): Place mark on board
    // Returns true if move is valid, false otherwise
    bool makeMove(int pos) {
        // Validate range
        if (pos < 1 || pos > 9) {
            cout << "Invalid position. Enter 1-9.\n";
            return false;
        }

        int row = (pos - 1) / 3;
        int col = (pos - 1) % 3;

        // Check if cell already taken
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Cell already taken. Choose another.\n";
            return false;
        }

        // Place the mark
        board[row][col] = turn;
        return true;
    }

    // ── checkWinner(): Check rows, cols, diagonals, draw
    // Returns 'X', 'O', 'D' (draw), or ' ' (ongoing)
    char checkWinner() {
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] &&
                board[i][1] == board[i][2]) {
                winner = board[i][0];
                return winner;
            }
        }

        // Check columns
        for (int j = 0; j < 3; j++) {
            if (board[0][j] == board[1][j] &&
                board[1][j] == board[2][j]) {
                winner = board[0][j];
                return winner;
            }
        }

        // Check main diagonal
        if (board[0][0] == board[1][1] &&
            board[1][1] == board[2][2]) {
            winner = board[0][0];
            return winner;
        }

        // Check anti-diagonal
        if (board[0][2] == board[1][1] &&
            board[1][1] == board[2][0]) {
            winner = board[0][2];
            return winner;
        }

        // Check draw (no empty cells left)
        bool draw = true;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    draw = false;

        if (draw) {
            winner = 'D';
            return winner;
        }

        // Game still ongoing
        return ' ';
    }

    // ── switchTurn(): Alternate between X and O
    void switchTurn() {
        turn = (turn == 'X') ? 'O' : 'X';
    }

    // ── getTurn(): Getter for current turn
    char getTurn()   { return turn;   }

    // ── getWinner(): Getter for winner
    char getWinner() { return winner; }

    // ── isCellFree(): Used by AI
    bool isCellFree(int pos) {
        int row = (pos - 1) / 3;
        int col = (pos - 1) % 3;
        return (board[row][col] != 'X' && board[row][col] != 'O');
    }
};


// ─────────────────────────────────────────
//  DERIVED CLASS : PlayerVsAI (Polymorphism)
// ─────────────────────────────────────────
class PlayerVsAI : public Game {
public:
    PlayerVsAI() : Game() {
        srand(time(0));   // seed random for AI
    }

    // ── aiMove(): AI picks a random free cell
    void aiMove() {
        int pos;
        do {
            pos = (rand() % 9) + 1;   // random 1-9
        } while (!isCellFree(pos));

        cout << "AI plays at position " << pos << "\n";
        makeMove(pos);
    }
};


// ─────────────────────────────────────────
//  FUNCTION : Run Player vs Player
// ─────────────────────────────────────────
void runPlayerVsPlayer() {
    Game g;
    int  pos;
    char result;

    g.printBoard();

    while (true) {
        cout << "Player " << g.getTurn()
             << ", enter position (1-9): ";
        cin  >> pos;

        if (!g.makeMove(pos))
            continue;   // invalid move, retry

        g.printBoard();

        result = g.checkWinner();

        if (result == 'X' || result == 'O') {
            cout << "🎉 Player " << result << " wins!\n";
            break;
        }
        if (result == 'D') {
            cout << "It's a draw!\n";
            break;
        }

        g.switchTurn();
    }
}


// ─────────────────────────────────────────
//  FUNCTION : Run Player vs AI
// ─────────────────────────────────────────
void runPlayerVsAI() {
    PlayerVsAI g;
    int  pos;
    char result;

    cout << "\nYou are X. AI is O.\n";
    g.printBoard();

    while (true) {
        // ── Human turn (X)
        cout << "Your turn (X). Enter position (1-9): ";
        cin  >> pos;

        if (!g.makeMove(pos))
            continue;

        g.printBoard();
        result = g.checkWinner();

        if (result == 'X') { cout << "You win!\n";    break; }
        if (result == 'D') { cout << "It's a draw!\n"; break; }

        g.switchTurn();

        // ── AI turn (O)
        cout << "AI's turn (O)...\n";
        g.aiMove();
        g.printBoard();
        result = g.checkWinner();

        if (result == 'O') { cout << "AI wins!\n";    break; }
        if (result == 'D') { cout << "It's a draw!\n"; break; }

        g.switchTurn();
    }
}


// ─────────────────────────────────────────
//  MAIN — Menu Driven
// ─────────────────────────────────────────
int main() {
    int choice;

    cout << "==============================\n";
    cout << "      TIC-TAC-TOE GAME        \n";
    cout << "==============================\n";

    do {
        cout << "\n--------- MAIN MENU ---------\n";
        cout << "1. Player vs Player\n";
        cout << "2. Player vs AI\n";
        cout << "3. Exit\n";
        cout << "Enter choice: "; cin >> choice;

        switch (choice) {
            case 1: runPlayerVsPlayer(); break;
            case 2: runPlayerVsAI();     break;
            case 3: cout << "Thanks for playing!\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 3);

    return 0;
}