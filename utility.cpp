/***********************************************************

OWNER:  ANUJ BANSAL
ROLLNO. 2018201096
COPYRIGHT PROTECTED
***********************************************************/
#include"utility.h"
int vmin=1;//for handling the esc key issue
int vtime=0;

/*
AUTHOR:         ANUJ
DESCRIPTION:    Read a character in non-canonical mode and switch back again into canonical mode
RETURN:         Return the character read
*/
int getch() {
      int c=0;
      struct termios org_opts, new_opts;
      int res=0;
      //-----  store old settings -----------
      res=tcgetattr(STDIN_FILENO, &org_opts);
      assert(res==0);
      //---- set new terminal parms --------
      memcpy(&new_opts, &org_opts, sizeof(new_opts));
      new_opts.c_lflag &=~(IXON | IEXTEN);
      new_opts.c_cc[VTIME]= vtime;    
      new_opts.c_cc[VMIN]= vmin;
      new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL | ISIG);
      tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
      c=getchar();
      //------  restore old settings ---------
      res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
      assert(res==0);
      return(c);
 }

void cursorAtEnd(){
  //Clear the screen, move to (0,0):
   printf("\033[2J");
}
void cursorUp(int lines){
  //- Move the cursor up 'lines' lines:
   printf("\033[%dA",lines);
}
void cursorDown(int lines){
  //- Move the cursor down 'lines' lines:
   printf("\033[%dB",lines);
}
void cursorForward(int columns){
  //- Move the cursor forward 'columns' columns:
   printf("\033[%dC",columns);
}
void cursorBackward(int columns){
  //- Move the cursor backward 'columns' columns:
   printf("\033[%dD",columns);
}
void clearConsole(){
  //Clear the screen
   printf("\033c");
}
void cursorMove(int line, int column){
  //Position the Cursor:
   printf("\033[%d;%dH",line,column);
}
void clearLine(){
  //clear current line
  printf("%c[2K", 27);
}

/*
AUTHOR:         ANUJ
DESCRIPTION:    Print the size of file in human readable format(similar to ls-lh)
*/
void printHumanReadableSize(long size)
{
  long Kb = 1  * 1024;
  long Mb = Kb * 1024;
  long Gb = Mb * 1024;
  long Tb = Gb * 1024;
  long Pb = Tb * 1024;
  long Eb = Pb * 1024;
  float val=size;
  if (size <  Kb)                 
    cout<<setw(7)<<right<<val<<setw(1)<<right<<"B";
  if (size >= Kb && size < Mb){
    val=1.0*size/Kb;
    val=(int)(val*10+0.5)/10.0;
    cout<<setw(7)<<right<<val<<setw(1)<<right<<"K";
  }
  if (size >= Mb && size < Gb){
    val=1.0*size/Mb;
    val=(int)(val*10+0.5)/10.0;
    cout<<setw(7)<<right<<val<<setw(1)<<right<<"M";
  }
  if (size >= Gb && size < Tb){
    val=1.0*size/Gb;
    val=(int)(val*10+0.5)/10.0;
    cout<<setw(7)<<right<<val<<setw(1)<<right<<"G";
  }
  if (size >= Tb && size < Pb){
    val=1.0*size/Tb;
    val=(int)(val*10+0.5)/10.0;
    cout<<setw(7)<<right<<val<<setw(1)<<right<<"T";
  }
  if (size >= Pb && size < Eb){
    val=1.0*size/Pb;
    val=(int)(val*10+0.5)/10.0;
    cout<<setw(7)<<right<<val<<setw(1)<<right<<"P";
  }
}


/*
AUTHOR:         ANUJ
DESCRIPTION:    Print the character entered by user in non canonical mode (To handle backspace press)
*/
void printInputBuffer(char inputBuffer[], long n){
  for (long i=0;i<n;i++)
      printf("%c", inputBuffer[i]);
}

/*
AUTHOR:         ANUJ
DESCRIPTION:    Print command mode there by moving the cursor to the last line of the cursor
*/
void printCommandMode(){
  cursorMove(1000,1);
  clearLine();    
  printf("COMMAND MODE :");
}

/*
AUTHOR:         ANUJ
DESCRIPTION:    Tokenize the characters entered by users in command mode dilimited by space
PARAMETERS:     Input buffer, token=>delimter
RETURN:         vector of words
*/
vector<string> tokenize(char inputBuffer[], string token){
  vector<string> words;
  char* word = strtok(inputBuffer, token.c_str());
  while (word != NULL) {
    words.push_back(word);
    word = strtok(NULL, token.c_str());
  }
  return words;
}
  


