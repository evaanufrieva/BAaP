#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stdlib.h"
#include "saper.h"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW  "\033[33m"

void help() {
    printf(YELLOW);
    printf("\n=== Контекстное меню ===\n");
    printf("Задача: Реализовать функционал игры 'Сапёр'\n");
    printf("Доступные команды:\n");
    printf("   calc   - выполнить расчёт\n");
    printf("   help   - вывести это меню\n");
    printf("   exit   - завершить программу\n");
    printf("========================\n");
    printf(RESET);
}

void realization() {
    int n,m;
    printf("Введите число строк и столбцов: ");
    scanf("%d %d", &n, &m);
    char **field=createField(n,m);
    for (int i = 0; i < n; i++) {
        printf("Введите значения %d-й строки поля (. или *): ", i + 1);
        for (int j = 0; j < m; j++){
            scanf(" %c", &field[i][j]);
            while (field[i][j] != '.' && field[i][j] != '*') {
                printf("Ошибка! Введите только '.' или '*': ");
                scanf(" %c", &field[i][j]);
            }
        } 
    }

    printf("\nПоле:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c ", field[i][j]);
        }
        printf("\n");
    }
    printf("\nРазминированное поле:\n");
    char **newField= inputNumbersField(n,m,field);
    for (int i = 0; i < n; i++){
        for (int j = 0;j < m; j++)
            {
                printf("%c " , newField[i][j]);
            }
        printf("\n");
    }
    freeField(n, field);    
}

int main()
{
    printf(GREEN "\nДобро пожаловать в лабораторную работу 4 Задание 5!\n" RESET);
    printf("В данной программе реализована игра 'Сапёр'\n");
    help();
   char command[100];

    while (true) {
        printf(GREEN "~$ " RESET);
        if (scanf("%99s", command) != 1) {
            break;
        }
        if (strcmp(command, "calc") == 0) {
            realization();
        } else if (strcmp(command, "help") == 0) {
            help();
        } else if (strcmp(command, "exit") == 0 || strcmp(command, "quit") == 0) {
            break;
        } else {
            printf(RED "[!] Команда \"%s\" не найдена. Введите help для справки.\n" RESET, command);
        }
    }
  
    return 0;
}