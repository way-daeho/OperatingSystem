#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int fdB;
	mkfifo("NamedPipeLineEx", 0666);
	char ph1[100], ph2[100];
	while (1)
	{
		fdB = open("NamedPipeLineEx", O_RDONLY);
		read(fdB, ph1, 100);
		printf("ph1: %s\n", ph1);
		close(fdB);
		fdB = open("NamedPipeLineEx", O_WRONLY);
		fgets(ph2, 100, stdin);
		write(fdB, ph2, strlen(ph2) + 1);
		close(fdB);
	}
	return 0;
}
