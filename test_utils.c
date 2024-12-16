#include "get_next_line.h"
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void	test_strlen(void)
{
	char	*str;
	char	*result;

	str = "Banana";
	result = ft_strlen(str) == strlen(str) ? "OK" : "FAIL";
	printf("ft_strlen:\t:\t%s\n", result);
	printf("strlen\t:\t\t%lu\n", strlen(str));
	printf("ft_strlen:\t:\t%d\n", ft_strlen(str));
}

void	test_checknl(void)
{
	char	*str;

	str = "Banana\n";
	printf("This is strlen\t:%lu\n", strlen(str));
	printf("This is checkln\t:%d\n", ft_check_nl(str));
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
	test_strlen();
	test_checknl();
    test_reset_return();
}