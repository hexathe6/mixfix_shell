#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

#include "prim.c"

int main(int argc, char** argv)
{
  if(argc > 2 && !(strcmp(argv[1],"-c")))
    {
      // eval argument
    }

  char* args[5] = {"-1", "-rt", "-B", ".", 0}; // -B is a GNU ls option, it may not work under cygwin or macos
  tuple4 x = sh_exec("/bin/ls", args);

  printf("%d %d %d\n", x.i0,x.i1,x.i2);
  
  char line[100] = {0};
  FILE* fp = fdopen((int)x.i0, "r");
  while(fgets(line, sizeof(line), fp))
    {
      printf("%s%d\n", line, strlen(line));
    }
  fclose(fp);

  return 0;
}
