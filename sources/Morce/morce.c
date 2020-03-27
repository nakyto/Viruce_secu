#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum alphabet { space, a, b, c, d, e, f, g, h ,i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z};


/**
 * @note : L'utilisateur, va entré dans un "input" pour traduire la chaine de charactère
*/
int main(int argc, char *argv[]){
  char ALFABET[27] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  char* morce[] = {"|", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.","....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."} ;

  char LA_CHAINE_A_CONSERTIRE[255];

  printf("=================================|\n");
  printf("--------------MORCE--------------|\n");
  printf("Ce programme prend en charge :   |\n");
  printf("les lettres ainsi que les epaces |\n");
  printf("=================================|\n");

  printf("Enter a String :");
  fgets(LA_CHAINE_A_CONSERTIRE,255,stdin);
  printf("ma chaine :%s",LA_CHAINE_A_CONSERTIRE);

  int longeur_chain = strlen(LA_CHAINE_A_CONSERTIRE);
  int i, j, cpt = 0;

  for(i = 0 ; i<longeur_chain;i++){


    switch (LA_CHAINE_A_CONSERTIRE[i])
    {
    case ' ':
      printf("%s",morce[space]);
      //strncpy(maConvertion,&morce_space,sizeof(LA_CHAINE_A_CONSERTIRE[i]));
      break;

    case 'a':
      printf("%s",morce[a]);
      break;

    case 'b':
      printf("%s",morce[b]);
      break;

    case 'c':
      printf("%s",morce[c]);
      break;

    case 'd':
      printf("%s",morce[d]);
      break;

    case 'e':
      printf("%s",morce[e]);
      break;

    case 'f':
      printf("%s",morce[f]);
      break;

    case 'g':
      printf("%s",morce[g]);
      break;

    case 'h':
      printf("%s",morce[h]);
      break;

    case 'i':
      printf("%s",morce[i]);
      break;

    case 'j':
      printf("%s",morce[j]);
      break;

    case 'k':
      printf("%s",morce[k]);
      break;

    case 'l':
      printf("%s",morce[l]);
      break;

    case 'm':
      printf("%s",morce[m]);
      break;

    case 'n':
      printf("%s",morce[n]);
      break;

    case 'o':
      printf("%s",morce[o]);
      break;

    case 'p':
      printf("%s",morce[p]);
      break;

    case 'q':
      printf("%s",morce[q]);
      break;

    case 'r':
      printf("%s",morce[r]);
      break;

    case 's':
      printf("%s",morce[s]);
      break;

    case 't':
      printf("%s",morce[t]);
      break;

    case 'u':
      printf("%s",morce[u]);
      break;

    case 'v':
      printf("%s",morce[v]);
      break;

    case 'w':
      printf("%s",morce[w]);
      break;

    case 'x':
      printf("%s",morce[x]);
      break;

    case 'y':
      printf("%s",morce[y]);
      break;

    case 'z':
      printf("%s",morce[z]);
      break;

    default:
    //  par défauf / cas d'ereur, cas non suporté marque un !
      printf("!");
      break;
    }

  }

  printf("\n");
  return 0;
}
