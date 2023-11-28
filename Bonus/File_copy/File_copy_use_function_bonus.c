#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    FILE *fin,*fout;
    char Infile[128],Outfile[128];
    char bf[5]={0,}; // int 4바이트 + 1 NULL바이트
    int TempFile;//fread를 출력한 내용의 크기가 들어가기 때문에 정수형 변수로 선언,fread함수만 바로 사용하면 쓰레기 값이 들어가기 때문에 TempFile변수에 넣어줘 쓰레기값이 아닌 파일의 본 내용이 복사본에 저장되도록 해주었다.
    printf("입력 파일 이름 : ");
    scanf("%s",Infile);
    printf("출력 파일 이름 : ");
    scanf("%s",Outfile);
    
    fin=fopen(Infile,"r");
    if(fin==NULL)
    {
        printf("Error: 파일 %s을 열 수 없습니다\n",Infile);
        exit(1);
    }
    
    fout=fopen(Outfile,"w");
    if(fout==NULL)
    {
        printf("Error : 파일 %s을 열 수 없습니다.\n",Outfile);
        exit(1);
    }
    
    TempFile=fread(bf,sizeof(char),128,fin);//fread함수의 매개인자는 버퍼,해당 자료형의 크기만큼 불어오기 위해 sizeof함수 사용, 128은 읽어올 크기이다. 그러므로 넉넉하게 주는 것이 좋다. 마지막 매개인자는 읽어올 파일을 넣어준다. 위에서는 입력파일이 fin으로 선언되어있기 때문에 fin을 넣어주었다.
    fwrite(bf, sizeof(char), TempFile, fout);//출력파일은 입력파일의 내용을 복사해야한다. 위와 같이 처음엔 버퍼를 적어주고, 다음으로 불러온 자료형의 크기를, TempFile은 128의 공간만큼 있지만 실제로 불러온 파일은 그보다 작은 값이 될 수도 있다. 왜냐하면 EOD만큼 크기를 자르기 때문에 공간을 불러온 파일 크기만큼 하기 위해서 TempFile을 넣어주었다.그리고 마지막 인자로 출력파일을 넣어준다.
    
    fclose(fin);//위 과정이 끝났기 때문에 입력 및 출력파일을 닫아준다.
    fclose(fout);
}

