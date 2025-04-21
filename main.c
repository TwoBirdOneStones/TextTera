#include <stdio.h>
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
} Transform;

typedef struct {
  enum BlockType type;
  Transform transform;
} Block;

Block blocks[WORLD_WIDTH][WORLD_HEIGHT];

void LoadWorldFile(void);

int main(){
  LoadWorldFile();
  return 0;
}

void LoadWorldFile() {
  printf("Hello Woreld\n");
}


