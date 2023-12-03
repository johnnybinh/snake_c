
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

int width = 50;
int height = 20;
int i, j;
int gameOver;
int score;

class




void draw()
{
  int map[] =
      {
          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
          1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
          1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
          1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
          1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
          1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  int maplength = sizeof(map) / sizeof(map[0]);
  printf("%d\n", maplength);
  for (int i = 0; i < maplength; i++)
  {
    if (map[i] == 0)
    {
      printf(" ");
    }
    if (map[i] == 1)
    {
      printf("#");
    }
    if (map[i] == 2)
    {
      printf("#\n");
    }
  }
}
void setup()
{
  srand(time(NULL));
  
}
void update()
{
}
void movement()
{
}

int main()
{
  draw();
  return 0;
}
