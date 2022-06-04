#include "customer.h"

char* GetNext(char* str, char del, char* buffer) {
	while (*str && *str != del)*buffer++ = *str++;
	if (*(buffer - 1) == '\n')*(buffer - 1) = 0;
	else *buffer = 0;

	if (*str == del)str++;

	return str;
}

long Search(FILE* fp, std::string fileName, std::string id) {
	if (0 == fopen_s(&fp, fileName.c_str(), "rt")) {
		std::cout << "파일이 열렸습니다!!!" << std::endl;
		char one_line_string[128], str[32], * pos;

		if (NULL != fgets(one_line_string, 128, fp)) {
			pos = one_line_string;
			for (int i = 0; *pos; i++) {
				pos = GetNext(pos, ',', str);
			}
		}
		long currLoc = ftell(fp);

		while (NULL != fgets(one_line_string, 128, fp)) {

			pos = one_line_string;
			for (int i = 0; *pos; i++) {
				pos = GetNext(pos, ',', str);
				if (i == 1 && strcmp(str, id.c_str()) == 0) {
					fclose(fp);
					std::cout << "파일이 닫혔습니다!!!" << std::endl;
					return currLoc;
				}
			}
			currLoc = ftell(fp);
		}
		fclose(fp);
		std::cout << "파일이 닫혔습니다!!!" << std::endl;
	}
}

void ShowData(FILE* fp, std::string location) {
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
			if (1) // 사용자에게는 3, 4, 5, 6, 7번째 항목만 필요
				printf(title[i], str);
			else
				continue;
		}
		printf("\n-------------------------------------------------------------------\n");
	}
	while (NULL != fgets(one_line_string, 128, fp)) {
		pos = one_line_string;
		if (NULL == strstr(one_line_string, location.c_str())) {
			continue;
		}
		for (int i = 0; *pos; i++) {
			
			pos = GetNext(pos, ',', str);
			if (1)
				printf(data[i], str);
		}
		printf("\n");
	}
	printf("\n-------------------------------------------------------------------\n");
}

void ShowData(FILE* fp, std::string location, std::string another) {
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
			if (1) // 사용자에게는 3, 4, 5, 6, 7번째 항목만 필요
				printf(title[i], str);
			else
				continue;
		}
		printf("\n-------------------------------------------------------------------\n");
	}
	while (NULL != fgets(one_line_string, 128, fp)) {
		pos = one_line_string;
		if (NULL == strstr(one_line_string, location.c_str())) {
			continue;
		}
		if (NULL == strstr(one_line_string, another.c_str())) {
			continue;
		}
		for (int i = 0; *pos; i++) {

			pos = GetNext(pos, ',', str);
			if (1)
				printf(data[i], str);
		}
		printf("\n");
	}
	printf("\n-------------------------------------------------------------------\n");
}

int EditData(FILE* fp, std::string find_id, std::string find_num) {
	char one_line_string[128], str[32], * pos;
	if (0 == fopen_s(&fp, "dataExample2.csv", "rt")) {
		std::cout << "파일이 열렸습니다!!!" << std::endl;
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
				if (i == 1 && strcmp(str, find_id.c_str())) {
					pos = GetNext(pos, ',', str);
					pos = GetNext(pos, ',', str);
					pos = GetNext(pos, ',', str);
					pos = GetNext(pos, ',', str);
					int str_int = 0, num_int = 0;
					for (int i = strlen(str) - 1; i >= 0; i--) {
						str_int += str[i] * pow(10, strlen(str) - 1 - i);
					}
					for (int i = find_num.size() - 1; i >= 0; i--) {
						num_int += find_num[i] * pow(10, find_num.size() - 1 - i);
					}
					if (str_int >= num_int) {
						std::cout << "구매가능!!!" << std::endl;

						fclose(fp);
						std::cout << "파일이 닫혔습니다!!!" << std::endl;
						return 1;
					}
					else {
						std::cout << "재고부족!!!" << std::endl;

						fclose(fp);
						std::cout << "파일이 닫혔습니다!!!" << std::endl;
						return 0;
					}
				}
			}
		}

		fclose(fp);
		std::cout << "파일이 닫혔습니다!!!" << std::endl;
	}
	return -1;
}
