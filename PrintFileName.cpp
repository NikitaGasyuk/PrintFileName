#include <iostream>
#include <dirent.h>

int main() 
{
    // инициализация переменной порядкового счёта файлов в директории(папке)
    int n = 0;
    // Переменная в которую будет записана открытая директория(путь к файлу) 
    DIR *dir;
    // структура содержащая информацию об элементе директории
    struct dirent *entry;
    // проверка на то что путь к открываемой директории существует или правильно указан
    if ((dir = opendir("PATH")) != NULL) 
    {
        // цикл по всем файлам в папке, проверка на то что файл существует
        while ((entry = readdir(dir)) != NULL)
        {
            // вывод порядкового номера файла и его названия
            n = n + 1;
            std::cout << n << " - "; 
            std::cout << entry->d_name << std::endl;
        }
        //закрытие директории
        closedir(dir);
    } 
    else 
    {
        // вывод ошибки в случае если с директорией что-то не так
        perror("Could not open directory");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
} 
