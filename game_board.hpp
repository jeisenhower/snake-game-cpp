#include "snake.hpp"
#include <SFML/Graphics.hpp>

// Possible improvements: Create a buffer that listens and stores key pressed events on a different thread so we can just pull from the 
// buffer in order to make the snake more consistently responsive. Maybe consider using interrupts on a separate thread along with the buffer?
// Or maybe even just set it so that the interrupt changes the direction of the snake. I am not sure how this would affect performance of the
// rest of the project, though. Need to look into how to set up interrupts and multithread this.


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