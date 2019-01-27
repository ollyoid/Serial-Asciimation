#include <stdio.h>
#include<stdlib.h>
#include<time.h>

//Macros
#define FRAME_HEIGHT 32
#define FRAME_WIDTH 64

#define FRAME_CONTENT char frameContent[FRAME_WIDTH][FRAME_HEIGHT]
    
//Draws the frame 
int drawFrame(FRAME_CONTENT){
  printf("+");
  for(unsigned int x = 0; x < FRAME_WIDTH; x++){
    printf("-");
  }
  printf("+\n");
  for(unsigned int y = 0; y < FRAME_HEIGHT; y++){
    printf("|");
    for(unsigned int x = 0; x < FRAME_WIDTH; x++){
      printf("%c",frameContent[x][y]);
    }
    printf("|\n");
  }
  printf("+");
  for(unsigned int x = 0; x < FRAME_WIDTH; x++){
    printf("-");
  }
  printf("+\n");
  return(0);
}

//Clears the frame by doing alot of carrage returns (would be nice to do differently)
void clearFrame(){
    int n;
    for (n = 0; n < 10; n++)
      printf( "\n\n\n\n\n\n\n\n\n\n" );
}

//Delay function for C, delays by milliseconds stated
void delay(unsigned int ms){
  clock_t time = clock();
  while((clock()-time)/(CLOCKS_PER_SEC/1000)< ms){
  }
}

//Sets the frame to be full of empty space
void initializeFrame(FRAME_CONTENT){
  for(unsigned int y = 0; y < FRAME_HEIGHT; y++){
    for(unsigned int x = 0; x < FRAME_WIDTH; x++){
      frameContent[x][y] = ' ';
    }
  }
}

//Add text to the frame 
void updateLine(FRAME_CONTENT, char string[], int line, int position){
  for(unsigned int c = 0; (c < FRAME_WIDTH)&&(string[c] != '\0'); c++){
    frameContent[(c+position)%FRAME_WIDTH][line] = string[c];
  }
}

//Scrolls text along a given line (just basic animation test)
void scrollLine(FRAME_CONTENT, char string[], int line){
  for(unsigned int p = 0; p < FRAME_WIDTH; p++){
    updateLine(frameContent, " \0", line, (p-1+FRAME_WIDTH)%FRAME_WIDTH);
    updateLine(frameContent, string, line, p);
    clearFrame();
    drawFrame(frameContent);
    delay(100);
  }
}
  

int main(){
  char frameContent[FRAME_WIDTH][FRAME_HEIGHT];
  initializeFrame(frameContent);
  while(1){
    scrollLine(frameContent, "Hello World", 0);
  }
  return(0);
}
