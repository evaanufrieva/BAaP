#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stdlib.h"
#include "magicSqr.h"
#include <math.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW  "\033[33m"

void help() {
    printf(YELLOW);
    printf("\n=== Контекстное меню ===\n");
    printf("Задача: Магический квадрат\n");
    printf("Доступные команды:\n");
    printf("   calc   - выполнить расчёт\n");
    printf("   help   - вывести это меню\n");
    printf("   exit   - завершить программу\n");
    printf("========================\n");
    printf(RESET);
}

void realization() {
    int n;
    do {
        printf("Введите порядок магического квадрата: ");
        scanf("%d", &n);

        if (n % 2 == 0) {
            printf("Ошибка! Магический квадрат по этому алгоритму возможен только для нечётного n.\n");
        }
    } while (n % 2 == 0);

    int **matrix = resultMatrix(n);
    printMatrix(n, matrix);
    freeSquare(n, matrix);
}


int main()
{
    printf(GREEN "\nДобро пожаловать в лабораторную работу 4 Задание 6!\n" RESET);
    printf("В данной программе реализован магический квадрат порядка n\n");
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