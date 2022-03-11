// gcc gerador_cpf.c -o gerador -O2
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int calc_nums[9] = {10,9,8,7,6,5,4,3,2};
int calc_nums2[10] = {11,10,9,8,7,6,5,4,3,2};

int msleep(unsigned int tms) {
    return usleep(tms * 1000);
}

int generate_num(){
    srand(time(NULL));
    int r = rand() % 10;  // Number in 0..9
    return r;
}

int ilen(int arr[]){
    int sum = 0;
    for(int i = 0; arr[i]; i++){
        sum++;
    }
    return sum;
}

int calc(int arr[]){
    int len = ilen(arr);
    int sum = 0;

    if (len == 9){
        for(int i = 0; i < 9; i++)
            sum += arr[i] * calc_nums[i];

        sum = sum * 10 % 11;
        return (sum >= 10) ? 0 : sum;
    }

    else {
        for(int i = 0; i < 10; i++)
            sum += arr[i] * calc_nums2[i];

        sum = sum * 10 % 11;
        return (sum >= 10) ? 0 : sum;
    }

    return -1;
}


int main(){
    int arr[11] = {0};

    puts("POR FAVOR, AGUARDE 7 SEGUNDOS!\n---------------------------");

    for(int i = 0; i < 9; i++){
        arr[i] = generate_num();
        
        while (arr[i] == 0 && i < 8)  // Cannot be 0 intil i > 7
        {
            msleep(500);
            arr[i] = generate_num();
        }
        msleep(730);  // Isso é necessário porque para gerar um numero aleatório diferente, é necessário esperar o próximo segundo, uma vez que o método é utilizar os segundos para gerar números pseudo-randômicos.
    }

    printf("9 PRIMEIROS DIGITOS DO CPF GERADO: ");  for(int i = 0; i < 9; i++) printf("%d", arr[i]);  puts("\n");

    arr[9] = calc(arr);
    arr[10] = calc(arr);

    printf("CPF COMPLETO GERADO: ");
    for(int i = 0; i < 11; i++)
        printf("%d", arr[i]);

    puts("\n----------------------------");

    return 0;
}
