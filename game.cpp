#include "game.h"


void Game::moveLeft(GameBoard &gb)
{
    for (auto row = 0; row < board_size(); ++row)
    slide(gb[row]);

    generateRandomTile(gb);
}



void Game::moveRight(GameBoard &gb)
{
    for (auto row = 0; row < board_size(); ++row)
    {
        std::reverse(gb[row].begin(), gb[row].end());
        slide(gb[row]);
        std::reverse(gb[row].begin(), gb[row].end());

    }

    generateRandomTile(gb);
}


void Game::moveUp(GameBoard &gb)
{
    for (auto col = 0; col < board_size(); ++col)
    {
        Row col_transpose = {gb[0][col], gb[1][col], gb[2][col], gb[3][col]};
        slide(col_transpose);

        for (auto row = 0; row < board_size(); ++row)
            gb[row][col] = col_transpose[row];
    }

    generateRandomTile(gb);
}



void Game::moveDown(GameBoard &gb)
{
    for (auto col = 0; col < board_size(); ++col)
    {
        Row col_transpose = {gb[0][col], gb[1][col], gb[2][col], gb[3][col]};
        std::reverse(col_transpose.begin(), col_transpose.end());
        slide(col_transpose);
        std::reverse(col_transpose.begin(), col_transpose.end());
        for (auto row = 0; row < board_size(); ++row)
            gb[row][col] = col_transpose[row];
    }

    generateRandomTile(gb);
}



void Game::generateRandomTile(GameBoard &gb)
{
    std::vector<std::pair<int, int>> empty;
    for (auto row = 0; row < board_size(); ++row)
    {
        for (auto col = 0; col < board_size(); ++col)
        {
            if (gb[row][col] == 0)
                empty.push_back(std::make_pair(row, col));
        }
    }

    int randIdx = rand() % empty.size();
    std::pair<int, int> pos = empty[randIdx];

    if (randIdx < empty.size() / 2)
        gb[pos.first][pos.second] = 2;
    else
        gb[pos.first][pos.second] = 4;   

}

void Game::filterZeros(Row &r)
{   
    auto first_zero = std::partition(r.begin(), r.end(), [](int i) {return i != 0; });

    r.erase(first_zero, r.end());

    // r.erase(
    //     std::remove_if(r.begin(), r.end(), [](int i = 0) {return i == 0;}),
    // r.end());
    

}


void Game::merge(Row &r)
{
    for (auto i = 0; i < board_size()-1; ++i)
    {
        if (r[i] == r[i+1])
        {
            r[i] *= 2;
            r[i+1] = 0;
        }
    }

}

void Game::slide(Row &r)
{
    filterZeros(r);
    merge(r);
    filterZeros(r);

    while (r.size() < board_size())
        r.push_back(0);
}


void Game::debug(GameBoard &gb)
{
    for (auto row = 0; row < board_size(); ++row)
    {
        for (auto col = 0; col < board_size(); ++col)
        {
            std::cout << gb[row][col] << " ";
        }
        std::cout << "\n" << std::endl;
    }
}