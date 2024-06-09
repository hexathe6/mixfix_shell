#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "cons.c"

#ifndef PRIM_C
#define PRIM_C

tuple4 sh_exec(char* name, char** args)
{
  int stdout_p[2];
  int stdin_p[2];
  int stderr_p[2];
  pipe(stdout_p);
  pipe(stdin_p);
  pipe(stderr_p);
  int pid = fork();
  if(pid < 0) exit(1); // something has gone terribly wrong here, just crash and don't move on
  if(!pid)
    {
      dup2(stdout_p[1], STDOUT_FILENO);
      dup2(stdin_p[0], STDIN_FILENO);
      dup2(stderr_p[1], STDERR_FILENO);
      close(stdout_p[1]);
      close(stdin_p[0]);
      close(stderr_p[1]);

      //execv(find_in_path(name), args);
      execvp(name, args);
    } // todo
  
  return (tuple4){(void*)stdout_p[0], (void*)stdin_p[1], (void*)stderr_p[0], (void*)pid};
}

#endif
