#include <stdio.h>
#include <Windows.h>

//�̻����� ����ü�� ������ش�.
struct BULLET {
	int x;
	int y;
	bool fire; // true false 1	0
};

BULLET pBullet;
char bg[25][80];

void ClearScreen() {
	//�ܼ� ���� �����
	system("cls");
	for (int y = 0; y < 25; y++) {
		for (int x = 0; x < 80; x++) {
			bg[y][x] = ' ';
		}
	}
}

//�������� ���
void GameMove() {

	if (pBullet.fire == true) {
		bg[pBullet.y][pBullet.x] = '>';
		pBullet.x++;
	}
	if (pBullet.x == 79) {
		pBullet.fire = false;
	}
}

//�׷��ִ� �Լ�
void PrintScreen() {
	bg[24][79] = '\0';//�迭���� �ι��ڸ� �־��༭ ���ڿ��� �����.
	printf("%s", bg);
}

void main() {
	pBullet.x = 0;
	pBullet.y = 0;
	pBullet.fire = true;//�̻��� �߻���

	int dwTime = GetTickCount64(); //���� �ʴ��� �ð� �Լ� 1/1000��


	while (true) {//���� ���ѷ���
		//����
		if (dwTime + 15 < GetTickCount64()) {
			dwTime = GetTickCount64();
			//�����ش�
			ClearScreen();
			//������ó��
			GameMove();
			//�׷��ش�
			PrintScreen();
		}
	}
}