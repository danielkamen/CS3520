

void game(int numDoodle, int numQueen, int numMale, int numWorker);

void generate_points(int *bugx, int *bugy, int width, int height, int x_offset, int y_offset);



enum State{INIT, ALIVE, DEAD, EXIT};


void setEndScreen(int timeToEnd);