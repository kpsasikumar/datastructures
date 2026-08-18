//Ex. No. 1(a) One Dimensional and Multidimensional Arrays

#include <stdio.h>
void main()
{
    int arr_one[6] = {11, 12, 13, 14, 15, 16};
    printf("\n Single Dimensional Array");
    printf("\n -----------------------\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%5d", arr_one[i]);
    }

    int arr_two[2][3] = {
                            {11, 12, 13},
                            {21, 22, 23},
                        };

    printf("\n\n Two Dimensional Array");
    printf("\n ---------------------- \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%5d", arr_two[i][j]);
        }
        printf("\n");
    }

    int arr_three[2][3][3] =    {
                                {
                                    {111, 112, 113},
                                    {121, 122, 123},
                                    {131, 132, 133}
                                },
                                {
                                    {211, 212, 213},
                                    {221, 222, 223},
                                    {231, 232, 233}
                                }
                        };

    printf("\n\n Three Dimensional Array");
    printf("\n ---------------------- ");
    for (int i = 0; i < 2; i++)
    {
        printf("\n Layer %d:\n", i);

        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                printf("%5d", arr_three[i][j][k]);
            }
            printf("\n");
        }
    }
}
