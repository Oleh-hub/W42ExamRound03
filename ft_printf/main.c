#include <stdio.h>
#include <limits.h> // INT_MAX

int ft_printf(const char *str, ...);

int main()
{
    char *s = "jkl";
    // int  i = -2147483648;
    // int  i = -123;
    // int  i = -2147483647;
    // int  i = 2147483647;
    // int  i = 257;
    // int  i = -980;
    // int j = 0;
    int i = -1;
    int count = 0;

    // count = printf("abbcccdddd\n");
    // printf("count = %i\n", count);
    // count = ft_printf("abbcccdddd\n");
    // printf("count = %i\n", count);
    // count = printf("%s\n", s);
    // printf("count = %i\n", count);
    // count = ft_printf("%s\n", s);
    // printf("count = %i\n", count);
    // count = printf("%d\n", i);
    // printf("count = %i\n", count);
    // count = ft_printf("%d\n", i);
    // printf("count = %i\n", count);
    // count = printf("a'%s'bc '%d' def\n", s, i);
    // printf("count = %i\n", count);
    // count = ft_printf("a'%s'bc '%d' def\n", s, i);
    // printf("count = %i\n", count);
    // count = printf("%%%%%%abbccc%%dddd\n");
    // printf("count = %i\n", count);
    // count = ft_printf("%%%%%%abbccc%%dddd\n");
    // printf("count = %i\n", count);
    // count = printf("%d\n", 0x102);
    // printf("count = %i\n", count);
    // count = ft_printf("%d\n", 0x102);
    // printf("count = %i\n", count);
    // count = printf("a'%s'bc '%d' def, '%x', '%d', '%x' \n", s, i, i, j, j);
    // printf("count = %i\n", count);
    // count = ft_printf("a'%s'bc '%d' def, '%x', '%d', '%x' \n", s, i, i, j, j);
    // printf("count = %i\n", count);

    count = printf("%x\n", 258);
    printf("count = %i\n", count);
    count = ft_printf("%x\n", 258);
    printf("count = %i\n", count);
    count = printf("%x\n", i);
    printf("count = %i\n", count);
    count = ft_printf("%x\n", i);
    printf("count = %i\n", count);

}
