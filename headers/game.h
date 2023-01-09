#ifndef GAME_H
#define GAME_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <glad/glad.h>

#include "GLFW/glfw3.h"

using Row = std::vector<int>;
using GameBoard = std::vector<std::vector<int>>;

class Game { 
public:
    Game();

        
    void init();

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    bool gameOver() const;
    bool keys[1024];
    GameBoard getBoard() const {return gb;}
    void debug() const;

    void processInput();
    void update();
    void render();

    ~Game();


private:
    bool canMergeRow() const;
    bool canMergeCol() const;
    bool check2048() const;
    bool check0() const;

    // constexpr int board_size() {return 4;}
    void generateRandomTile();
    void filterZeros(Row &r);
    void merge(Row &r);
    void slide(Row &r);

    GameBoard gb; //= {{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};
    const int board_sz = 4;
};

#endif