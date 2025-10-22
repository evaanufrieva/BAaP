#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "diagSum.h"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW  "\033[33m"

void help() {
    printf(YELLOW);
    printf("\n=== Контекстное меню ===\n");
    printf("Задача: Найти максимальную сумму чисел диагоналей трёхмерной матрицы\n");
    printf("Исполнила: Ануфриева Ева\n");
    printf("Доступные команды:\n");
    printf("   calc   - выполнить расчёт\n");
    printf("   help   - вывести это меню\n");
    printf("   exit   - завершить программу\n");
    printf("========================\n");
    printf(RESET);
}

void realization() {
    int n;
    printf("Введите n - размер трёхмерного массива: ");
    if (scanf("%d", &n)!=1 || n<=0)
    {
        printf("Неправильный размер n\n");
    }
    printf("Введите элементы массива:\n");

    int ***arr=create3DArray(n);
    int *sumdiag=NULL;
    int size=0;
    // 1. Диагональ от (0,0,0) до (n-1,n-1,n-1)
    int sum1=0;
    for (int i = 0; i < n; i++)
    {
        sum1+=arr[i][i][i];
    }
    addValue(&sumdiag, &size, sum1);
    // 2. Диагональ от (0,0,n-1) до (n-1,n-1,0)
    int sum2=0;
    for (int i = 0; i < n; i++)
    {
        sum2+=arr[i][i][n-1-i];
    }
    addValue(&sumdiag, &size, sum2);
    // 3. Диагональ от (0,n-1,n-1) до (n-1,0,n-1)
    int sum3=0;
    for (int i = 0; i < n; i++)
    {
        sum3+=arr[i][n-1-i][i];
    }
    addValue(&sumdiag, &size, sum3);
    // 4. Диагональ от (n-1,0,0) до (0,n-1,n-1)
    int sum4=0;
    for (int i = 0; i < n; i++)
    {
        sum4+=arr[n-1-i][i][i];
    }
    addValue(&sumdiag, &size, sum4);
    int maxDiagSum=sumdiag[0];
    for (int i = 0; i < size; i++)
    {
        if (sumdiag[i]>maxDiagSum) maxDiagSum=sumdiag[i];
        
    }
    printf("Максимальная сумма элементов диагонали трёхмерного массива: %d\n", maxDiagSum);
    free(sumdiag);
}

int main()
{
    printf(GREEN "\nДобро пожаловать в лабораторную работу 4 Задание 4!\n" RESET);
    printf("В данной программе реализован подсчёт диагонали с наибольшей суммой чисел\n");
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