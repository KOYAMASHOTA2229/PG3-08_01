#include <stdio.h>
#include <iostream>
#include <chrono>

int main() {

	std::string a(1000000, 'a');

	std::chrono::system_clock::time_point start, end;
	std::time_t time_stamp;

	//計測開始
	start =  std::chrono::system_clock::now();

	//計測したい処理
	//コピー
	std::string b = a;

	//計測終了
	end = std::chrono::system_clock::now();


	// 処理に要した時間
	auto time1 = end - start;

	// 処理に要した時間をミリ秒に変換
	printf("コピーによりかかる時間\n");
	auto msec1 = std::chrono::duration_cast<std::chrono::microseconds>(time1).count();
	std::cout << msec1 << " msec" << std::endl;



	//計測開始
	start = std::chrono::system_clock::now();

	//計測したい処理
	//移動
	std::string m = move(a);

	//計測終了
	end = std::chrono::system_clock::now();


	// 処理に要した時間
	auto time2 = end - start;

	// 処理に要した時間をミリ秒に変換
	printf("移動によりかかる時間\n");
	auto msec2 = std::chrono::duration_cast<std::chrono::microseconds>(time2).count();
	std::cout << msec2 << " msec" << std::endl;


	return 0;
}