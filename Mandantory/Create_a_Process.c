#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid; // 프로세스를 저장하는 타입인 pid_t형 pid를 선언
	/* fork a child process*/
	pid = fork(); // 자식 프로세스를 만드는 fork함수를 선언

	if (pid < 0)
	{ /* error occurred */
		// pid
		fprintf(stderr, "Fork Failed\n");
		return 1;
	}
	else if (pid == 0)
	{ /* pid값이 0이면 child process */
		execlp("/bin/ls", "ls", NULL);
		// execlp함수는 경로에 등록된 디렉토리를 참고하여 다른 프로그램을 실행하고 종료한다.
		// 자식프로세스가 생성되면 현재디렉토리에 있는 디렉토리를 출력한다.
	}
	else
	{								/* pid값이 0보다 크면 parent process */
		wait(NULL);					/*parent will wait for the child to complete */
		printf("Child Complete\n"); // 자식 프로세서가 종료되면 완료되었다고 출력한다.
	}

	return 0;
}
