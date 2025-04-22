#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

#define WORLD_WIDTH 5
#define WORLD_HEIGHT 5

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

Block blocks[WORLD_WIDTH][WORLD_HEIGHT] = {{0}, {0}};
char worldStrip[WORLD_WIDTH] = {0};

void SeedRandom(void);
void LoadWorldFile(void);
Block* GetBlockAt(int x, int y);
void SetBlockType(Block* _block, enum BlockType _type);
void SetBlockPos(Block* _block, int _x, int _y);


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
  int _hight = 0;
  while (fgets(worldStrip, sizeof(worldStrip), worldFile)) {
    for (int i = 0; i < WORLD_WIDTH; i++) {
      enum BlockType _blockType = (enum BlockType)(worldStrip[i] - '0');
      Block* _block = GetBlockAt(i, _hight);
      SetBlockType(_block, _blockType);
    };
    _hight++;
  }
  fclose(worldFile);
}

Block* GetBlockAt(int x, int y) {
  return &blocks[y][x];
}

void SetBlockType(Block* _block, enum BlockType _type) {
  _block->type = _type;
}

void SetBlockPos(Block* _block, int x, int y) {
  _block->transform.position.x = x;
  _block->transform.position.y = y;
}




