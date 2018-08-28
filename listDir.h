/***********************************************************

OWNER: 	ANUJ BANSAL
ROLLNO. 2018201096
COPYRIGHT PROTECTED
***********************************************************/
#include<bits/stdc++.h>
#include<stdlib.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include"utility.h"
using namespace std;


#ifndef INC_MODULE2_H
#define INC_MODULE2_H
unsigned long initialLS();
struct stat getStatInfo(string rootPath, string fName);
void printHead();
DIR * openDirectory(const char* s);
void getFileList(DIR * pDir);
long enterDirectory(unsigned long indexOfFile);
void printStatInfo(struct stat info, string fName);
void openFile(string filePath);
unsigned long backDirect();
unsigned long forwardDirect();
void printFilesWinDependent(unsigned long firstIndex,unsigned long lastIndex,string path);
unsigned long backspace();
unsigned long goHome();

#endif
