// beehive_bfs_2292.cpp : Defines the entry point for the console application.
// https://www.acmicpc.net/problem/2292
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> MIN; //줄 내에 가장 작은 값 저장
vector<int> MAX; //줄 내에 가장 큰 값 저장
//두 배열의 인덱스 넘버가 최단 거리를 결정

int main()
{
	cin >> n;

	//줄 내에 가장 
	MIN.push_back(1);
	MAX.push_back(1);

	int min = 2, max, num=6;
	int i=1;
	while (min <= n ) {

		MIN.push_back(min);
		max = min + (i*num - 1);
		MAX.push_back(max);

		min += (i*num);
		i++;

	}

	cout << MIN.size() << " " << MAX.size() << endl;

	for (int i = 0; i < MIN.size(); i++) {
		cout << MIN[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < MAX.size(); i++) {
		cout << MAX[i] << " ";
	}


	

    return 0;
}

