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
    if (out < 1) {
        printf("Некорректный ввод! Завершение работы!\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int main(void) {
    int n;
    if (InputHandler(&n, "Введите максимальное число на бочёнке: ")){
        return EXIT_FAILURE;
    }
	printf("%d\n", n);

	return EXIT_SUCCESS;
}
