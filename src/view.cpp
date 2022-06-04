#define _CRT_SECURE_NO_WARNINGS
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

void InventoryManagement(std::string store_name) {

	std::cout << "\n\n" << std::endl;

	std::cout << "1. 입고" << std::endl;
	std::cout << "2. 출고" << std::endl;
	std::cout << "3. 종료" << std::endl;
	int choice;
	std::cout << "선택 >> ";
	std::cin >> choice;
	std::cin.ignore();
	InventoryManagement(store_name, choice);/*
	if (choice == 1) {
		std::cout << "\n\nwarehousing" << std::endl; // 입고

		std::string category, title, price, amount;
		char ans;
		std::cout << "title >> ";
		getline(std::cin, title);
		fflush(stdin);
		std::cout << "category >> ";
		std::cin >> category;
		fflush(stdin);
		std::cout << "price >> ";
		std::cin >> price;
		fflush(stdin);
		std::cout << "amount >> ";
		std::cin >> amount;
		fflush(stdin);

		system("cls");
		std::cout << "category : " << category << std::endl;
		std::cout << "title : " << title << std::endl;
		std::cout << "price : " << price << std::endl;
		std::cout << "amount : " << amount << std::endl;
		std::cout << "\n맞습니까?(y/n) >> ";
		std::cin >> ans;
		if (ans == 'y') { // 파일 뒤지기
			char* id = Search("dataExample2.csv", category, title, price);
			if (strcmp(id, "-1") == 0) {
				std::cout << "make new!";
			}
			else {
				std::cout << "modify the amount of its id";
			}
		}
		else
			InventoryManagement();*/

	system("cls");
	FILE* fp=NULL;
	ShowData(fp, store_name, "dataExample2.csv", "rt");
	InventoryManagement(store_name);
}

void InventoryManagement(std::string store_name, int i) {
	if (i == 1) { // 입고
		std::cout << "\n\nwarehousing" << std::endl;

		std::string category, title, price, amount;
		char ans;
		std::cout << "title >> ";
		getline(std::cin, title);
		fflush(stdin);
		std::cout << "category >> ";
		std::cin >> category;
		fflush(stdin);
		std::cout << "price >> ";
		std::cin >> price;
		fflush(stdin);
		std::cout << "amount >> ";
		std::cin >> amount;
		fflush(stdin);

		system("cls");
		std::cout << "category : " << category << std::endl;
		std::cout << "title : " << title << std::endl;
		std::cout << "price : " << price << std::endl;
		std::cout << "amount : " << amount << std::endl;
		std::cout << "\n맞습니까?(y/n) >> ";
		std::cin >> ans;
		if (ans == 'y') { // 파일 뒤지기
			std::string id = Search("dataExample2.csv", category, title, price);
			if (id.at(0) == '-' && id.at(1) == '1' && id.at(2) == ',') { // 기존에 없던 상품(상품번호 존재하지 않음)
//				std::cout << "make new!" << std::endl;
//				for (int i = 3; i < id.size(); i++) {
//					std::cout << id.at(i);
//				}
//				std::cout << std::endl;
				FILE* fp = NULL;
				std::string end_id = "";
				for (int i = 3; i < id.size(); i++) {
					end_id += id.at(i);
				}
				std::stringstream toStr;
				int end = 0;
				for (int i = end_id.size() - 1; i >= 0; i--) {
					end += (end_id.at(i) - 48) * pow(10, end_id.size() - 1 - i);
				}
				end += 1;
				toStr << end;
				end_id = toStr.str();
				std::string phone, location;
				if (0 == fopen_s(&fp, "dataExample2.csv", "rt")) {
					char one_line_string[128], str[32], * pos;
//					std::string phone, location;
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
							//				string store_name;
							if (strcmp(str, store_name.c_str()) == 0) {
								pos = GetNext(pos, ',', str); // str에 상품번호 담김
								pos = GetNext(pos, ',', str); // str에 카테고리 담김
								pos = GetNext(pos, ',', str); // str에 제목 담김
								pos = GetNext(pos, ',', str); // str에 가격 담김
								pos = GetNext(pos, ',', str); // str에 재고 담김
								pos = GetNext(pos, ',', str); // str에 전화번호담김
								phone = str;
								pos = GetNext(pos, ',', str); // str에 위치 담김
								location = str;
							}
						}
					}
					fclose(fp);
					fp = NULL;
				}





				if (0 == fopen_s(&fp, "dataExample2.csv", "r+t")) {
					char one_line_string[128], str[32], * pos;
					//long currLoc=Search()
					std::string endLine;
					fseek(fp, 0L, SEEK_END);
					endLine = store_name;
					endLine += ',';
					endLine += end_id;
					endLine += ',';
					endLine += category;
					endLine += ',';
					endLine += title;
					endLine += ',';
					endLine += price;
					endLine += ',';
					endLine += amount;
					endLine += ',';
					endLine += phone;
					endLine += ',';
					endLine += location;
					endLine += '\n';
					fputs(endLine.c_str(), fp);
					fclose(fp);
				}
			}
			else { // 기존에 있던 상품(상품번호 존재)
//				std::cout << "modify the amount of its id" << std::endl;
//				std::cout << id << std::endl;

				FILE* fp = NULL;
				char* p;
				std::string total_str;
				long find_pos;
				int before = 0, after = 0;
				long currLoc = Search(fp, "dataExample2.csv", id);
				if (0 == fopen_s(&fp, "dataExample2.csv", "r+t")) {
					char one_line_string[128], str[32], * pos;
					fseek(fp, currLoc, SEEK_SET);
					fgets(one_line_string, 128, fp);
					pos = one_line_string;
					for (int i = 0; *pos; i++) {
						pos = GetNext(pos, ',', str);
						if (i == 5) {
							total_str = str;
							total_str += ','; // 기존 재고. ex) 10,
							for (int i = total_str.size() - 2; i >= 0; i--) {
								before += (total_str.at(i)-48) * pow(10, total_str.size() - 2 - i);
							}
//							std::cout << "기존 재고 : " << str << std::endl;
//							std::cout << "수정 재고 : " << amount << std::endl;
						}
					}
					p = strstr(one_line_string, total_str.c_str());
					if (p != NULL) {
						find_pos = strlen(one_line_string) - (p - one_line_string) + 1;
						fseek(fp, (-1) * find_pos, SEEK_CUR);
						amount += ','; // 수정 재고. ex) 20,
						for (int i = amount.size() - 2; i >= 0; i--) {
							after += (amount.at(i) - 48) * pow(10, amount.size() - 2 - i);
						}
						after += before;
						std::stringstream toStr;
						toStr << after;
						amount = toStr.str();
						amount += ',';

						fwrite(amount.c_str(), amount.size(), 1, fp);
						fseek(fp, find_pos - amount.size(), SEEK_CUR);
					}
				}
				fclose(fp);
				fp = NULL;
			}
		}
	}
	else if (i == 2) { // 출고
		std::cout << "미구현" << std::endl;
		exit(1);
	}

	else if (i == 3) { // 종료
		exit(1);
	}
}

void ShowData(FILE* fp, std::string store_name, std::string fileName, std::string mode) {
	if (0 == fopen_s(&fp, fileName.c_str(), mode.c_str())) {
		char one_line_string[128], str[32], * pos;
		const char* title[8] = {
			"%s        ", "%s     ", "%s                ", "%s          ", "%s   ", "%s  ", "%s            ", "%s                      "
		};
		const char* data[8] = {
			"%-15s  ", "  %4s  ", "  %10s  ", "  %25s  ", "  %6s  ", "  %2s  ", "  %12s  ", "  %20s  "
			// 이름        상품번호    카테고리    책제목        가격      재고        전화         위치          
		};
		if (NULL != fgets(one_line_string, 128, fp)) {
			printf("-------------------------------------------------------------------\n");
			pos = one_line_string;
			for (int i = 0; *pos; i++) {
				pos = GetNext(pos, ',', str);
				if (i >= 1 && i <= 5) // 사용자에게는 3, 4, 5, 6, 7번째 항목만 필요
					printf(title[i], str);
				else
					continue;
			}
			printf("\n-------------------------------------------------------------------\n");
		}

		while (NULL != fgets(one_line_string, 128, fp)) {
			pos = one_line_string;
			for (int i = 0; *pos; i++) {
				pos = GetNext(pos, ',', str);
				if (i == 0 && store_name.compare(str) != 0) // 사용자에게는 3, 4, 5, 6, 7번째 항목만 필요
					break;
				else if (i >= 1 && i <= 5)
					printf(data[i], str);
			}
			printf("\n");
		}
		printf("\n-------------------------------------------------------------------\n");
		fclose(fp);
	}
}
