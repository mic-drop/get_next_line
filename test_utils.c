#include "get_next_line.h"
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


/* *
	Testing strlen()
 **/

//Sunshine
void	test_strlen(void)
{
	char	*str;
	char	*result;

	str = "Banana";
	result = ft_strlen(str) == strlen(str) ? "OK" : "FAIL";
	printf("ft_strlen:\t:\t%s\n", result);
	printf("strlen\t:\t\t%lu\n", strlen(str));
	printf("ft_strlen:\t:\t%zu\n", ft_strlen(str));
}

void test_big_len(void)
{
    char *str;
    long unsigned int i = 0;

    // Allocate memory on the heap
    str = malloc(2147483649UL * sizeof(char));
    if (str == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    // Fill the array
    while (i < 2147483649UL)
    {
        str[i] = 'a';
        i++;
    }
    str[i - 1] = '\0';  // Set null terminator correctly

    // Uncomment below to test strlen (it may be slow due to size)
    long unsigned int result = strlen(str);
    printf("strlen: %lu\n", result);
	printf("ft_strlen:\t:\t%zu\n", ft_strlen(str));
    free(str); // Free the allocated memory
}
void test_strlen_null(void)
{
    char a[1 + 1];
    a[0] = 'a';
    a[1] = '\0';
	printf("strlen:\t:\t%zu\n", strlen(a));
	printf("ft_strlen:\t:\t%zu\n", ft_strlen(a));

}


void test_non_null_terminated_array(void)
{
	char str[40]; //If its not a ull terminared string, ft_strlen fucks up
    int fd = open("41_no_nl", O_RDONLY);
    int i = 0;
    reset_buffer(str);
    read(fd, str, 40);
    str[40] = '\0';
    while(str[i] != NULL)
    {
        write(1, &str[i], 1);
        write(1, "\n", 1);
        // printf("This is str %s\n", str);
        // printf("This is str[%d]: |%c|\n", i, str[i]);
        i++;
    }
    printf("\n******** i < 40 **********\n");
    i = 0;
    while(i < 40)
    {
        printf("This is str[i]: |%c|\n", str[i]);
        i++;
    }
    printf("\n***** while(str[i]) *************\n");
    i = 0;
    while(str[i])
    {
        printf("This is str[i]: |%c|\n", str[i]);
        i++;
    }
    printf("|%s|\n", str);
    printf("Last char in str |%c|\n", str[39]);
    printf("Last char in str |%c|\n", str[40]);
    printf("Last char in str |%c|\n", str[41]);
	printf("strlen\t:\t\t%lu\n", strlen(str));
	printf("ft_strlen:\t:\t%zu\n", ft_strlen(str));
}

void	test_checknl(void)
{
	char	*str;

	str = "Banana\n";
	printf("This is strlen\t:%lu\n", strlen(str));
	printf("This is checkln :%zu\n", ft_check_nl(str));
}

void	test_reset_return(void)
{
    char *txt = "Ola\nAlo\n";
    char *str;
    int fd = open("aloola.txt", O_RDONLY);
    str = get_next_line(fd);
    printf("line: |%s|", str);


}

int	main(void)
{
	// test_strlen();
	// test_big_len();
	test_non_null_terminated_array();
	// test_checknl();
    // test_reset_return();
    // test_strlen_null();
}