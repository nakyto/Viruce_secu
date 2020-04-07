#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/**
 * @arg : char** cl ( un tableau de char)
 */
// operation addition
double opAdd(char** cl,int i ){
    double result;

            // on vérifi si le charactère precédant est un digit, un nombre.
           //if (isdigit(cl[i-1]) == 1 && isdigit(cl[i+1]) == 1)
            //{
                
                float a = atof(cl[i-1]); // ici on l'affacete a un variable
                float b = atof(cl[i+1]);

                result = a+b; // le calcule d'une adision
    

            

        //}// fin if
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

/**
 * 
 * @arg char** cl 
 * @arg int lenCharText .
 */


double myCacluate(char** cl,int lenCharText){
    double monCal=0.0;
    //printf("%s",*cl);

    //printf("%s",cl[2]);

    for(int i = 1; i<lenCharText-1; i++){
        //printf("%s",cl[3]);
        // on prend le premiser char pour chaque 'phrase'
        switch(cl[i][0])
        {
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
    //printf("%4lf",monCal);    
    return monCal;
}




int string_lenght(char **S){
    int indexTab = 0;
    int c = 0;

    while (S[indexTab][c] != NULL)
    {
        for(c;c< strlen(S[indexTab]);c++);
        
        indexTab++;
    }
    
    return indexTab;

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
              printf("Use spaces to separate number operator!!\n");
              char monCalcule[255];
              //monCalcule = malloc(255);
              printf("Your calcul: ");
              //fgets(monCalcule,255,stdin);
              scanf("%hhd",monCalcule);
              printf("===> %hhs",monCalcule );

            /*
              char * tmp  = strtok(monCalcule," ");  ;
              char ** StringToHasmap; 
              int i = 0;
              while (monCalcule != "\0")
              {
                //StringToHasmap[i] = tmp; 
                printf("%s",tmp);
                tmp = strtok(NULL," ");  
                //i++;          
              }*/


            //char** monCalculeSplit = StringToHasmap(monCalcule," ");
            //printf("\n ===> %s",StringToHasmap[0] );
              //printf("\nYour result :%.4f\n",myCacluate(StringToHasmap,strlen(monCalcule)));
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
       
        double result = myCacluate(argv,argc);
        fprintf(stdout,"\nYour result :%.4lf\n",result);
        printf("Bye  \n");
        exit(EXIT_SUCCESS);
    }
    printf("Bye  \n");
    //printf("------- Programe Quiter ------\n");
    exit(EXIT_FAILURE);
}
