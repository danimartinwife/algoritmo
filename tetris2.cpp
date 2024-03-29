#include <iostream>
using namespace std;
int c, r;
int map[22][22];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> c >> r;

	//맵 입력
	for (int i = 0; i <= r; i++) {
		for (int j = 0; j < c; j++) {
			if (i == r)
				map[i][j] = 1;
			else
				cin >> map[i][j];
		}
	}

	int maxcnt = -1, maxix = -1;
	for (int x = 0; x < c; x++) {
		int start_ix = 0;
		for (int i = 0; i <= r; i++) {
			//위에서부터 빈칸 아닌 부분 찾기
			if (map[i][x] == 1) {
				start_ix = i - 1;
				break;
			}
		}

		//4개짜리 직사각형 벗어나면 건너뛰기
		if (start_ix < 3)
			continue;

		int cnt = 0; //k번째 줄이 완전히 메워지는 개수
		for (int i = start_ix - 3; i <= start_ix; i++) {
			int cntt = 1; //i줄의 1의 갯수, 이미 맨 밑줄은 1로 채워서
			for (int j = 0; j < c; j++) {
				if (map[i][j] == 1)
					cntt++;
			}
			if (cntt == c) //한줄 채워지면
				cnt++;
		}

		if (cnt != 0 && cnt > maxcnt) {
			maxcnt = cnt; //가장 높은것 최대값 응용
			maxix = x + 1;
		}
		
	}

	if (maxix == -1)
		cout << 0 << " " << 0 << endl;
	else
		cout << maxix << " " << maxcnt << endl;

    return 0;
}
