#include <stdio.h>
#include <Windows.h>

//미사일의 구조체를 만들어준다.
struct BULLET {
	int x;
	int y;
	bool fire; // true false 1	0
};

BULLET pBullet;
char bg[25][80];

void ClearScreen() {
	//콘솔 내용 지우기
	system("cls");
	for (int y = 0; y < 25; y++) {
		for (int x = 0; x < 80; x++) {
			bg[y][x] = ' ';
		}
	}
}

//움직임을 담당
void GameMove() {

	if (pBullet.fire == true) {
		bg[pBullet.y][pBullet.x] = '>';
		pBullet.x++;
	}
	if (pBullet.x == 79) {
		pBullet.fire = false;
	}
}

//그려주는 함수
void PrintScreen() {
	bg[24][79] = '\0';//배열끝에 널문자를 넣어줘서 문자열로 만든다.
	printf("%s", bg);
}

void main() {
	pBullet.x = 0;
	pBullet.y = 0;
	pBullet.fire = true;//미사일 발사중

	int dwTime = GetTickCount64(); //현재 초단위 시간 함수 1/1000초


	while (true) {//게임 무한루프
		//지연
		if (dwTime + 15 < GetTickCount64()) {
			dwTime = GetTickCount64();
			//지워준다
			ClearScreen();
			//움직임처리
			GameMove();
			//그려준다
			PrintScreen();
		}
	}
}