#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

//Your function should return the line including the terminating \n character
void test_get_line(void)
{

    printf("### Testing Multiple lines ####\n");

    int fd = open("camoes.txt", O_RDONLY);
    char *line = get_next_line(fd);
    printf("Test\t: |Os bons vi sempre passar\n|\n");
    printf("Result\t: |%s|\n", line);
    free(line);
    line = get_next_line(fd);
    printf("Test\t: |No mundo graves tormentos;\n|\n");
    printf("Result\t: |%s|\n", line);
    free(line);
    
    line = get_next_line(fd);
    printf("Test\t: |E para mais me espantar\n|\n");
    printf("Result\t: |%s|\n", line);
    free(line);
    
    line = get_next_line(fd);
    printf("Test\t: |Os maus vi sempre nadar\n|\n");
    printf("Result\t: |%s|\n", line);
    free(line);
    
    line = get_next_line(fd);
    printf("Test\t: |Em mar de contentamentos.|\n");
    printf("Result\t: |%s|\n", line);
    free(line);
    
    printf("\n");
}

// If the end of file was reached and does not end with a \n character, return line without \n.
void test_end_file_no_nl(void)
{
    printf("### Testing End of FIle - NO NL ####\n");
    int fd = open("end_file.txt", O_RDONLY);
    char *line = get_next_line(fd);
    printf("Test\t: |aaaaaaaaaaa|\n");
    printf("Result\t: |%s|\n", line);
    free(line);

    printf("\n");
}

void test_line_no_nl(void)
{
    //
    int fd = open("line_no_nl.txt", O_RDONLY);
    char *line = get_next_line(fd);
    printf("Test\t: |abcdefghijklmnopqrstuvwxyz|\n");
    printf("Result\t: |%s|\n", line);
    free(line);

   line = get_next_line(open("41_no_nl", O_RDONLY));
    printf("Test\t: |01234567890123456789012345678901234567890|\n");
    printf("Result\t: |%s|\n", line);
    
    free(line);
    printf("\n");
}

//If there is nothing else to read or if an error occurred, it should return NULL.
void test_nothing_to_read(void)
{

    printf("### Testing Nothing to read ####\n");
    int fd = open("nothing.txt", O_RDONLY);
    char *line = get_next_line(fd);
    printf("Test\t: |(null)|\n");
    printf("Result\t: |%s|\n", line);
    free(line);
    printf("\n");
}


void test_reach_end_of_file_with_line(void)
{
    printf("### Testing End of File WITH NL ####\n");
    //1 line with nl
	int	fd = open("a.txt", O_RDONLY);
    char	*line = get_next_line(fd);
	printf("Test\t: |a\n|\n");
	printf("Result\t: |%s|\n", line);
	free(line);
    //Try to read after end of file
	line = get_next_line(fd);
	printf("Test\t: |(null)|\n");
	printf("Result\t: |%s|\n", line);
	free(line);
    printf("\n");
}

//We consider that get_next_line() has an undefined behavior if the file pointed to
// by the file descriptor changed since the last call whereas read() didn’t reach the
// end of file.
void multiple_fd(void)
{
    printf("### Testing Multiple FDs ####\n");
    //Ope, read, close 1st file
	int	fd = open("camoes.txt", O_RDONLY);
    char	*line = get_next_line(fd);
	printf("Test\t: |Os bons vi sempre passar\n|\n");
	printf("Result\t: |%s|\n", line);
    //Ope, read, close 2nd file
    int fd2 = open("end_file.txt", O_RDONLY);
    line = get_next_line(fd2);
	printf("Test\t: |aaaaaaaaaaa|\n");
	printf("Result\t: |%s|\n", line);

    printf("\n");
}

void    test_non_existing_fd(void)
{
    printf("### Testing Non exisitng fd####\n");
    char	*line = get_next_line(74);
	printf("Test\t: |(null)|\n");
	printf("Result\t: |%s|\n", line);
    free(line);

}

int main(void)
{
    test_get_line();
    test_end_file_no_nl();
    test_line_no_nl();
    test_nothing_to_read();
	test_reach_end_of_file_with_line();
    // multiple_fd();
    test_non_existing_fd();
    return (0);
}