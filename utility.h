/***********************************************************

OWNER: 	ANUJ BANSAL
ROLLNO. 2018201096
COPYRIGHT PROTECTED
***********************************************************/
#include<bits/stdc++.h>
#include <termios.h>
#include <signal.h>
#include <termios.h>
#include <signal.h>
///////////////Key Mappings///////////
#define K_ESC '\033'
#define K_UP 'A'
#define K_DOWN 'B'
#define K_RIGHT 'C'
#define K_LEFT 'D'
#define K_COLON ':'
#define K_h 'h'
#define K_H 'H'
#define K_q 'q'
#define K_Q 'Q'
#define K_BACKSPACE 127
#define K_ENTER 10
#define K_SPACE 10

#define MAX_BUFFER 2000
///////////various commands opcodes/////////////
#define COPY "copy"
#define MOVE "move"
#define RENAME "rename"
#define GOTO "goto"
#define SNAPSHOT "snapshot"
#define CREATE_DIR "create_dir"
#define CREATE_FILE "create_file"
#define DELETE_DIR "delete_dir"
#define DELETE_FILE "delete_file"
#define SEARCH "search"
using namespace std;

#ifndef INC_UTILITY_H
#define INC_UTILITY_H

int getch();
void cursorAtEnd();
void cursorUp(int lines);
void cursorDown(int lines);
void cursorForward(int columns);
void cursorBackward(int columns);
void clearConsole();
void cursorMove(int line, int column);
void clearLine();
void printHumanReadableSize(long size);
void printInputBuffer(char inputBuffer[],long n);
void printCommandMode();
vector<string> tokenize(char inputBuffer[], string token);
//Enum to identify the success and failures of various commands
enum CommandState {FAILURE,SUCCESS_GOTO,SUCCESS_DIR_CREATED,SUCCESS_FILE_CREATED,SUCCESS_DIR_DELETED,SUCCESS_FILE_DELETED,SUCCESS_COPY,SUCCESS_MOVE,SUCCESS_RENAME,SUCCESS_SNAPSHOT,SUCCESS_SEARCH};

#endif 


