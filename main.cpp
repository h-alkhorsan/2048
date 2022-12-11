#include "game.h"

char process_input() {char c; std::cin >> c; return c;}

GameBoard gb = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};
Game two_zero_four_eight(gb);


int main()
{

    char input;
    while (input != 'q')
    {

        input = process_input();

    
        if (input == 'a')
            two_zero_four_eight.moveLeft(gb);

        else if (input == 'd')
            two_zero_four_eight.moveRight(gb);

        else if (input == 'w')
            two_zero_four_eight.moveUp(gb);


        else if (input == 's')

            two_zero_four_eight.moveDown(gb);
    

        two_zero_four_eight.debug(gb);
    }
    
    return 0;
}