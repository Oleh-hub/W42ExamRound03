#include <stdio.h>
#include <limits.h> // INT_MAX

int ft_printf(const char *str, ...);

int main()
{
    char *s = "jkl";
    // int  i = -2147483648;
    // int  i = -123;
    // int  i = -2147483647;
    int  i = 2147483647;
    // int  i = -999;
    // int count = 0;

    printf("abbcccdddd\n");
    ft_printf("abbcccdddd\n");
    printf("%s\n", s);
    ft_printf("%s\n", s);
    printf("%d\n", i);
    ft_printf("%d\n", i);
    printf("a'%s'bc '%d' def\n", s, i);
    ft_printf("a'%s'bc '%d' def\n", s, i);
    printf("%%%%%%abbccc%%dddd\n");
    ft_printf("%%%%%%abbccc%%dddd\n");
}
