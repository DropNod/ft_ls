#include "ft_ls.h"

int main(int ac, char **av)
{
  DIR *dir;

  (void) ac;
  (void) av;
  dir = opendir(".");
  struct dirent *file = readdir(dir);
  while (file)
  {
    printf("%s\n", file->d_name);
    file = readdir(dir);
  }
  return (EXIT_SUCCESS);
}