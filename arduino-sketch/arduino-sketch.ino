//Macros
#define FRAME_HEIGHT 32 
#define FRAME_WIDTH 48

//This just is to type less
#define FRAME_CONTENT char frameContent[FRAME_WIDTH][FRAME_HEIGHT]

//frame *object*
char frameContent[FRAME_WIDTH][FRAME_HEIGHT];


//Draws the frame given 2d char matrix
int drawFrame(FRAME_CONTENT){
  Serial.print("+");
  for(unsigned int x = 0; x < FRAME_WIDTH; x++){
    Serial.print("-");
  }
  Serial.print("+\n");
  for(unsigned int y = 0; y < FRAME_HEIGHT; y++){
    Serial.print("|");
    for(unsigned int x = 0; x < FRAME_WIDTH; x++){
      Serial.print(frameContent[x][y]);
    }
    Serial.print("|\n");
  }
  Serial.print("+");
  for(unsigned int x = 0; x < FRAME_WIDTH; x++){
    Serial.print("-");
  }
  Serial.print("+\n");
  return(0);
}


//Clears the frame by doing alot of carrage returns (would be nice to do differently)
void clearFrame(){
  Serial.print( "\n\n\n\n\n\n\n\n\n\n" );
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


void setup() {
  Serial.begin(2000000); // As fast as we can make it
  initializeFrame(frameContent);
}

void loop() {
   scrollLine(frameContent, "Hello World!", 0);
}


