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
	printf("ft_strlen sunshine test:\t:\t%s\n", result);
	printf("Expected %lu and got %zu\n",strlen(str), ft_strlen(str) );
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
    printf("ft_strlen BIG str: %s\n", result == ft_strlen(str) ? "OK" : "FAIL");
    printf("Expected %lu and got %zu\n", result, ft_strlen(str));
    free(str); // Free the allocated memory
}

void	strlen_test_null(void)
{
	char *str;
	str = NULL;

	//printf("Strings size should be equal : %s\n", strlen(str) == ft_strlen(str) ? "OKAY" : "FAIL");
	// printf("Expected: %lu\n", strlen(str));
	printf("Got: %lu\n", ft_strlen(str));
	
}

//This should indicate that if my buffer is not null terminated, that the join will fuck up
//See line 45 of get_utils, final size will result of the sum between undefined behaviour and size of line
void test_strlen_non_null(void)
{
    char a[1 + 1];
    a[0] = 'a';
    a[1] = 'b';
    putchar(strlen(a) + 48);
	printf("strlen:\t:\t%zu\n", strlen(a));
	printf("ft_strlen:\t:\t%zu\n", ft_strlen(a));

}

//This tests seems to suggest that our BUFFER_SIZE needs a plus one to be null safe
//Althoug we are not causing a segfault
void test_non_null_terminated_array(void)
{
	char non_null_buff[40]; //If its not a ull terminared string, ft_strlen fucks up
    char null_safe_buff[41];
    int fd = open("41_no_nl", O_RDONLY);
    int fd2 = open("41_no_nl", O_RDONLY);
    reset_buffer(non_null_buff);
    reset_buffer(null_safe_buff);
    read(fd, non_null_buff, 40);
    read(fd2, null_safe_buff, 40);

	printf("strlen non null\t:\t\t%lu\n", strlen(non_null_buff));
	printf("ft_strlen non null:\t:\t%zu\n", ft_strlen(non_null_buff));
    printf("This is non_null buff: |%s|\n", non_null_buff);

	
    printf("strlen null safe\t:\t%lu\n", strlen(null_safe_buff));
	printf("ft_strlen null safe:\t:\t%zu\n", ft_strlen(null_safe_buff));
    printf("This is null_safe buff: |%s|\n", null_safe_buff);
}

/* Test Join */

//Sunshine
//Sunshine is giving seg fault because of free in line 54 of join
//However, so does vanda. This has to do with the first call being with line allways null
void	join_sunshine(void)
{
	char *expected = "bananamorango";
	char *banana = "banana";
	char *morango = "morango";

	char *result = ft_strjoin(banana, morango);

	printf("Strings should be equal : %s\n", strcmp(expected, result) == 0 ? "OKAY" : "FAIL");
	printf("Expected: %s\n", expected);
	printf("Got: %s\n", result);

	printf("Strings size should be equal : %s\n", strlen(result) == strlen(expected) ? "OKAY" : "FAIL");
	printf("Expected: %lu\n", strlen(expected));
	printf("Got: %lu\n", strlen(result));

}

//Actuall Sunshine
void join_join_null(void)
{

	char *expected = "morango";
	char *banana = NULL;
	char *morango = "morango";

	char *result = ft_strjoin(banana, morango);

	printf("Strings should be equal : %s\n", strcmp(expected, result) == 0 ? "OKAY" : "FAIL");
	printf("Expected: %s\n", expected);
	printf("Got: %s\n", result);

	printf("Strings size should be equal : %s\n", strlen(result) == strlen(expected) ? "OKAY" : "FAIL");
	printf("Expected: %lu\n", strlen(expected));
	printf("Got: %lu\n", strlen(result));

	char *kiwi = "kiwi";

	result = ft_strjoin(result, kiwi);
	printf("Strings should be equal : %s\n", strcmp("morangokiwi", result) == 0 ? "OKAY" : "FAIL");
	printf("Expected: %s\n", "morangokiwi");
	printf("Got: %s\n", result);

	printf("Strings size should be equal : %s\n", strlen(result) == strlen("morangokiwi") ? "OKAY" : "FAIL");
	printf("Expected: %lu\n", strlen("morangokiwi"));
	printf("Got: %lu\n", strlen(result));
}

void	join_non_null_str(void)
{
	char non_null[3];//Change this to exact number of bytes read and see the undefined behavioour
	char *line = NULL;
	int fd = open("camoes.txt", O_RDONLY);
	read(fd, non_null, 2);
	line = ft_strjoin(line, non_null);

	printf("Line is |%s|, with size %lu\n", line, strlen(line));	
	read(fd, non_null, 2);
	line = ft_strjoin(line, non_null);

	printf("Line is |%s|, with size %lu\n", line, strlen(line));	
}

/*  Test checknl */

void	test_checknl(void)
{
	char	*str;

	str = "Banana\n";
	printf("This is strlen\t:%lu\n", strlen(str));
	printf("This is checkln :%d\n", ft_check_nl(str));
}

void    check_no_nl(void)
{
	char	*str;
    char    *result;
	str = "Banana";
	result = ft_check_nl(str) == -1 ? "OK" : "FAIL";
	printf("Test check_nl with no nl :%s\n", result);
    printf("Expected -1 and got %d\n", ft_check_nl(str));

}

void	test_reset_return(void)
{
    char *str;
    int fd = open("aloola.txt", O_RDONLY);
    str = get_next_line(fd);
    printf("line: |%s|\n", str);


}

int	main(void)
{
/* Strlen */
	test_strlen();
	test_big_len();
	// strlen_test_null();
    // test_strlen_non_null();
	// test_non_null_terminated_array();

/* Str join */
	// join_sunshine();
	// join_join_null();
	// join_non_null_str();

/* check_nl */
	// test_checknl();
    // check_no_nl();
    
/* Reset and return */
    // test_reset_return();
}