#include "ft_ls.h"

typedef struct dir_s
{
  struct dirent **entrys;
  int nb_entrys;
} dir_t;

int count_entrys(const char *dir_name)
{
  struct dirent *file;
  int output;
  DIR *dir;

  dir = opendir(dir_name);
  file = readdir(dir);
  output = 0;
  while (file)
  {
    output++;
    file = readdir(dir);
  }
  closedir(dir);
  return (output);
}

dir_t init_dir(const char *dir_name)
{
  DIR *dir;
  dir_t output;

  output.nb_entrys = count_entrys(dir_name);
  output.entrys = malloc(output.nb_entrys * sizeof(struct dirent *));
  dir = opendir(dir_name);
  for (int i = 0; i < output.nb_entrys; i++)
    output.entrys[i] = readdir(dir);
  closedir(dir);
  return (output);
}   

int main(int ac, char **av)
{
  dir_t dir;

  (void) ac;
  (void) av;
  dir = init_dir(".");
  for (int i = 0; i < dir.nb_entrys; i++)
  {
    if (dir.entrys[i]->d_name[0] != '.')
      printf("%s  ", dir.entrys[i]->d_name);
  }
  return (EXIT_SUCCESS);
}