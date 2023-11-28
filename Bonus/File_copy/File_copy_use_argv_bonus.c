#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) // 필수과제와 같이 argc에서 매개인자의 갯수를 받고, 개수 만큼 char *argv배열의 크기를 정해준다.
{
	FILE *inptr, *outptr;
	char Infile, Outfile, buffer[5] = {0, };

	inptr = fopen(argv[1], "r");

	if (inptr == NULL)
	{
		printf("ERROR : Can't open file %s\n", argv[1]);
		exit(1);
	}

	outptr = fopen(argv[2], "w");

	if (outptr == NULL)
	{
		printf("ERROR : Can't open file %s\n", argv[2]);
		exit(1);
	}

	while ((fread(buffer, sizeof(char), 1, inptr)) != EOF)
	{ // fread함수와 read함수는 용도는 똑같지만 사용목적이 다르다, 내용을 하나씩 받아오기위해 while문을 사용하였다. 그 이유는 받아오는 크기를 1로 지정하였기 때문에 파일에 내용이 없을 때 까지라는 조건을 두어서 하나씩 받아온다.
		fwrite(buffer, sizeof(char), 1, outptr);
	} // while문 조건에 맞게 fwrite함수를 사용하여 출력파일에 값을 복사해준다.
	/*  */
	printf("File copied.\n"); // 출력파일이 완성되면 복사완료가 되었다는 문장을 출력해준다.
	fclose(inptr);			  // 입력파일을 닫아준다.
	fclose(outptr);			  // 출력파일을 닫아준다.

	return 0;
}
