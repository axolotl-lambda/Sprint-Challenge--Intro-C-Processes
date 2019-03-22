#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  for (int i = 0; i < argc; i++)
  {
    // argv[i] is the argument at index i
    printf("%s\n", argv[i]);
  }

  // Open directory
  DIR *dir;
  struct dirent *entry;

  dir = opendir("/");

  if (dir == NULL)
  {
    perror("opendir() error");
  }
  // Repeatly read and print entries

  else
  {
    puts("contents of root:");
    while ((entry = readdir(dir)) != NULL)
      printf("  %s\n", entry->d_name);
    closedir(dir);
  }
  // Close directory

  return 0;
}