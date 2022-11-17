//#include <SFML/Graphics.hpp>
#include "game_board.hpp"
#include <iostream>
#include <chrono>
#include <thread>


// POTENTIAL OPTIMIZATION: What if we did the drawing in the portion of the code where we check if the snake is on top of itself? Would that make any noticeable 
// difference? I have been led to believe that it wouldn't make any noticeable difference, but it would be worth experimenting with potentially. For now, I am 
// going to stick with looping back through the snake to draw the pieces.

GameBoard::GameBoard(Snake &new_snake) : snake(new_snake) {
    // Display the game board, delay for 2 seconds, then call the play method
    window.create(sf::VideoMode(600, 600), "Snake");
    window.clear(sf::Color::Black);

    // Draw the snake on the gameboard
    sf::RectangleShape snake_piece(sf::Vector2f(piece_size, piece_size));
    snake_piece.setPosition(snake.head_x, snake.head_y);
    window.draw(snake_piece);
    window.display();
    
    // Delay for 2-3 seconds
    

    play();
};

void GameBoard::play() {

    while(!game_over && !game_won && window.isOpen()) {
    //while(window.isOpen()) {    

        // Clear the window
        window.clear(sf::Color::Black);


        // Check for events such as window closed or arrow keys pressed
        sf::Event e;

        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                game_over = true;
                window.close();
            }
        }

        // Check if any of the keyboard arrow keys were pressed. If they are, then change
        // the direction of the snake accordingly
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            snake.set_direction('r');
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            snake.set_direction('l');
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            snake.set_direction('u');
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            snake.set_direction('d');
        }

        // Check if the snake collieded with anything out of bounds
        if (snake.isOnSelf()) {
            // Set game over to true
            game_over = true;
        }
        // Check if the snake has gone over a fruit
        if (snake.isOnFruit()) {
            // Grow the snake by one unit
            snake.grow();
            if (snake.get_length() >= total_pieces) {
                game_won = true;
            }
            snake.generateFruit();
        }

        // Move the snake
        snake.move();
        
        // TODO: Draw the snake on the screen at the locations specified in the vectors storing the snake body
        /*for (int i=0; i<snake.get_length(); i++) {
            // Draw a box of length and width piece size starting at x[i] and y[i]
            sf::RectangleShape snake_piece(sf::Vector2f(piece_size, piece_size));
            std::cout << "x: " << snake.x[i] << ", y: " << snake.y[i] << "\n";
            if (i == snake.get_length() - 1) {
                snake_piece.setFillColor(sf::Color::Green);
            } else {
                snake_piece.setFillColor(sf::Color::Blue);
            }

            snake_piece.setPosition(snake.x[i], snake.y[i]);
            window.draw(snake_piece);
        }*/

        // Draw the snake on the screen at the locations specified in the vectors storing the snake body
        sf::RectangleShape snake_piece(sf::Vector2f(piece_size, piece_size));

        for (int i=0; i<snake.get_length(); i++) {
            // Draw a box of length and width piece size starting at x[i] and y[i]
            
            if (i == snake.get_length() - 1) {
                snake_piece.setFillColor(sf::Color::Green);
            } else {
                snake_piece.setFillColor(sf::Color::Blue);
            }

            snake_piece.setPosition(snake.x[i], snake.y[i]);
            window.draw(snake_piece);
        }

        // Draw fruit on board
        //sf::RectangleShape fruit(sf::Vector2f(piece_size, piece_size));
        sf::CircleShape fruit(piece_size/2);
        fruit.setFillColor(sf::Color::Red);
        fruit.setPosition(snake.fruit_x, snake.fruit_y);
        window.draw(fruit);
        window.display();

        // Set a delay before next loop iteration begins
        std::this_thread::sleep_for(std::chrono::milliseconds(55));
    }

    if (game_over) {
        // Display the game over message
        std::cout << "Game over\n" << "Your Score: " << snake.get_length() << "\n";
    } else if (game_won) {
        // Display the winner message
        std::cout << "Winner!!!! We thought that was impossible!\n";
    } else {
        // Display an error message
        std::cout << "Error\n";
    }

};

void GameBoard::print_snake_pieces() {
    for (int i=0; i < snake.get_length(); i++) {
        std::cout << snake.get_x(i) << ", " << snake.get_y(i) << "\n";
    }
};


GameBoard::~GameBoard() {

};