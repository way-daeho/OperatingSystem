#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int fd;
	char mes[100];
	while (1)
	{
		fd = open("NamedPipeLineEx", O_RDONLY);
		read(fd, mes, sizeof(mes));
		printf("Client: %s\n", mes);
		close(fd);
	}
	return 0;
}
