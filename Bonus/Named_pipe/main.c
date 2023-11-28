#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int fd;

	mkfifo("NamedPipeLineEx", 0666);

	if (mkfifo("NamedPipeLineEx", 0666) == -1)
	{
		perror("NamedPipe가 생성되지 않았습니다.");
		exit(1);
	}

	char mes[100];
	while (1)
	{
		fd = open("NamedPipeLineEx", O_WRONLY);
		gets(mes);
		write(fd, mes, 100);
		close(fd);
	}
	return 0;
}
