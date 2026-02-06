#include <iostream>
#include <dirent.h>

int main() {
    int n = -2;
    DIR *dir;
    struct dirent *entry;
    if ((dir = opendir("путь к папке")) != NULL) 
    {
        while ((entry = readdir(dir)) != NULL)
        {
            n = n + 1;
            std::cout << n << " "; 
            std::cout << entry->d_name << std::endl;
        }
    closedir(dir);
    } 
    else 
    {
    perror("Could not open directory");
    return EXIT_FAILURE;
    }
return EXIT_SUCCESS;
} 
