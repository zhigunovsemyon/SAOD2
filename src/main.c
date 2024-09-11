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

int SquareAlgorithm(int n, int m){
    int count = 0;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++) {
            if (i + j == m) {
                count++;
            }
        }
    }
    return count;
}

int main(void) {
    int n;  //Максимальное число на бочёнке
    int m;  //Сумма чисел на бочёнке
    if (InputHandler(&n, "Введите максимальное число (> 0) на бочёнке: ")){
        return EXIT_FAILURE;
    }
    if (InputHandler(&m, "Введите сумму чисел (> 0) на двух бочёнках: ")){
        return EXIT_FAILURE;
    }
	printf("%d из ", n);
	printf("%d\n", m);

    printf("Найдено комбинаций: %d\n", SquareAlgorithm(n,m));

	return EXIT_SUCCESS;
}
