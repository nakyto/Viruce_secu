#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/**
 * @arg : char** cl ( un tableau de char)
 */
// operation addition
double opAdd(char* cl,int i ){
    static float result;
        if (cl[i-1] == (char)0 || cl[i-1] == ' ')
            {
                perror("Error : String is not conform\nMake sure, you don't hava space or null char.\n");
                exit(EXIT_FAILURE);
            }else
            {
                // on vérifi si le charactère precédant est un digit, un nombre.
                if (isdigit(cl[i-1]) == 1 )
                {
                    int a = atoi(cl[i-1]); // is on l'affacete a un variable

                    if (isdigit(cl[i+1]) == 1)
                    {
                    int b = atoi(cl[i+1]);
                    result = a+b; // le calcule d'une adision
                    }

                }

        }// fin if
    return result;
}
// operation soustraction
double opSou(char* cl,int i ){
    static float result;
        if (cl[i-1] == '\0' || cl[i-1] == ' ')
            {
                perror("Error : String is not conform\nMake sure, you don't hava space or null char\n");
                exit(EXIT_FAILURE);
            }else
            {
                // on vérifi si le charactère precédant est un digit, un nombre.
                if (isdigit(cl[i-1]) == 1 )
                {
                    int a = atoi(cl[i-1]); // is on l'affacete a un variable

                    if (isdigit(cl[i+1]) == 1)
                    {
                    int b = atoi(cl[i+1]);
                    result = a-b; // le calcule d'une adision
                    }

                }

        }// fin if

    return result;
}
// opération multiplication
double opMul(char* cl,int i ){
    static float result;

        if (cl[i-1] == '\0' || cl[i-1] == ' ')
            {
                perror("Error : String is not conform\nMake sure, you don't hava space or null char\n");
                exit(EXIT_FAILURE);
            }else
            {
                // on vérifi si le charactère precédant est un digit, un nombre.
                if (isdigit(cl[i-1]) == 1 )
                {
                    int a = atoi(cl[i-1]); // is on l'affacete a un variable

                    if (isdigit(cl[i+1]) == 1)
                    {
                    int b = atoi(cl[+1]);
                    result = a*b; // le calcule d'une adision
                    }

                }

        }// fin if
}
//opération division
double opDiv(char* cl,int i ){
    static float result;
        if (cl[i-1] == '\0' || cl[i-1] == ' ')
            {
                perror("Error : String is not conform\nMake sure, you don't hava space or null char\n");
                exit(EXIT_FAILURE);
            }else
            {
                // on vérifi si le charactère precédant est un digit, un nombre.
                if (isdigit(cl[i-1]) == 1 )
                {
                    int a = atoi(cl[i-1]); // is on l'affacete a un variable

                    if (isdigit(cl[i+1]) == 1)
                    {
                    int b = atoi(cl[i+1]);
                    result = a/b; // le calcule d'une adision
                    }

                }

        }// fin if
    return result;
}
// opération puisance
double opPow(char* cl,int i ){
    static float result;
        if (cl[i-1] == '\0' || cl[i-1] == ' ')
            {
                perror("Error : String is not conform\nMake sure, you don't hava space or null char\n");
                exit(EXIT_FAILURE);
            }else
            {
                // on vérifi si le charactère precédant est un digit, un nombre.
                if (isdigit(cl[i-1]) == 1 )
                {
                    int a = atoi(cl[i-1]); // is on l'affacete a un variable

                    if (isdigit(cl[i+1]) == 1)
                    {
                    int b = atoi(cl[i+1]);
                    result = pow(a,b); // le calcule d'une puissance
                    }

                }

        }// fin if
    return result;
}


double myCacluate(char* cl){
    double monCal=0;

    for(int i = 0; i<strlen(cl); i++){


        switch ( cl[i] )
        {
        case'(':
            break;
        case'+':
            monCal += opAdd(cl,i);
            break;
        case'-':
            monCal += opAdd(cl,i);
            break;
        case'*':
            monCal += opMul(cl,i);
            break;
        case'/':
            monCal += opDiv(cl,i);
            break;
        case'^':
            monCal += opPow(cl,i);
            break;
        default:
            break;
        }

    }
}

// ===============  end function =================================

/**
 * @arg : int argc compteur de paramètre, argv la chaine de paramètre.
 * @note : la fonction main avec des paramètres pour pouvoir executé le programe avec directement un cacule
 */
int main(int argc, char** argv)
{
    if(argc < 2 ){
        //fprintf(stderr,"Error : entre des argumen\n");
        printf("Do you want to continue ?\n");
        printf("1 : Continue\n");
        printf("0 : Exit the program\n");

        char le_Chois='\0';
        printf("Your choice : ");
        //fgets(le_Chois,4,stdin);
        scanf("%c",&le_Chois);
        printf("\n");

        if (isdigit(le_Chois)) {

          if (le_Chois == '1')
          {
              /**
               * @note : Cas pour continuer le programe
               */
              printf("Spaces are not tolerated!!\n");
              char monCalcule[255];
              printf("Your calcul :");
              //fgets(monCalcule,255,stdin);
              scanf("%s",monCalcule);
              printf("\nYour result :%4f\n",myCacluate(monCalcule));

          }
          if (le_Chois == '0')
          {
              /**
               * @note : Cas pour quité le programe
               */
              printf("Bye\n------- Programe Quiter ------\n");
              exit(EXIT_SUCCESS);
          }
          if(le_Chois != '0' || le_Chois != '1')
          {
              /**
               * @note : Cas non envisagé pour le programe
               */
              perror("Error : not envisagied casse\n");
              exit(EXIT_FAILURE);
          }
        }else
        {
          /**
           * @note : Cas non envisagé pour le programe
           */
          perror("Error : is not a digit \n");
          exit(EXIT_FAILURE);
        }


    }else{
       
        
        fprintf(stdout,"\nYour result :%4f\n",myCacluate(argv));
        printf("Bye  \n");
        exit(EXIT_SUCCESS);
    }
    //printf("Bye  \n");
    //printf("------- Programe Quiter ------\n");
    exit(EXIT_FAILURE);
}
