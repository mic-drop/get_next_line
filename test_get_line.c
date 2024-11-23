#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

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
    close(fd);
}
// If the end of file was reached and does not end with a \n character, return line without \n.
void test_end_file_no_nl(void)
{
    int fd = open("end_file.txt", O_RDONLY);
    char *line = get_next_line(fd);
    printf("Test\t:aaaaaaaaaaa");
    printf("Result\t: %s", line);
    printf("\n");
    free(line);
    close(fd);
}
//If there is nothing else to read or if an error occurred, it should return NULL.
void test_nothing_to_read(void)
{

    int fd = open("nothing.txt", O_RDONLY);
    char *line = get_next_line(fd);
    printf("Test\t: (null)\n");
    printf("Result\t: %s\n", line);
    free(line);
    close(fd);
}

void test_line_no_nl(void)
{
    int fd = open("line_no_nl.txt", O_RDONLY);
    char *line = get_next_line(fd);
    printf("Test\t: abcdefghijklmnopqrstuvwxyz\n");
    printf("Result\t: %s\n", line);
    free(line);
    close(fd);
}

int main(void)
{
    // test_get_line();
    test_end_file_no_nl();
    // test_nothing_to_read();
    test_line_no_nl();
    return (0);
}