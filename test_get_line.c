#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

//Your function should return the line including the terminating \n character
void test_get_line(void)
{
    int fd = open("camoes.txt", O_RDONLY);
    char *line = get_next_line(fd);
    printf("Test\t: Os bons vi sempre passar\n");
    printf("Result\t: %s", line);
    line = get_next_line(fd);
    printf("Test\t: No mundo graves tormentos;\n");
    printf("Result\t: %s", line);
}
// If the end of file was reached and does not end with a \n character, return line without \n.
void test_end_file_no_nl(void)
{
    int fd = open("end_file.txt", O_RDONLY);
    char *line = get_next_line(fd);
    printf("Test\t:aaaaaaaaaaa");
    printf("Result\t: %s", line);
}
//If there is nothing else to read or if an error occurred, it should return NULL.

int main(void)
{
    test_get_line();
    test_end_file_no_nl();
    return (0);
}