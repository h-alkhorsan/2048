#ifndef GAME_H
#define GAME_H

#include <vector>
#include <algorithm>
#include <iostream>


using Row = std::vector<int>;
using GameBoard = std::vector<std::vector<int>>;


class Game { 

public:
    Game(GameBoard &gb) {generateRandomTile(gb);}
        
    void moveLeft(GameBoard &gb);
    void moveRight(GameBoard &gb);
    void moveUp(GameBoard &gb);
    void moveDown(GameBoard &gb);
    void debug(GameBoard &gb);


private:
    constexpr int board_size() {return 4;}
    void generateRandomTile(GameBoard &gb);
    void filterZeros(Row &r);
    void merge(Row &r);
    void slide(Row &r);

};

#endif