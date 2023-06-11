//  Paydreanne E. Hinton
//  Processes.cpp
//  ITSC 3146
//
//  Created by Bahamon, Julio on 1/12/17.
//


/*
 @file Processes.cpp
 @author student name, student@uncc.edu
 @author student name, student@uncc.edu
 @author student name, student@uncc.edu
 @description: <ADD DESCRIPTION>
 @course: ITSC 3146
 @assignment: in-class activity [n]
 */


#ifndef Processes_cpp
#define Processes_cpp

#include "Processes.h"
#include <unistd.h>


using namespace std;


// Part 1: Working With Process IDs
pid_t getProcessID(void)
{
   // TODO: Add your code here
   pid_t ProcessID = getpid();
   return ProcessID;
}


// Part 2: Working With Multiple Processes
string createNewProcess(void)
{
   pid_t id = fork();
   
   // DO NOT CHANGE THIS LINE OF CODE
   process_id = id;
   
   
   if(id == -1)
   {
      return "Error creating process";
   }
   else if (id == 0)
   {
      // TODO: Add your code here
      return "I just became a parent!\nI am a child process!\nI am bored of my parent, switching programs now";
   }
   else
   {
      // TODO: Add your code here
      int status = 0;
      wait(&status);
      return "My child process just terminated!";
   }
}


// Part 3: Working With External Commands
void replaceProcess(char * args[])
{
   // Spawn a process to execute the user's command.
   pid_t id = fork();
   
   
   // TODO: Add your code here
   if (id == -1) {
      cout << "Error";
   } else if (id == 0) {
      execvp("ls", args);
      _exit(1);
   } else {
      wait(NULL);
      exit(0);
   }
}

/*
1) https://www.geeksforgeeks.org/getppid-getpid-linux/#
2) https://www.geeksforgeeks.org/wait-system-call-c/#
3) https://www.geeksforgeeks.org/getppid-getpid-linux/
4) https://www.digitalocean.com/community/tutorials/execvp-function-c-plus-plus
*/

#endif /* TestProg_cpp */
