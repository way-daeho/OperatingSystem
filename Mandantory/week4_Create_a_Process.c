#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;	  // 프로세스 번호를 저장하는 타입의 pid_t형 인스턴스 pid를 선언
	pid = fork(); // 프로세스를 생성하는 fork함수
	if (pid == -1)
	{									// 프로세스가 생성되지 않으면 -1을 반환
		printf("Error: cannot fork\n"); // 프로세스를 생성할 수 없다는 메세지 출력
		exit(1);						// 강제종료
	}

	if (pid == 0)
	{ // pid가 0이면 자식프로세서
		int j;
		for (j = 1; j <= 10; j++)
		{													// 1번부터 10번까지 자식프로세서 출력을 위한 반복문
			printf("\nChild : pid = %d %d\n", getpid(), j); // getpid는 실행중인 프로세스 ID를 구하는 함수
			sleep(1);										// 부모프로세서와 차이를 보여주기 위해 1초 딜레이
		}
	}
	else
	{ // 양수라면 부모프로세서
		int i;
		for (i = 1; i <= 10; i++)
		{													 // 1부터 10번까지 부모프로세서 출력
			printf("\nParent : pid = %d %d\n", getpid(), i); ////getpid는 실행중인 프로세스 ID를 구하는 함수
			sleep(2);										 // 자식 프로세스와 차이를 보여주기 위해 2초 딜레이를 준다.
		}
	}
	return 0; // 정상적인 종료를 위해 return 0을 해준다.
}
