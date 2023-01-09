#include "headers/game.h"

char process_input() {char c; std::cin >> c; return c;}

Game two_zero_four_eight;


int main()
{

    char input;
    while (input != 'q' && !two_zero_four_eight.gameOver())
    {

        input = process_input();

    
        if (input == 'a')
            two_zero_four_eight.moveLeft();

        else if (input == 'd')
            two_zero_four_eight.moveRight();

        else if (input == 'w')
            two_zero_four_eight.moveUp();


        else if (input == 's')

            two_zero_four_eight.moveDown();
    

        two_zero_four_eight.debug();
    }
    
    return 0;
}
