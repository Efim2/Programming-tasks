#include <stdio.h>
#include <stdbool.h> 
// Директория для работы с булевыми выражениями, они принимают значения true и folse.

int main(void) {
    int n = 0;
    bool increasing = false;
    float a, b;
    FILE *input; // Информация о файле. Зачем она нужна??

    input = fopen("input.txt", "r"); 
    // input = inp - файловая переменная(вход), fopen - file open.
    // "input.txt" - имя  файла для открытия, "r" - read(чтение), "w" - write(запись). 

    if(input == NULL) {
        printf("Fail is missing\n");
        return -1;
    }
    // Проверка на открытие файла. Если файл не найден или защищен от запсиси, то программа завершится. 

    if(fscanf(input, "%f", &a) != 1) {
        printf("Failed to read first element\n");
        return -1;
    }
    // Считываем данные из файла функцией fscanf. Где певый аргумент - файловая переменная.
    // Что значит, функция неравна 1 (fscanf(input, "%f", &a) != 1)??
    while(fscanf(input, "%f", &b) > 0) {
        if (a < b) {
            if(!increasing) {
                n++;
                increasing = true;
                
            }
        }
        else {
            increasing = false;
        }
        a = b;
    }
    fclose(input);

    printf("The number of increasing sections of the sequence =");
    printf("%d", n);
    return 0;
}