
#include <time.h>
#include <stdio.h>          
#include <stdlib.h>

void main(){
    int tirage[5];
    int bonus[2];

    srand(time(NULL));

    for(int i = 0; i < 5; i++){
        tirage[i] = 0;
    }

    for(int i = 0; i < 2; i++){
        bonus[i] = 0;
    }

    for(int i = 0; i < 5; i++){
        int isExist = 0;
        int random = 0;

        do{
            isExist = 0;
            random = rand() % 49 + 1;
            for(int j = 0; j < 5; j++){
                if(tirage[j] == random)
                    isExist ++;
            }
        }while(isExist != 0);

        tirage[i] = random;
    }

    for(int i = 0; i < 2; i++){
        int isExist = 0;
        int random = 0;

        do{
            isExist = 0;
            random = rand() % 12 + 1;
            for(int j = 0; j < 2; j++){
                if(bonus[j] == random)
                    isExist ++;
            }
        }while(isExist != 0);

        bonus[i] = random;
    }

    printf("vos numéros sont :\n");
    for(int i = 0; i < 5; i++){
        if(i != 4)
            printf("%d - ", tirage[i]);
        else
            printf("%d\n", tirage[i]);
    }

    printf("vos numéros bonus sont :\n");
    for(int i = 0; i < 2; i++){
        if(i != 1)
            printf("%d - ", bonus[i]);
        else
            printf("%d\n", bonus[i]);
    }

}