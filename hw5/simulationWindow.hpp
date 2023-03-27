
#define WELL_WIDTH 100
#define WELL_HEIGHT 100


using namespace std;


struct gamewindow_t
{
  int upper_left_x;
  int upper_left_y;
  int width;
  int height;
  char draw_char;
  char color[3];
};

typedef struct gamewindow_t gamewindow_t;

gamewindow_t *init_GameWindow(int, int, int, int);
gamewindow_t *changeGameWindow(int upper_left_x, int upper_left_y, int width, int height, gamewindow_t *);

void undraw_Gamewindow(gamewindow_t *);
void draw_Gamewindow(gamewindow_t *);
