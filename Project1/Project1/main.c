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
    int x, y;                      // ȭ�� ��ǥ�� ���� ����

    int width = 6;                 // ���� ũ�� (��)
    int height = 5;                // ���� ũ�� (��)

    // 1. �� ���� ��� (y=1)
    // x ��ǥ 1���� width(6)���� '#' ���
    for (x = 1; x <= width; x++) {
        // ANSI escape �ڵ�� Ŀ���� y=1, x=���� ��ġ�� �̵�
        printf("\x1B[%d;%dH", 1, x);

        if (x == 1)
            // '#' ���� ���, printf("#") �� �� ���� ���
            printf("#");
        else
            // �������� putchar�� ��� (�� ���� ��� �Լ�)
            putchar('#');
    }

    // 2. �߰� �� ��� (y=2���� height-1����)
    // �� ���� �¿� ���� '#', �������� �������� ���
    for (y = 2; y <= height - 1; y++) {
        // ���� ��('#') ��� ��ġ�� Ŀ�� �̵�
        printf("\x1B[%d;%dH", y, 1);
        putchar('#');              // ���� �׵θ� ���

        // ���� �߰� �κ� ���� ��� (x=2���� width-1����)
        for (x = 2; x < width; x++) {
            printf("\x1B[%d;%dH", y, x); // Ŀ�� �̵�
            putchar(' ');                 // ���� ���
        }

        // ������ ��('#') ��� ��ġ�� Ŀ�� �̵�
        printf("\x1B[%d;%dH", y, width);
        putchar('#');              // ������ �׵θ� ���
    }

    // 3. �� �Ʒ��� ��� (y=height)
    // x ��ǥ 1���� width���� ��� '#'
    for (x = 1; x <= width; x++) {
        printf("\x1B[%d;%dH", height, x); // Ŀ�� �̵�
        putchar('#');                      // '#' ���
    }

    // 4. ��� ���� �� Ŀ���� ���� �� ù ĭ���� �̵� (y=height+1, x=1)
    printf("\x1B[%d;%dH", height + 1, 1);

    return 0;
}
