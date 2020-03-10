/* Libraries for testing
#include <stdio.h>
#include <fcntl.h>
Delete*/

/*TESTS
int main (void)
{
	int 	fd = open("read.txt", O_RDONLY);	
	int 	fd2 = open("read2.txt", O_RDONLY);
	int 	fd3 = open("read3.txt", O_RDONLY);

	char	*line;
	char	*line2;
	char	*line3;
	int		result;
	int		counter;

	counter = 0;
	while (counter < 3 && (result = get_next_line(fd, &line)))
	{
		printf("CODE >>%d<<\n", result);
		printf("%s\n\n", line);
		counter++;
	}
	while (counter < 6 && (result = get_next_line(fd2, &line2)))
	{
		printf("CODE >>%d<<\n", result);
		printf("%s\n\n", line2);
		counter++;
	}
	while (counter < 9 && (result = get_next_line(fd3, &line3)))
	{
		printf("CODE >>%d<<\n", result);
		printf("%s\n\n", line3);
		counter++;
	}
	while (counter < 12 && (result = get_next_line(fd, &line)))
	{
		printf("CODE >>%d<<\n", result);
		printf("%s\n\n", line);
		counter++;
	}
	free(line);
 	free(line2);
	free(line3); 
} */