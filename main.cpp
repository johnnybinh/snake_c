
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <stdbool.h>
#include <iostream>

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
int mon_x = 2;
int mon_y = 5;
char board[HEIGHT][WIDTH];
int food = 0;
int curr = 0;

// for macos only
#include <termios.h>
#include <unistd.h>

char getch()
{
  char buf = 0;
  struct termios old = {0};
  if (tcgetattr(0, &old) < 0)
    perror("tcsetattr()");
  old.c_lflag &= ~ICANON;
  old.c_lflag &= ~ECHO;
  old.c_cc[VMIN] = 1;
  old.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, &old) < 0)
    perror("tcsetattr ICANON");
  if (read(0, &buf, 1) < 0)
    perror("read()");
  old.c_lflag |= ICANON;
  old.c_lflag |= ECHO;
  if (tcsetattr(0, TCSADRAIN, &old) < 0)
    perror("tcsetattr ~ICANON");
  return buf;
}

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
      food = food + 1;
      count--;
    }
  }
  // init pacman
  pacman_x = WIDTH / 2;
  pacman_y = HEIGHT / 2;
  board[pacman_y][pacman_x] = pacman;

  board[mon_y][mon_x] = MONSTER;
}

void draw()
{
  system("cls");
  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      printf("%c", board[i][j]);
    }
    printf(" \n");
  }
  printf("score:%d \n", score);
  printf("food left:%d \n", food);
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
      food--;
      if (food == 0)
      {
        res = 2;
        return;
      }
    }
    board[pacman_y][pacman_x] = EMPTY;
    pacman_x = x;
    pacman_y = y;
    board[pacman_y][pacman_x] = pacman;
  }
}

void moveMonster(int move_x, int move_y)
{
  int x = mon_x + move_x;
  int y = mon_y + move_y;

  if (board[y][x] != WALL)
  {
    if (board[y][x] != FOOD)
    {
      board[mon_y][mon_x] = EMPTY;
      mon_x = x;
      mon_y = y;
      board[mon_y][mon_x] = MONSTER;
    }
  }
}

int main()
{
  char in;
  int rng;
  init();
  bool gameEnd = false;
  while (gameEnd != true)
  {

    draw();
    in = getch();
    switch (in)
    {
    case 'w':
      Move(0, -1);
      break;
    case 'a':
      Move(-1, 0);
      break;
    case 's':
      Move(0, 1);
      break;
    case 'd':
      Move(1, 0);
      break;

    case 'q':
      printf("exited!");
      gameEnd = true;
      break;
    }

    rng = rand() % 4 + 1;
    switch (rng)
    {
    case 1:
      moveMonster(0, 1);
    case 2:
      moveMonster(1, 0);
    case 3:
      moveMonster(0, -1);
    case 4:
      moveMonster(0, 1);
    }

    if (res == 2)
    {
      printf("Hooray");
      break;
      gameEnd = true;
    }
  }
}