/*
Придумать несколько алгоритмов и сравнить их порядок сложности в лучшем, среднем и худшем случаях для решения
следующей задачи.
В лотереи вытаскивают два бочонка с цифрами. На каждом бочонке может быть цифра от 0 до n. Сколько существует
возможных комбинаций, при которых сумма чисел на этих бочонках окажется равна m.
*/

#include <stdio.h>
#include <stdlib.h>

/* Чтение ввода числа num из stdin по запросу из text */
int InputHandler(int *num, const char *text) {
    printf("%s", text);
    int out = scanf("%d", num);
    if (out == EOF) {
        printf("\nВведён EOF. Завершение работы!\n");
        return EOF;
    } 
    if (out < 1 || *num < 0) {
        printf("Некорректный ввод! Завершение работы!\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

long Algorithm1 (int n, int m, int doOut) {
    int count = 0;
    if (n * 2 < m) {
        return count;
    }
    int i = m / 2;
    if (i * 2 == m) {
        if (doOut) {
            printf("(%d:%d)\n", i, i);
        }   
    }
    for (i++; i <= n; i++) {
        count++;
        if (doOut) {
            printf("(%d:%d)\n", i, m - i);
            printf("(%d:%d)\n", m - i, i);
        }
    }

    return count;
}
long Algorithm0(int n, int m, int doOut){
    //Счётчик итераций
    long count = 0;
    //Перебор первого числа
    for (int i = 0; i <= n; i++){
        //Перебор второго числа
        for (int j = 0; j <= n; j++) {
            //Если они соответствуют условию, комбинация отображается на экране
            if (i + j == m) {
                if (doOut) {
                    printf("(%d:%d)\n", i, j);
                }   
            }
            //Увеличение счётчика итераций
            count++;
        }
    }
    return count;
}

int main(const int argc, [[maybe_unused]] const char **argv) {
    int doOut = (argc > 1) ? 0 : 1;
    int n;  //Максимальное число на бочёнке
    int m;  //Сумма чисел на бочёнке
    //Ввод числа n
    if (InputHandler(&n, "Введите максимальное число (> 0) на бочёнке: ")){
        return EXIT_FAILURE;
    }
    //Ввод числа m
    if (InputHandler(&m, "Введите сумму чисел (> 0) на двух бочёнках: ")){
        return EXIT_FAILURE;
    }
    printf("%d из %d\n", n, m);
    
    printf("Алгоритм 0. Совершено итераций: %ld\n", Algorithm0(n, m, doOut));
    printf("Алгоритм 1. Совершено итераций: %ld\n", Algorithm1(n, m, doOut));
    
    return EXIT_SUCCESS;
}
