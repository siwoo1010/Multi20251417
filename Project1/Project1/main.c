#include<stdio.h>
#include<Windows.h>

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
	

	gotoxy(x,y);
while(1)
	{
		printf("\x1B[%d;%dH", y, x);
		printf("#");
	
	}
	return 0;
}
//
#include <stdio.h>

int main() {
    int x, y;                      // 화면 좌표용 변수 선언

    int width = 6;                 // 가로 크기 (열)
    int height = 5;                // 세로 크기 (행)

    // 1. 맨 윗줄 출력 (y=1)
    // x 좌표 1부터 width(6)까지 '#' 출력
    for (x = 1; x <= width; x++) {
        // ANSI escape 코드로 커서를 y=1, x=현재 위치로 이동
        printf("\x1B[%d;%dH", 1, x);

        if (x == 1)
            // '#' 문자 출력, printf("#") 딱 한 번만 사용
            printf("#");
        else
            // 나머지는 putchar로 출력 (한 글자 출력 함수)
            putchar('#');
    }

    // 2. 중간 줄 출력 (y=2부터 height-1까지)
    // 각 줄의 좌우 끝은 '#', 나머지는 공백으로 출력
    for (y = 2; y <= height - 1; y++) {
        // 왼쪽 끝('#') 출력 위치로 커서 이동
        printf("\x1B[%d;%dH", y, 1);
        putchar('#');              // 왼쪽 테두리 출력

        // 줄의 중간 부분 공백 출력 (x=2부터 width-1까지)
        for (x = 2; x < width; x++) {
            printf("\x1B[%d;%dH", y, x); // 커서 이동
            putchar(' ');                 // 공백 출력
        }

        // 오른쪽 끝('#') 출력 위치로 커서 이동
        printf("\x1B[%d;%dH", y, width);
        putchar('#');              // 오른쪽 테두리 출력
    }

    // 3. 맨 아랫줄 출력 (y=height)
    // x 좌표 1부터 width까지 모두 '#'
    for (x = 1; x <= width; x++) {
        printf("\x1B[%d;%dH", height, x); // 커서 이동
        putchar('#');                      // '#' 출력
    }

    // 4. 출력 끝난 후 커서를 다음 줄 첫 칸으로 이동 (y=height+1, x=1)
    printf("\x1B[%d;%dH", height + 1, 1);

    return 0;
}
