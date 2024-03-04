#include"save.h"

int main() {

	cout << "2024 STL" << endl;

	save("save.cpp");
}

void save(string_view fileName) {
	//읽을 파일을 연다.
	ifstream in{ fileName.data() }; //<-- 자유형 데이터 타입
	if (!in) {
		cout << "파일을 열지 못했습니다. " << endl;
		exit(0);
	}
	//쓸 파일을 덧붙이기 모드로 연다.
	ofstream out("2024 1 월56목78 강의 저장.txt", ios::app);

	//읽을 파일의 모든 내용을 읽어 쓸 파일에 덧붙인다. 
	vector<char> v{ istreambuf_iterator<char>{in}, {} };
	copy(v.begin(), v.end(), ostreambuf_iterator<char>{out});

	for (char c : v)
		cout << c;

	//저장하는 시간을 파일에 기록한다.
	auto now = chrono::system_clock::now();
	cout << now << endl;

	auto time = chrono::system_clock::to_time_t(now); //utc 시간으로 변환
	auto lt = localtime(&time); //현지 시간으로 변환

	auto old = out.imbue(locale("ko_KR"));
	out << "=============================" << endl;
	out << fileName << put_time(lt, ", 저장시간:  %x %A %X ") << endl;
	out << "=============================" << endl;
	out.imbue(old);

}