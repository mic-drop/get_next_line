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
	printf("ft_strlen sunshine test: %s\n", result);
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

    printf("ft_strlen NULL ptr: %s\n", ft_strlen(str) == 0 ? "OK" : "FAIL");
	printf("Expected 0 and got %lu\n", ft_strlen(str));
	
}

void strlen_test_empty_str(void)
{
	char *str = "";

    printf("ft_strlen empty str: %s\n", ft_strlen(str) == 0 ? "OK" : "FAIL");
	printf("Expected 0 and got %lu\n", ft_strlen(str));

}

//This should indicate that if my buffer is not null terminated, that the join will fuck up
//See line 45 of get_utils, final size will result of the sum between undefined behaviour and size of line
//Should return undefined behaviour
void test_strlen_non_null(void)
{
    char a[1 + 1];
    a[0] = 'a';
    a[1] = 'b';
	printf("strlen:\t:\t%zu\n", strlen(a));
	printf("ft_strlen:\t:\t%zu\n", ft_strlen(a));

}
void test_strlen_null_terminated(void)
{
    char a[1 + 1];
    a[0] = 'a';
    a[1] = '\0';
    printf("ft_strlen null terminated array str: %s\n", ft_strlen(a) == strlen(a) ? "OK" : "FAIL");
	printf("Expected 1 and got %lu\n", ft_strlen(a));

}

//This tests seems to suggest that our BUFFER_SIZE needs a plus one to be null safe
//Althoug we are not causing a segfault
void test_non_null_terminated_array(void)
{
	char *non_null_buff = calloc(40, sizeof(char) + 1); //If its not a ull terminared string, ft_strlen fucks up
    char *null_safe_buff = calloc(41, sizeof(char) + 1);
    int fd = open("41_no_nl", O_RDONLY);
    int fd2 = open("41_no_nl", O_RDONLY);
    read(fd, non_null_buff, 40);
    read(fd2, null_safe_buff, 40);
	int non_safe_len = strlen(non_null_buff);
	int ft_non_safe_len =  ft_strlen(non_null_buff);

	printf("Test strlen non null buffer:\t%s\n", ft_non_safe_len == non_safe_len ? "OK" : "FAIL");
	printf("Expected %d and got %d\n", non_safe_len, ft_non_safe_len);
    printf("This is non_null buff: |%s|\n", non_null_buff);

	int safe_len = strlen(null_safe_buff);
	int ft_safe_len =  ft_strlen(null_safe_buff);
	
	printf("Test strlen null safe buffer:\t%s\n", ft_safe_len == safe_len ? "OK" : "FAIL");
	printf("Expected %d and got %d\n", safe_len, ft_safe_len);
    printf("This is null_safe buff: |%s|\n", null_safe_buff);
	printf("Test non safe vs safe buff:\t%s\n", (safe_len == 40 && non_safe_len > 40) ?"OK" : "FAIL");
	free(non_null_buff);
	free(null_safe_buff);
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

	printf("Strings should be equal : %s\n", strcmp(expected, result) == 0 ? "OK" : "FAIL");
	printf("Expected: %s\n", expected);
	printf("Got: %s\n", result);

	printf("Strings size should be equal : %s\n", strlen(result) == strlen(expected) ? "OK" : "FAIL");
	printf("Expected: %lu\n", strlen(expected));
	printf("Got: %lu\n", strlen(result));
	free(result);

}

//Actuall Sunshine
void join_join_null(void)
{

	char *expected = "morango";
	char *banana = NULL;
	char *morango = "morango";

	char *result = ft_strjoin(banana, morango);

	printf("Strings should be equal : %s\n", strcmp(expected, result) == 0 ? "OK" : "FAIL");
	printf("Expected: %s\n", expected);
	printf("Got: %s\n", result);

	printf("Strings size should be equal : %s\n", strlen(result) == strlen(expected) ? "OK" : "FAIL");
	printf("Expected: %lu\n", strlen(expected));
	printf("Got: %lu\n", strlen(result));

	char *kiwi = "kiwi";

	result = ft_strjoin(result, kiwi);
	printf("Strings should be equal : %s\n", strcmp("morangokiwi", result) == 0 ? "OK" : "FAIL");
	printf("Expected: %s\n", "morangokiwi");
	printf("Got: %s\n", result);

	printf("Strings size should be equal : %s\n", strlen(result) == strlen("morangokiwi") ? "OK" : "FAIL");
	printf("Expected: %lu\n", strlen("morangokiwi"));
	printf("Got: %lu\n", strlen(result));
	free(result);
}

void	join_non_null_str(void)
{
	static char non_null[3];//Change this to exact number of bytes read and see the undefined behavioour
	char *line = NULL;
	int fd = open("camoes.txt", O_RDONLY);
	read(fd, non_null, 2);
	line = ft_strjoin(line, non_null);

    printf("Testing join of null with null terminated buffer: %s\n", strcmp(line, "Os") == 0 ? "OK" : "FAIL");
	printf("Expected |Os| and got |%s|  \n", line);	
	printf("Expected size 2 and got %lu\n", strlen(line));	
	read(fd, non_null, 2);
	line = ft_strjoin(line, non_null);

    printf("Testing second  join of null with null terminated buffer: %s\n", strcmp(line, "Os b") == 0 ? "OK" : "FAIL");
	printf("Expected |Os b| and got |%s|\n", line);	
	printf("Expected size 4 and got %lu\n", strlen(line));
	free(line);	
}

void    join_null_ptr_with_empty_str(void)
{
    char *line = NULL;
    char *buff = "";

    char *result = ft_strjoin(line, buff);

    printf("Test join empty strings: %s\n", strcmp(result, "") == 0 ? "OK" : "FAIL");
    printf("Expected || and got |%s|\n", result);
	free(result);

};
//Gives segmentation fault because of buffer
void    join_null_ptr_with_null_ptr(void)
{
    char *line = NULL;
    char *buff = NULL;

    char *result = ft_strjoin(line, buff);

    printf("Test join NULL pointers: %s\n", strcmp(result, "") == 0 ? "OK" : "FAIL");
    printf("Expected || and got |%s|\n", result);
	free(result);

}
//Core dumped Line cant be empty string
void join_empty_str_with_empty_str(void)
{
    char *line = "";
    char *buff = "";

    char *result = ft_strjoin(line, buff);

    printf("Test join empty strings: %s\n", strcmp(result, "") == 0 ? "OK" : "FAIL");
    printf("Expected || and got |%s|\n", result);
}

void	join_null_str_with_empty_buff(void)
{
	static char empty_buff[3];
	char *line = NULL;
    char *result = ft_strjoin(line, empty_buff);
    printf("Test join NULL string with empty buffer: %s\n", strcmp(result, "") == 0 ? "OK" : "FAIL");
    printf("Expected || and got |%s|\n", result);
	free(result);
}

/*  Test checknl */

void	test_checknl(void)
{
	char	*str;

	str = "Banana\n";
	printf("Test check_nl sunshine: %s\n", ft_check_nl(str) == 6 ? "OK" : "FAIL");
	printf("Expected 6 and got %d\n", ft_check_nl(str));
}

void    check_no_nl(void)
{
	char	*str;
    char    *result;
	str = "Banana";
	result = ft_check_nl(str) == -1 ? "OK" : "FAIL";
	printf("Test check_nl with no nl: %s\n", result);
    printf("Expected -1 and got %d\n", ft_check_nl(str));
}

void	check_nl_empty_line(void)
{
	char	*str = "";
    char    *result;
	result = ft_check_nl(str) == -1 ? "OK" : "FAIL";
	printf("Test check_nl with no nl: %s\n", result);
    printf("Expected -1 and got %d\n", ft_check_nl(str));
}
//Gives segmentation fault
//added protection if(!line) return -1;
void	check_nl_NULL_line(void)
{
	char	*str = NULL;
    char    *result;
	result = ft_check_nl(str) == -1 ? "OK" : "FAIL";
	printf("Test check_nl with no nl: %s\n", result);
    printf("Expected -1 and got %d\n", ft_check_nl(str));

}

void	test_reset_buffer(void)
{
	char	buff[3] = "123";
	reset_buffer(buff);
	if(buff[0] == '\0' && buff[1] == '\0' && buff[2] == '\0')
		printf("Test reset buffer: OK\n");
	else
		printf("Test reset buffer: FAIL\n");
}
void	test_reset_static_buffer(void)
{
	static char	buff[3] = "321";
	reset_buffer(buff);
	if(buff[0] == '\0' && buff[1] == '\0' && buff[2] == '\0')
		printf("Test reset static buffer: OK\n");
	else
		printf("Test reset static buffer: FAIL\n");
}
/*  Test Reset Buffer */

void	test_reset_empty_buffer(void)
{
	char *buff = calloc(3, sizeof(char));
	reset_buffer(buff);
	if(buff[0] == '\0' && buff[1] == '\0' && buff[2] == '\0')
		printf("Test reset empty buffer: OK\n");
	else
		printf("Test reset empty buffer: FAIL\n");
	free(buff);
}
void	test_reset_empty_static_buffer(void)
{
	static char	buff[3];
	reset_buffer(buff);
	if(buff[0] == '\0' && buff[1] == '\0' && buff[2] == '\0')
		printf("Test reset empty static buffer: OK\n");
	else
		printf("Test reset empty static buffer: FAIL\n");
}
//Gives segfault if buffer is NULL
// We added protection
void	test_reset_NULL_ptr(void)
{
	char	*buff = NULL;
	reset_buffer(buff);
	if(!buff)
		printf("Test reset null pointer: OK\n");
	else
		printf("Test reset null pointer: FAIL\n");
}

void	test_reset_static_NULL_ptr(void)
{
	static char	*buff = NULL;
	reset_buffer(buff);
	if(!buff)
		printf("Test reset static null pointer: OK\n");
	else
		printf("Test reset static null pointer: FAIL\n");
}

/* Test Reset and return */

void	test_reset_return(void)
{
	static char static_buff[9] = "ola\nalo\n";
	char expected_buff[9] = "alo\n";
	char *line = ft_strjoin(NULL, static_buff);
	if(!*static_buff)
		return;
	ft_reset__and_return(static_buff, line, 8);
	printf("Testing reset return 1:\n");
	printf("\t Buffer content: %s\n", strcmp(static_buff, expected_buff) == 0 ? "OK" : "FAIL");
	printf("\t\tExpected buff to be |%s|\n\t\tAnd got |%s|\n", expected_buff, static_buff);	
	printf("\t Buffer size: %s\n", strlen(static_buff) == strlen(expected_buff) ? "OK" : "FAIL");
	printf("\t\tExpected buffer size to be %lu and got %lu\n\n", strlen(static_buff), strlen(expected_buff));

	printf("\t Line content: %s\n", strcmp(line, "ola\n") == 0 ? "OK" : "FAIL");
	printf("\t\tExpected line to be |ola\n|\n\t\tAnd got |%s|\n", line);
	printf("\t Line size: %s\n", strlen(line) == strlen("ola\n") ? "OK" : "FAIL");
	printf("\t\tExpected line size to be 4 and got %lu\n", strlen(line));

	free(line);
	line = NULL;
	line = ft_strjoin(line, static_buff);
	ft_reset__and_return(static_buff, line, 8);
	reset_buffer(expected_buff);
	printf("Testing reset return 2:\n");
	printf("\t Buffer content: %s\n", strcmp(static_buff, expected_buff) == 0 ? "OK" : "FAIL");
	printf("\t\tExpected buff to be |%s|\n\t\tAnd got |%s|\n", expected_buff, static_buff);	
	printf("\t Buffer size: %s\n", strlen(static_buff) == strlen(expected_buff) ? "OK" : "FAIL");
	printf("\t\tExpected buffer size to be %lu and got %lu\n\n", strlen(static_buff), strlen(expected_buff));

	printf("\t Line content: %s\n", strcmp(line, "alo\n") == 0 ? "OK" : "FAIL");
	printf("\t\tExpected line to be |alo\n|\n\t\tAnd got |%s|\n", line);
	printf("\t Line size: %s\n", strlen(line) == strlen("alo\n") ? "OK" : "FAIL");
	printf("\t\tExpected line size to be 4 and got %lu\n", strlen(line));
	free(line);

}

int	main(void)
{
/* Reset and return */
    test_reset_return(); // needs to be tested first. But why?
/* Strlen */
	test_strlen();
	// test_big_len();
	strlen_test_null();
    strlen_test_empty_str();
    // test_strlen_non_null(); This test only proves that strlen must recieve a null terminated string
    test_strlen_null_terminated();
	test_non_null_terminated_array();

/* Str join */
	// join_sunshine(); Segfault
	join_join_null();
	join_non_null_str();
    join_null_ptr_with_empty_str();
    // join_null_ptr_with_null_ptr(); Segfaults
    // join_empty_str_with_empty_str(); Core Dumps
	join_null_str_with_empty_buff();

/* check_nl */
	test_checknl();
    check_no_nl();
	check_nl_empty_line();
	check_nl_NULL_line();

/*  test_reset_buffer */
	test_reset_buffer();
	test_reset_static_buffer();
	test_reset_empty_buffer();
	test_reset_empty_static_buffer();
	test_reset_NULL_ptr();
	test_reset_static_NULL_ptr();

}