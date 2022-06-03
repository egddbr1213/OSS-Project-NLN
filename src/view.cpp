#include "view.h"

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

bool LogIn(std::string& id) {
	bool is_user = false;
	
	char* ans_id = (char*)malloc(sizeof(char) * 50);
	if(ans_id==NULL) {
		std::cout << "malloc error on ans_id" << std::endl;
		exit(1);
	}

	char* ans_pw = (char*)malloc(sizeof(char) * 50);
	if(ans_pw==NULL) {
		std::cout << "malloc error on ans_pw" << std::endl;
		exit(1);
	}

	std::cout << "사용자 아이디 >> ";
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

char* Search(std::string fileName, std::string category, std::string title, std::string price) {
	FILE* fp = NULL;
	if (0 == fopen_s(&fp, fileName.c_str(), "rt")) {
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
				char* id = str;
				pos = GetNext(pos, ',', str);
				if (strcmp(str, category.c_str()) == 0) {
					pos = GetNext(pos, ',', str);
					if (strcmp(str, title.c_str()) == 0) {
						pos = GetNext(pos, ',', str);
						if (strcmp(str, price.c_str()) == 0) {
							return id;
						}				
					}
					else {	
						strcpy(id, "-1");
						return id;
					}
				}
			}
		}
		fclose(fp);
		fp = NULL;
	}
}
