#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int fdA;

	mkfifo("NamedPipeLineEx", 0666);

	char ph1[100], ph2[100];
	while (1)
	{
		fdA = open("NamedPipeLineEx", O_WRONLY);
		fgets(ph2, 100, stdin);
		write(fdA, ph2, strlen(ph2) + 1);
		close(fdA);
		fdA = open("myfifo", O_RDONLY);
		read(fdA, ph1, sizeof(ph1));
		printf("User2: %s\n", ph1);
		close(fdA);
	}
	return 0;
}
