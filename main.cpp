#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

#define WIDTH 40
#define HEIGHT 21
#define pacman 'C'
#define WALL '#'
#define FOOD 'o'
#define MONSTER 'X'
#define EMPTY ' '

//declare var
int res = 0;
int score = 0;
int pacman_x, pacman_y;
char board[HEIGHT][WIDTH];
int food = 0;
int curr = 0;

void init(){
  //border
  for(int i = 0; i < HEIGHT; i++){
    for(int j = 0; j < WIDTH; j++){
      if(i == 0 || i == HEIGHT  -1 || j == 0 || j == WIDTH -1){
        board[i][j] = WALL;
      }
      else{
        board[i][j] = EMPTY;
      }
    }
  }
  // walls;
  int count = 10;
  while(count != 0){
    for(int i = 2; i < WIDTH; i = i + 2){
      for(int j = 2; j < 38; j++){
      board[i][j] = WALL;
    }
  }
    
    count--;
  }
}

void draw(){
  for (int i = 0; i < HEIGHT; i++){
    for(int j = 0; j < WIDTH; j++){
      printf("%c", board[i][j]);
    }
    printf(" \n");
  }
}


int main(){
  init();
  draw();
}