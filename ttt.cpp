#include <iostream>
#include <vector>
#include "ttt.hpp"

int main (){

  for(int turn = 1; turn<=9; turn++){

    if(turn == 1){
    setup(turn);
    }

    NextTurn(turn);

  }

  CurrentBoard();

}
