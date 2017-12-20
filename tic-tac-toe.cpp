#include <iostream>
using namespace std;

void printInitialMessage();
void printPlayerMessage(int);
void printInvalidMessage();
void printBoard(int [3][3]);
void registerMove(int [3][3], int, int);
void initializeBoard(int [3][3]);
char getSymbol(int);
bool checkValidMove(int [3][3], int);
bool checkWinner(int [3][3]);
void printEndGameMessage(int, int);

int main() {

  int board[3][3];
  int player = 0, numJogadas = 0;
  int move;

  printInitialMessage();
  initializeBoard(board);
  do {
    printPlayerMessage(player);
    
    cin >> move;
    if(checkValidMove(board, move)) {
      registerMove(board, move, player);
      printBoard(board);
      player = (player + 1) % 2; 
      numJogadas++;
    } else {
      printInvalidMessage();
    }
  } while (!checkWinner(board) && (numJogadas != 9));

  printEndGameMessage(player, numJogadas);
  return 0;
}

void printInitialMessage() {
  cout << "Bem vindo ao Tic-Tac-Toe" << endl;
}

void printInvalidMessage() {
  cout << "Jogada inválida. Jogue novamente" << endl;
}

void initializeBoard(int board[3][3]) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      board[i][j] = -1;
    }
  }
}

void printPlayerMessage(int player) {
  cout << "Vez do jogador ";
  if(player == 0) {
    cout << 1 << " (jogardor X): ";
  } else {
    cout << 2 << " (jogador O): ";
  }
}

void registerMove(int board[3][3], int move, int player) {
  switch(move) {
    case 1:
      board[2][0] = player;
      break;
    case 2:
      board[2][1] = player;
      break;
    case 3:
      board[2][2] = player;
      break;
    case 4:
      board[1][0] = player;
      break;
    case 5:
      board[1][1] = player;
      break;
    case 6:
      board[1][2] = player;
      break;
    case 7:
      board[0][0] = player;
      break;
    case 8:
      board[0][1] = player;
      break;
    case 9:
      board[0][2] = player;
      break;
  }
}

void printBoard(int board[3][3]) {
  char symbol;
  for(int i = 0; i <= 2; i++) {
    for (int j = 0; j <= 2; j++) {
      symbol = getSymbol(board[i][j]);
      cout << ' ' << symbol << ' ';
      if (j != 2) {
        cout << '|';
      } else {
        cout << endl;
      }
    }
    if (i != 2) {
      cout << "---+---+---";
    }
    cout << endl;
  }
}

char getSymbol(int symbol) {
  if (symbol == 1) {
    return 'O';
  } else if (symbol == 0) {
    return 'X';
  } else {
    return ' ';
  }
}

bool checkWinner(int board[3][3]) {
  if(board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][2] != -1 ||
     board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][2] != -1 ||
     board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][2] != -1 ||
     board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[2][0] != -1 ||
     board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[2][1] != -1 ||
     board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2] != -1 ||
     board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != -1 ||
     board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[0][2] != -1) {
       return true;
     }
  return false;
}

bool checkValidMove(int board[3][3], int move) {
  switch(move) {
    case 1:
      if(board[2][0] == -1) {
        return true;
      } else {
        return false;
      }
      break;
    case 2:
      if(board[2][1] == -1) {
        return true;
      } else {
        return false;
      }
      break;
    case 3:
      if(board[2][2] == -1) {
        return true;
      } else {
        return false;
      }
      break;
    case 4:
      if(board[1][0] == -1) {
        return true;
      } else {
        return false;
      }
      break;
    case 5:
      if(board[1][1] == -1) {
        return true;
      } else {
        return false;
      }
      break;
    case 6:
      if(board[1][2] == -1) {
        return true;
      } else {
        return false;
      }
      break;
    case 7:
      if(board[0][0] == -1) {
        return true;
      } else {
        return false;
      }
      break;
    case 8:
      if(board[0][1] == -1) {
        return true;
      } else {
        return false;
      }
      break;
    case 9:
      if(board[0][2] == -1) {
        return true;
      } else {
        return false;
      }
      break;
    default:
      return false;
  }
}

void printEndGameMessage(int player, int numJogadas) {
  if(numJogadas == 9) {
    cout << "Deu velha!" << endl;
  } else {
    cout << "Jogador ";
    if(player == 0) {
      cout << 2;
    } else {
      cout << 1;
    }
    cout << " venceu!!!" << endl;
  }
}