#include "snake.hpp"
#include <SFML/Graphics.hpp>

class GameBoard {
    Snake snake;
    int height = 600;
    int width = 600;
    sf::RenderWindow window;


    
    public:
        int piece_size = 25;
        int total_pieces = 576;
        bool game_won = false;
        bool game_over = false;
        //GameBoard();
        GameBoard(Snake &new_snake);
        int get_total_pieces();
        void play();
        void print_snake_pieces();
        ~GameBoard();
};