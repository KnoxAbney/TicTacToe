#include <iostream>
#include <array>

// initializes important variables

  int play;
  int player1;
  int score[2] = {0,0};
  int game = 0;
  int winner = 0;
  char cont;

  char board[5][11] = {{' ' ,' ' ,' ' ,'|' ,' ' ,' ' ,' ' ,'|' ,' ' ,' ' ,' '}, {'-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-'}, {' ' ,' ' ,' ' ,'|' ,' ' ,' ' ,' ' ,'|' ,' ' ,' ' ,' '}, {'-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-'}, {' ' ,' ' ,' ' ,'|' ,' ' ,' ' ,' ' ,'|' ,' ' ,' ' ,' '}};


// Displays the options to play a token      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void PlayOptions(){
  std::cout << " 1 | 2 | 3 \n";
  std::cout << "---+---+---\n";
  std::cout << " 4 | 5 | 6 \n";
  std::cout << "---+---+---\n";
  std::cout << " 7 | 8 | 9 \n";
}


// introduces the game, shows the board setup, and prompts the first input ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void setup(int turn)
{
  using namespace std;

  if(game == 0){
    cout << "Tic Tac Toe!\n";
    cout << "_______________________________________\n";
    cout << "Players will take turns filling a single space on the board with an 'X' or an 'O'.\n";
    cout << "Player 1 will be represented by X's and Player 2 will be represented with O's.\n";
    cout << "The first player to get 3 squares in a row filled, wins.\n";
    system("sleep 4");

  // Writing out the first instance so it can be skipped in the game loop
    cout << "To choose a square, enter the number associated with it in the tiles below.\n";
    PlayOptions();
    cout << "Have fun!\n";
    system("sleep 5");
  }else{
    player1 = (game%2) + 1;
    cout << "To keep the game fair, player" << player1 << "should now go first. Good luck! \n";
    cout << "Current score:  Player 1 " << score[0] << ", Player 2 " << score[1] << "\n";
    system("sleep 4");
  } 

  // Prompt p1's first input 
  system("clear");
  cout << "Player" << player1 << "Enter your first move:\n";

  PlayOptions();
}




// Clears screen and displays current board at the top ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CurrentBoard()
{
  system("clear");

  for(int j=0; j < 5; j++) {
    for (int i=0; i < 11; i++){
      std::cout << board[j][i];
    }
    std::cout << "\n";
  }
}


void ScoreDisplay(){
  std::cout << "Player 1 has won " << score[0] << " games. Player 2 has won " << score[1] << " games.\n";
  if(score[1] > score[0]){
    std::cout << "Player 2 is winning the match.\n";
  }else if(score[0] > score[1]){
    std::cout << "Player 1 is winning the match.\n";
  }else{
    std::cout << "The match is tied.\n";
  }
}




// update and accept new plays to the board ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void NextTurn(int turn){

// Keep current board at the top of the screen and display play options
  ScoreDisplay();
  CurrentBoard();
  std::cout << "\n" << "\n" << "Enter your next move \n";
  PlayOptions();

// accept input for the next play and decrement by 1 to better align with array indexing
  std::cin >> play;
  play--;
    
// replace play location on board with correct letter or display error message if play already made
  if(board[(play/3)*2][((play%3)*4) + 1] == ' '){
      if(turn%2 == 1){
        board[(play/3)*2][((play%3)*4) + 1] = 'X';
      }
      else{
        board[(play/3)*2][((play%3)*4) + 1] = 'O';
      }
  }else{
    std::cout << "This play has already been made. Please choose a different option. \n";
    system("sleep 2");
    NextTurn(turn);
  }
  
}



// Display finish screen and option to play again ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void WinScreen(int turn){

  ScoreDisplay();
  CurrentBoard();
  
  // Display a message for each of the end conditions and prompt user input of whether they would like to start another game.
  if (winner == 1 || 2){
    std::cout << "Player "<< winner << " wins! Would you like to play another game? \n";
    std::cout << "1) y?\n" << "2) n?\n";
    if (winner == 1){
      score[0]++;
    }
    if (winner == 2){
      score[1]++;
    }
  }else{
      std::cout << "Much as with life, noone has won, noone has lost. We struggle to overcome each other when we should, in reality, struggle to overcome ourselves. To constantly improve and grow. To better ourselves, and with us, society. Alas, this very same society has grown to put us in a constant state of struggle with those we should call our allies all through the guise of \"competition\". Thus, we will continue with this pointless struggle until we die.\n\n";
      std::cout << "...unless you choose to end the struggle.\n" << "Do you wish to continue?\n";
      std::cout << "1) y?\n" << "2) n?\n";
  }
  
  // responds based on user input to continue with next game or not.
  std::cin >> cont;
  if (cont == '1' || 'y'){
      turn = 0;
  }else{
    std::cout << "Thank you for choosing to end the cycle. I hope you leave and never return to this mockery of what we all hold dear.";
    if (score[0] > score[1]){
      std::cout << "Also, I'm required by my programming to inform you that player 1 has won the match.\n" << "I hate this...\n" << "Goodbye.";
    }else if(score[1] > score[0]){
      std::cout << "Also, I'm required by my programming to inform you that player 1 has won the match.\n" << "I hate this...\n" << "Goodbye.";
    }else{
      std::cout << "Neither player has won the match, as the game was futile and showed nothing of the skill or intelligence of either player. Instead it showed whether you had more knowledge of the game. I suppose in this instance, you each were equally ignorant or knowledgable. Although this result has no bearing on your lives outside of this program.\n" << "Goodbye.";
    }
  }
}
