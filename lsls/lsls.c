#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

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
    printf("Contents of %s:\n", dir_to_open);
    // print out `.` and `..` first
    printf("%10s %s\n", "<DIR>", ".");
    printf("%10s %s\n", "<DIR>", "..");

    // print out rest of entries
    while ((entry = readdir(dir)) != NULL)
    {
      // for each one, make sure it's not `.` or `..`
      if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, ".."))
      {
        stat((entry->d_name), &buf);
        int is_dir = S_ISDIR(buf.st_mode);

        if (is_dir)
        {
          printf("%10s %s\n", "<DIR>", entry->d_name);
        }
        else
        {
          printf("%10lld %s\n", buf.st_size, entry->d_name);
        }
      }
    }
  }

  // Close directory
  closedir(dir);

  return 0;
}