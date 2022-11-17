#include <iostream>
#include <string>
#include "snake.hpp"


Snake::Snake() {
  // Generate a random place for the initial fruit position.
  generateFruit();
}


int Snake::get_length() {
  return length;
};

char Snake::get_direction() {
  return direction;
};

void Snake::set_direction(char new_direction) {
  direction = new_direction;
};

int Snake::get_width() {
  return width;
};

int Snake::get_height() {
  return height;
};

int Snake::get_piece_size() {
  return piece_size;
};

int Snake::get_x(int pos) {
  if (0 <= pos < length) {
    return x[pos]; 
  }
  return -1;
};
 
int Snake::get_y(int pos) {
  if (0 <= pos < length) {
    return y[pos];
  }
  return -1;
};

std::vector<int> Snake::get_x() {
  return x;
};

std::vector<int> Snake::get_y() {
  return y;
};


void Snake::move() {
  
  switch(direction) {
    case 'u': head_y -= piece_size; break;
    case 'd': head_y += piece_size; break;
    case 'l': head_x -= piece_size; break;
    case 'r': head_x += piece_size; break;
  }

  // Check if the snake is out of bounds. If it is, move it back into window on opposite side
  if (head_x >= width) {
    head_x = 0;
  } else if (head_x <= 0) {
    head_x = width-piece_size;
  }
  if (head_y >= height) {
    head_y = 0;
  } else if (head_y <= 0) {
    head_y = height - piece_size;
  }

    for (int i=0; i<length; i++) {
    if (x[i] >= width) {
      x[i] = 0;
    } else if (x[i] <= 0) {
      x[i] = width/piece_size;
    }
    
    if (y[i] >= height) {
      y[i] = 0;
    } else if (y[i] <= 0) {
      y[i] = height - piece_size;
    }
  }

  

  x.push_back(head_x);
  y.push_back(head_y);

  // Doing this accounts for when we grow the snake, since if it hits an apple we grow
  if (x.size() > length) {
    // Remove the first element of the snake (the tail)
    x.erase(x.begin());
    y.erase(y.begin());
  }



 

};

void Snake::grow() {
  length++;
};

bool Snake::isOnSelf() {
  if (length > 1) {
    for (int i=0; i<length-1; i++) {
      if (head_x == x[i] && head_y == y[i]) {
        return true;
      }
    }
  }
  
  return false;
};

bool Snake::isOnFruit() {
  // Check if the head coords equal the fruit coords
  if (head_x == fruit_x && head_y == fruit_y) {
    return true;
  }
  return false;
};

void Snake::generateFruit() {
  // Generate an x value between origin and width/piece_size
  fruit_x = (random_num(3, (width/piece_size) - 3)) * piece_size;
  // Generate random y value between origin and height/piece_size
  fruit_y = (random_num(3, (height/piece_size) - 3)) * piece_size;
  // Multiply x and y values by piece_size to get the coords of the new fruit
}


int Snake::random_num(int low, int high) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(low, high);
  return dist(gen);
}



Snake::~Snake() {

};