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

void test_non_null_terminated_array(void)
{
	char str[2]; //If its not a ull terminared string, ft_strlen fucks up
	str[0] = 'a';
	printf("strlen\t:\t\t%lu\n", strlen(str));
	printf("ft_strlen:\t:\t%zu\n", ft_strlen(str));

}

void	test_checknl(void)
{
	char	*str;

	str = "Banana\n";
	printf("This is strlen\t:%lu\n", strlen(str));
	printf("This is checkln\t:%zu\n", ft_check_nl(str));
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
}