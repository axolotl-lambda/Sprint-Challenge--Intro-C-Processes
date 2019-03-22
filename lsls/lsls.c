#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

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
    printf("Error: too many arguments\n");
    return 1;
  }

  // Open directory
  printf("Attempting to open %s\n", dir_to_open);
  DIR *dir;
  struct dirent *entry;
  struct stat buf;

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
    {
      stat((entry->d_name), &buf);
      printf("%lld %s\n", buf.st_size, entry->d_name);
    }
  }

  // Close directory
  closedir(dir);

  return 0;
}