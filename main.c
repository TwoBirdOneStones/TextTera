#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define WORLD_WIDTH 25
#define WORLD_HEIGHT 25

enum BlockType {
  Air = 0,
  Dirt = 1,
  Stone = 2,
};

typedef struct {
  int x;
  int y;
} Position;

typedef struct {
  Position position;
} Transform;


typedef struct {
  enum BlockType type;
  Transform transform;
} Block;

Block blocks[WORLD_WIDTH][WORLD_HEIGHT];

void SeedRandom(void);
void LoadWorldFile(void);

int main(){
  LoadWorldFile();
  return 0;
}

void SeedRandom() {
  srand(time(NULL));
}

void LoadWorldFile() {
  FILE *worldFile = fopen("world.txt", "r");
  if (worldFile == NULL) {
    printf("File not found\n");
  }
}


