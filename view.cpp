#include "view.h"
/*
void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void mainpage(int input = 0) {
	std::cout << "\n\n\n\n\t\t\t\t\t\t사용자 모드" << std::endl;
	std::cout << "\n\t\t\t\t원하시는 작업을 선택해 주세요.(방향키로 선택)\n\n" << std::endl;
	if (input % 2 == 0) {
		textcolor(BLACK, WHITE);
		std::cout << "\t\t\t\t\t\t상품 구매" << std::endl;
		textcolor(WHITE, BLACK);
		std::cout << "\n\n\t\t\t\t\t\t뒤로 가기" << std::endl;
		textcolor(WHITE, BLACK);
	}
	else {
		textcolor(WHITE, BLACK);
		std::cout << "\t\t\t\t\t\t상품 구매" << std::endl;
		textcolor(BLACK, WHITE);
		std::cout << "\n\n\t\t\t\t\t\t뒤로 가기" << std::endl;
		textcolor(WHITE, BLACK);
	}
	int ch1, ch2;
	ch1 = _getch();

	if (ch1 == 224) {
		ch2 = _getch();
		if (ch2 == 72 || ch2 == 80) {
			system("cls");
			mainpage(input + 1);
		}
	}

	else if (ch1 == 13) {
		if (input % 2 == 0) {
			//상품 구매
			system("cls");
			std::cout << "\n\n\nCongratulation!!!" << std::endl;
		}
		else {
			system("cls");
			std::cout << "\n\n\nExit." << std::endl;
			Sleep(500);
			system("cls");
			std::cout << "\n\n\nExit. ." << std::endl;
			Sleep(500);
			system("cls");
			std::cout << "\n\n\nExit. . ." << std::endl;
			Sleep(500);
		}
	}
}*/

char* GetNext(char* str, char del, char*buffer)
{
	while(*str&&*str!=del)*buffer++=*str++;
	if(*(buffer-1)=='\n')*(buffer-1)=0;
	else *buffer=0;
	if(*str==del)str++;

	return str;
}

std::string SearchLocation(std::string location)
{
	// 현위치 주변에 있는지 없는지 검색하는 함수의 내용을 추가해주세요
	return location;
}

bool LogIn() {
		std::cout << "사용자 아이디 >> ";
	bool is_user = false;
	char* ans_id = (char*)malloc(sizeof(char) * 10);
	char* ans_pw = (char*)malloc(sizeof(char) * 10);
	std::cin >> ans_id;
	fflush(stdin);
	FILE* fp = NULL;
	if (0 == fopen_s(&fp, "SellerProfile.csv", "rt")) {
		char one_line_string[128], str[32], * pos;

		if (NULL != fgets(one_line_string, 128, fp)) {
			pos = one_line_string;
			for (int i = 0; *pos; i++) {
				pos = GetNext(pos, ',', str);
			}
		}

		while (NULL != fgets(one_line_string, 128, fp)) {
			pos = one_line_string;
			for (int i = 0; *pos; i++) {
				pos = GetNext(pos, ',', str);
				if (strcmp(str, ans_id) == 0) {
					std::cout << "사용자 비밀번호 >> ";
					std::cin >> ans_pw;
					pos = GetNext(pos, ',', str);
					if (strcmp(str, ans_pw) == 0) {
						is_user = true;
						break;
					}
					else {
						std::cout << "없는 사용자이거나 비밀번호 입력 오류" << std::endl;
					}
				}
			}
		}
		fclose(fp);
		fp = NULL;
		free(ans_id);
		free(ans_pw);
	}


	return is_user;
}
