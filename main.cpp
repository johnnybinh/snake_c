#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>

#define WIDTH 40
#define HEIGHT 21
#define pacman 'C'
#define WALL '#'
#define FOOD 'o'
#define MONSTER 'X'
#define EMPTY ' '

// declare var
int res = 0;
int score = 0;
int pacman_x, pacman_y;
char board[HEIGHT][WIDTH];
int food = 0;
int curr = 0;

void init()
{
  srand(time(0));
  // border
  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1)
      {
        board[i][j] = WALL;
      }
      else
      {
        board[i][j] = EMPTY;
      }
    }
  }
  // walls;
  for (int i = 3; i <= 5; i++)
  {
    for (int j = 5; j < 35; j++)
    {
      board[i][j] = WALL;
    }
  }
  for (int i = 15; i <= 17; i++)
  {
    for (int j = 5; j < 35; j++)
    {
      board[i][j] = WALL;
    }
  }
  for (int i = 8; i <= 12; i++)
  {
    for (int j = 10; j < 15; j++)
    {
      board[i][j] = WALL;
    }
    for (int j = 25; j < 30; j++)
    {
      board[i][j] = WALL;
    }
  }
  // FOOD
  int count = 10;
  while (count != 0)
  {
    int i = (rand() % (HEIGHT + 1));
    int j = (rand() % (WIDTH + 1));

    if (board[i][j] != WALL && board[i][j] != pacman)
    {
      board[i][j] = FOOD;
      food++;
      count--;
    }
  }
  // init pacman
  pacman_x = WIDTH / 2;
  pacman_y = HEIGHT / 2;
  board[pacman_y][pacman_x] = pacman;
}

void draw()
{
  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      printf("%c", board[i][j]);
    }
    printf(" \n");
  }
  printf("score: ");
  printf("food left: ");
}

void Move(int move_x, int move_y)
{
  int x = pacman_x + move_x;
  int y = pacman_y + move_y;

  // collision
  if (board[y][x] != WALL)
  {
    if (board[y][x] == FOOD)
    {
      score++;
    }
  }
}

int main()
{
  init();
  draw();
}