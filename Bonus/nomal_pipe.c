#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 25 // 버퍼사이즈를 25로 설정
#define READ_END 0	   // fd표준입력 0
#define WRITE_END 1	   // fd표준출력 1

int main(void)
{
	char write_msg[BUFFER_SIZE] = "Greetings"; // 메세지를 써주기 위한 파이프라인 넣어준 데이터를 확인하기 위해서 넣어준 문장
	char read_msg[BUFFER_SIZE];				   // 메세지 읽기를 위한 파이프라인

	int fd[2]; // 파일 디스크립터 읽기와 쓰기를 넣어주기 위해 크기가 2인 배열 생성
	pid_t pid; // 프로세스 아이디를 구별하기 위해 선언한 변수

	if (pipe(fd) == -1)
	{									// 프로세스가 생성되지 않는 경우
		fprintf(stderr, "Pipe failed"); // 표준에러와 함께 파이프가 생성되지 않았음을 출력함
		return 1;						// 종료시킨다.
	}
	pid = fork(); // fork를 사용하여 프로세스를 실행시킨다.

	if (pid < 0)
	{									// 프로세스 생성실패
		fprintf(stderr, "Fork Failed"); // 표준에러와 함께 프로세스가 생성되지 않았음을 출력
		return 1;						// 종료시킨다.
	}

	if (pid > 0)
	{															// pid가 0보다 큰 경우는 부모 프로세스이다.
		close(fd[READ_END]);									// 쓰기를 위해서 읽기 파이프 라인을 닫아준다.
		write(fd[WRITE_END], write_msg, strlen(write_msg) + 1); // 쓰기를 해준다. fd값을 표준 입력으로 하고, 메세지 입력 버퍼에,메세지버퍼의 길이보다 1을 더해줘서 NULL값을 더해준다.
		close(fd[WRITE_END]);									// 쓰기가 완료되면 쓰기 파이프라인을 닫아준다.
	}
	else
	{											   // 0보다 크지도 않고 작지도 않은 경우는 0일 때 즉, 자식프로세스 일 때이다.
		close(fd[WRITE_END]);					   // 쓰기모드를 닫아준다. 자식프로세서는 Consumer의 개념이기 때문이다.
		read(fd[READ_END], read_msg, BUFFER_SIZE); // read함수를 사용하여 fd값을 읽기모드로 변경 후, 리드 메세지 파이프 라인을 사용하여 버퍼 사이즈만큼 메세지를 받아온다.
		printf("read %s\n", read_msg);			   // 받아온 메세지를 출력해준다.
		close(fd[READ_END]);					   // 읽기가 끝나면 읽기파이프라인을 닫아준다.
	}

	return 0;
}
