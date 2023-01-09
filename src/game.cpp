#include "../headers/game.h"
#include "../headers/texture.h"
#include "../headers/renderer.h"

Renderer *renderer;

Game::Game()
{
    init();
}

Game::~Game()
{
    delete renderer;
}

void Game::init()
{
    gb = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}; 
    generateRandomTile();

    Shader shader;
    renderer = new Renderer(shader);
    

    // Tex2D board = loadTexture("textures/board.png", false);
    // Tex2D tile_0 = loadTexture("textures/0.png", false);
    // Tex2D tile_2 = loadTexture("textures/2.png", false);
    // Tex2D tile_4 = loadTexture("textures/4.png", false);
    // Tex2D tile_8 = loadTexture("textures/8.png", false);
    // Tex2D tile_16 = loadTexture("textures/16.png", false);
    // Tex2D tile_32 = loadTexture("textures/32.png", false);
    // Tex2D tile_64 = loadTexture("textures/64.png", false);
    // Tex2D tile_128 = loadTexture("textures/128.png", false);
    // Tex2D tile_256 = loadTexture("textures/256.png", false);
    // Tex2D tile_512 = loadTexture("textures/512.png", false);
    // Tex2D tile_1024 = loadTexture("textures/1024.png", false);
    // Tex2D tile_2048 = loadTexture("textures/2048.png", false);


}

void Game::processInput()
{
    if (keys[GLFW_KEY_W])
        moveUp();

    if (keys[GLFW_KEY_A])
        moveLeft();

    if (keys[GLFW_KEY_S])
        moveDown();

    if (keys[GLFW_KEY_D])
        moveRight();
}

void Game::moveLeft()
{
    if (!canMergeRow())
        return; 

    for (auto row = 0; row < board_sz; ++row)
    slide(gb[row]);

    generateRandomTile();
}



void Game::moveRight()
{
    if (!canMergeRow())
        return;

    for (auto row = 0; row < board_sz; ++row)
    {
        std::reverse(gb[row].begin(), gb[row].end());
        slide(gb[row]);
        std::reverse(gb[row].begin(), gb[row].end());

    }

    generateRandomTile();
}


void Game::moveUp()
{
    if (!canMergeCol())
        return;

    for (auto col = 0; col < board_sz; ++col)
    {
        Row col_transpose = {gb[0][col], gb[1][col], gb[2][col], gb[3][col]};
        slide(col_transpose);

        for (auto row = 0; row < board_sz; ++row)
            gb[row][col] = col_transpose[row];
    }

    generateRandomTile();
}



void Game::moveDown()
{
    if (!canMergeCol())
        return;

    for (auto col = 0; col < board_sz; ++col)
    {
        Row col_transpose = {gb[0][col], gb[1][col], gb[2][col], gb[3][col]};
        std::reverse(col_transpose.begin(), col_transpose.end());
        slide(col_transpose);
        std::reverse(col_transpose.begin(), col_transpose.end());
        for (auto row = 0; row < board_sz; ++row)
            gb[row][col] = col_transpose[row];
    }

    generateRandomTile();
}




void Game::generateRandomTile()
{
    std::vector<std::pair<int, int>> empty;
    for (auto row = 0; row < board_sz; ++row)
    {
        for (auto col = 0; col < board_sz; ++col)
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
    for (auto i = 0; i < board_sz - 1; ++i)
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

    while (r.size() < board_sz)
        r.push_back(0);
}


void Game::debug() const
{
    for (auto row = 0; row < board_sz; ++row)
    {
        for (auto col = 0; col < board_sz; ++col)
        {
            std::cout << gb[row][col] << " ";
        }
        std::cout << "\n" << std::endl;
    }
}

bool Game::canMergeRow() const
{
    for (auto row = 0; row < board_sz; ++row)
    {
        for (auto col = 0; row < board_sz - 1; ++col)
        {
            if (gb[row][col] == gb[row][col+1])
                return true;
        }
    }

    return false;
}

bool Game::canMergeCol() const
{
    for (auto col = 0; col < board_sz; ++col)
    {
        Row col_transpose = {gb[0][col], gb[1][col], gb[2][col], gb[3][col]};
        for (auto i = 0; i < board_sz; ++i)
        {
            if (col_transpose[i] == col_transpose[i+1])
                return true;
        }
    }

    return false;

}

bool Game::check2048() const
{
    for (auto row = 0; row < board_sz; ++row)
    {
        for (auto col = 0; col < board_sz; ++col)
        {
            if (gb[row][col] == 2048)
                return true;
        }
    }

    return false;
}


bool Game::check0() const
{
    for (auto row = 0; row < board_sz; ++row)
    {
        for (auto col = 0; col < board_sz; ++col)
        {
            if (gb[row][col] == 0)
                return true;
        }
    }

    return false;
}

bool Game::gameOver() const
{
    if (check2048())
        return true;

    if (!check0())
        return true;

    if (!canMergeRow() || !canMergeCol())
        return true;

    return false;

    
}


void Game::update()
{

}

void Game::render()
{
    Tex2D board_background = loadTexture("textures/board.png", false);


    for (auto row = 0; row < board_sz; ++row)
    {
        for (auto col = 0; col < board_sz; ++col)
        {

            // render the appropiate texture and positions
        }
    }
}