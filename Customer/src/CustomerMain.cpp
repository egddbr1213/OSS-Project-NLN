// main.cpp of customer's program#include "customer.h"
using namespace std;
int main() {
	cout << "[사용자용]\n" << endl;
	string cur_location_city;
	string cur_location_gu;
	cout << "현위치를 입력해주세요(ex. 청주시 서원구) >> ";
	cin >> cur_location_city;
	cin >> cur_location_gu;
	string cur_location;
	cur_location = cur_location_city + ' ' + cur_location_gu;
	FILE* fp;
	if (0 == fopen_s(&fp, "../../documents/dataExample2.csv", "rt")) {
		cout << "파일이 열렸습니다!!!" << endl;
		ShowData(fp, cur_location);

		fclose(fp);
		cout << "파일이 닫혔습니다!!!" << endl;
	}

	cout << "1. 책 제목" << endl;
	cout << "2. 카테고리" << endl;
	int ans;
	cin >> ans;
	cin.ignore();
	if (ans == 1) {
		cout << "\n\n책 제목을 입력해주세요 >> ";
		string title;
		getline(cin, title);
		if (0 == fopen_s(&fp, "../../documents/dataExample2.csv", "rt")) {
			cout << "파일이 열렸습니다!!!" << endl;
			ShowData(fp, cur_location, title);
			fclose(fp);
			cout << "파일이 닫혔습니다!!!" << endl;
		}
//		cin.ignore();

		cout << "원하는 번호 입력 >> ";
		int id;
		cin >> id;
		cin.ignore();
		stringstream toStr1, toStr2;
		toStr1 << id;
		string find_id = toStr1.str();
		cout << "원하는 권수 입력 >> ";
		int num;
		cin >> num;
		cin.ignore();
		toStr2 << num;
		string find_num = toStr2.str();
		int rst = EditData(fp, find_id, find_num);
		if (rst == 1) { // 재고 충분
			char* p;
			std::string total_str;
			long find_pos;
			int before = 0, after = 0;
			long currLoc = Search(fp, "../../documents/dataExample2.csv", find_id);
			if (0 == fopen_s(&fp, "../../documents/dataExample2.csv", "r+t")) {
				cout << "파일이 열렸습니다!!!" << endl;
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
							before += (total_str.at(i) - 48) * pow(10, total_str.size() - 2 - i);
						}
						//							std::cout << "기존 재고 : " << str << std::endl;
						//							std::cout << "수정 재고 : " << amount << std::endl;
					}
				}
				p = strstr(one_line_string, total_str.c_str());
				if (p != NULL) {
					find_pos = strlen(one_line_string) - (p - one_line_string) + 1;
					fseek(fp, (-1) * find_pos, SEEK_CUR);
					//					amount += ','; // 수정 재고. ex) 20,
					find_num += ',';
					for (int i = find_num.size() - 2; i >= 0; i--) {
						after += (find_num.at(i) - 48) * pow(10, find_num.size() - 2 - i);
					}
					before -= after;
					std::stringstream toStr;
					toStr << before;
					find_num = toStr.str();
					find_num += ',';

					fwrite(find_num.c_str(), find_num.size(), 1, fp);
					fseek(fp, find_pos - find_num.size(), SEEK_CUR);
				}

				fclose(fp);
				cout << "파일이 닫혔습니다!!!" << endl;
			}
			else
				cout << "파일을 못 열고 있는 것으로 보여질 수 있을 것 같다고 생각할 수 있을 것 같다고 생각합니다" << endl;
			fp = NULL;
		}
		else if (rst == 2) { // 재고 부족
			return 0;
		}
		else {
			return 0;
		}

	}
	else if (ans == 2) {
		cout << "\n\n카테고리를 입력해주세요 >> ";
		string category;
		getline(cin, category);
		if (0 == fopen_s(&fp, "../../documents/dataExample2.csv", "rt")) {
			cout << "파일이 열렸습니다!!!" << endl;
			ShowData(fp, cur_location, category);

			fclose(fp);
			cout << "파일이 닫혔습니다!!!" << endl;
		}

		cout << "원하는 번호 입력 >> ";
		int id;
		cin >> id;
		cin.ignore();
		stringstream toStr;
		toStr << id;
		string find_id = toStr.str();
		cout << "원하는 권수 입력 >> ";
		int num;
		cin >> num;
		cin.ignore();
		toStr << num;
		string find_num = toStr.str();
		EditData(fp, find_id, find_num);

	}
	else {
		return 0;
	}
	return 0;
}
