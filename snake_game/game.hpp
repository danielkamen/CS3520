
void game();
void generate_points(int *food_x, int *food_y, int width, int height, int x_offset, int y_offset);
enum State{INIT, ALIVE, DEAD, EXIT};
void generate_Obstacl_Point(int *obs_x, int *obs_y, int width, int height,
                     int x_offset, int y_offset, int sizeOfObstacleX, int sizeOfObstacleY);
typedef struct Snake Snake;
Snake* instantiateDeadSnake(Snake* snake, int OldSize, int width, int height, int x_offset, int y_offset);
void setEndScreen(int score, int length);