#include <stdio.h>
#include <string.h>
char t[32][32], g[32], c = '0', r;
int a, b;

void binadd()
{
    for (int i = 1; i < a; i++)
    {
        for (int j = b - 1; j >= 0; j--)
        {
            if (t[i][j] == g[j] && g[j] == '0')
            {
                if (c == '0')
                    g[j] = '0';
                else
                    g[j] = '1';
            }
            else if (t[i][j] == g[j] && g[j] == '1')
            {
                if (c == '0')
                {
                    g[j] = '0';
                    c = '1';
                }
                else
                {
                    g[j] = '1';
                    c = '1';
                }
            }

            else if (t[i][j] == '1' || g[j] == '1')
            {
                if (c == '0')
                {
                    g[j] = '1';
                    c = '0';
                }
                else
                {
                    g[j] = '0';
                    c = '1';
                }
            }
        }
        if (c == '1')
        {
            for (int j = b - 1; j >= 0; j--)
            {
                if (g[j] == '1' && c == '1')
                {
                    g[j] = '0';
                    c = '1';
                }
                else if (g[j] == '0' && c == '1')
                {
                    g[j] = '1';
                    c = '0';
                }
            }
        }
        c = '0';
    }
}

int main()
{
    printf("enter the total no of numbers\n");
    scanf("%d", &a);
    printf("enter the total no of bits\n");
    scanf("%d", &b);
    for (int i = 0; i < a; i++)
    {
        printf("Enter the no %d\n", i + 1);
        scanf("%s", t[i]);
    }
    strcpy(g, t[0]);
    printf("%s\n", g);
    binadd();
    printf("%s\n", g);
}
