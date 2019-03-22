#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // set up variables
  char *dir_to_open;

  // Parse command line
  // if zero args -> open ./
  if (argc == 1)
  {
    dir_to_open = "./";
  }
  // if two args, set the second to the directory
  else if (argc == 2)
  {
    dir_to_open = argv[1];
  }
  // if more then 2 args, error out
  else
  {
    perror("too many arguments");
    return 1;
  }

  // Open directory
  printf("Attempting to open %s\n", dir_to_open);
  DIR *dir;
  struct dirent *entry;

  dir = opendir(dir_to_open);

  if (dir == NULL)
  {
    perror("opendir() error");
  }
  // Repeatly read and print entries

  else
  {
    puts("contents of directory:");
    while ((entry = readdir(dir)) != NULL)
      printf("  %s\n", entry->d_name);
  }
  // Close directory
  closedir(dir);

  return 0;
}