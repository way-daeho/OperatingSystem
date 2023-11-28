#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>

int main()
{
	/* the size (in bytes) of shared memory object*/
	const int SIZE = 4096; // 공유 메모리의 크기
	/* name of the shared memory object */
	const char *name = "OS"; // 공유메모리 객체의 이름을 OS로 선언한다.
	/* string written to shared memory */
	const char *message_0 = "Hello"; // 공유메모리 0에 "Hello"를 넣어준다.
	const char *message_1 = "World"; // 공유메모리 1에 "World"를 넣어준다.

	/* Shared memory file descriptor */
	int fd; // 읽기 신호인지 쓰기신호인지 보내주는 신호연산자
	/* pointer to shared memory object */
	char *ptr; // 공유메모리 객체의 주소를 저장해주는 포인터를 선언한다.(공유메모리에 들어간 값들이 char형이기에 char형으로 선언)

	/* create the shared memory object */
	fd = shm_open(name, O_CREAT | O_RDWR, 0666); // 읽기 쓰기 신호에 공유메모리를 열겠다는 신호를 보내준다
												 // shm_open함수의 인자로 공유메모리 객체, 객체 생성 및 객체 읽기쓰기,리눅스에서 권한을 지정하는 번호

	/* configure the size of the shared memory object */
	ftruncate(fd, SIZE); // 파일 디스크립터로 파일 크기를 변경해는 함수다 매개인자로 파일 디스크립터와 공유메모리의 크기를 적어준다.

	/* memory map the shared memory object */
	ptr = (char *)												  /// shared 메모리 위치
		mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0); // mmap 0 ~ 공유메모리 사이즈만큼 ptr주소를 맞추어 준다. READ, write함수를 쓰지 않고 공유메모리로 사용할 수 있게 한다. 처음의 0은 시작주소이다.

	/* write to the shared memory object */
	sprintf(ptr, "%s", message_0);
	/* sprintf는 출력하는 결과 값을 변수에 저장해주는는 기능이 있다. 그러므로 ptr 공유 메모리에 저장되어있는 message_0를 출력한다. */
	ptr += strlen(message_0);
	/* message_0의 길이만큼 메모리 공간을 할당해주기 위해 strlen함수를 이용해준다. */
	sprintf(ptr, "%s", message_1); // 위 message_0과 같다.
	ptr += strlen(message_1);

	return 0;
}
