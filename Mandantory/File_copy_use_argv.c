#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
// int argc는 파일의 갯수를 받는다. 이 코드에서는 명령어처럼 사용할 파일의 이름, 입력,출력 파일 총 3개의 인자를 받는다.
// 받은 이후 *argv배열 크기를 지정해준다.
{
	char c;				  // 파일의 내용을 받아주는 변수
	FILE *inptr, *outptr; // 입출력파일의 주소를 받아주는 파일형 변수.

	if ((inptr = fopen(argv[1], "r")) == NULL) // 만약 argv[1]에 저장되어있는 입력파일이 없다는 제어문
	{
		printf("ERROR:can't open file %s\n", argv[1]); // 입력파일을 열 수 없다고 출력
		exit(1);									   // 강제종료
	}
	if ((outptr = fopen(argv[2], "w")) == NULL) // argv[2]에 저장된 출력파일 이름이 NULL값이라면
	{
		printf("ERROR:can't not open file %s\n", argv[2]); // 파일을 열 수 없다고 출력
		exit(1);										   // 강제종료
	}
	while ((c = getc(inptr)) != EOF) // 반복문을 사용하여 파일안에 값을 하나씩 받는다 입력파일의 값의 끝까지 실행
		putc(c, outptr);			 // 입력파일에 있는 내용 하나하나 반복문이 끝날 때 까지 출력파일에 입력을 해준다.
	printf("File copied.\n");		 // 파일이 복사가 끝났다는 메세지 출력
	fclose(inptr);					 // 입력파일을 닫아준다.
	fclose(outptr);					 // 출력파일을 닫아준다.

	return (0);
}
