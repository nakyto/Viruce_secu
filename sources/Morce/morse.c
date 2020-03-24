
#include <stdio.h>

enum alphabet { space, a, b, c, d, e, f, g, h ,i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z};

int main()
{
    char alpha[27] = {' ', 'a', 'b', 'c', 'd', 'e'};
    char* morce[] = {"|", ".-", "-...", "-.-.", "-..", "."};

    char test[20] = "a abc";

    for(int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 27; j++)
        {
            if(test[i] == alpha[j])
            {
                printf("%s ", morce[j]);
            }
        }
    }

    return 0;
}