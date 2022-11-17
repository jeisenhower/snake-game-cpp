#include <string>
#include <vector>
#include <random>

// This class controls a snake in the terminal

class Snake {
  int length = 1;
  const int piece_size = 25;
  const double speed = 75;
  const int height = 600;
  const int width = 600;
  const int total_pieces = (height*width)/piece_size;
  char direction = 'd';
  


  public:
    int head_x = 25;
    int head_y = 50;
    int fruit_x;
    int fruit_y;
    std::vector<int> x = {head_x};
    std::vector<int> y = {head_y};
    Snake();
    void move();
    int get_length();
    int get_piece_size();
    int get_width();
    int get_height();
    void set_direction(char new_direction);
    char get_direction();
    void set_x(int* new_x);
    void set_y(int* new_y);
    int get_x(int pos);
    int get_y(int pos);
    std::vector<int> get_x();
    std::vector<int> get_y();
    void grow(); 
    bool isOnSelf();
    bool isOnFruit();
    void generateFruit();
    static int random_num(int low, int high);

    ~Snake();
};