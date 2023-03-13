#include <iostream>
#include <vector>
#include "ttt.hpp"

int main (){

  bool end = false;
  int turn = 1;

  while(end == false){
    
    if(turn == 1){

    setup(turn);

    }

    NextTurn(turn);
    turn = WinScreen(turn);
    end = EndCheck();
    turn++;


  }

  CurrentBoard();

}
