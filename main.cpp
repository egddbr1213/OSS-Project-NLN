#include "view.h"
using namespace std;
int main() {
//	mainpage(0);
	cout << "판매자 모드" << endl;
	cout << "관리를 시작하시겠습니까?(y/n) >> ";
	char ans;
	cin >> ans;
	if(ans=='y') {
		system("clear");
		FILE* fp=NULL;

		if(0==fopen_s(&fp, "dataExample.csv", "rt")) {
			char one_line_string[128], str[32], *pos;
			const char* title[8] = {
				" %s ", "%s              ", "%s           ", "%s    ", "%s  ", "%s            ", "%s                      ", "%s  "
		};
			const char* data[8] = {
				"  %4s  ", "  %10s  ", "  %25s  ", "  %6s  ", "  %2s  ", "  %12s  ", "  %20s  ", "  %20s  "
		};

			if(NULL!=fgets(one_line_string, 128, fp)) {
				printf("-------------------------------------------------------------------\n");
				pos=one_line_string;
				for(int i=0;*pos;i++) {
					pos=GetNext(pos, ',', str);
					printf(title[i], str);
				}
				printf("\n-------------------------------------------------------------------\n");
			}
			while(NULL!=fgets(one_line_string, 128, fp)) {
				pos=one_line_string;
				for(int i=0;*posli++) {
					printf(data[i], str);
				}
				printf("\n");
			}
			printf("\n-------------------------------------------------------------------\n");
			fclose(fp);
		}
		else {
			cout << "File not found!!!!!" << endl;
		}
		cout << "\n\n현위치를 설정하시겠습니까?(y/n) >> ";
		cin >> ans;
		if(ans=='y') {
			string cur_location_city;
			string cur_location_gu;
			cout << "현위치를 입력해주세요(ex. 청주시 서원구) >> ";
			cin >> cur_location_city;
			cin >> cur_location_gu;
			string cur_location;
			cur_location=cur_location_city+cur_location_gu;
		}
	}
	else if(ans=='n')
		cout << "bye bye...";

	return 0;
}
