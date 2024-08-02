#include <stdio.h>
#include <iostream>
#include <chrono>

int main() {

	std::string a(1000000, 'a');

	std::chrono::system_clock::time_point start, end;
	std::time_t time_stamp;

	//�v���J�n
	start =  std::chrono::system_clock::now();

	//�v������������
	//�R�s�[
	std::string b = a;

	//�v���I��
	end = std::chrono::system_clock::now();


	// �����ɗv��������
	auto time1 = end - start;

	// �����ɗv�������Ԃ��~���b�ɕϊ�
	printf("�R�s�[�ɂ�肩���鎞��\n");
	auto msec1 = std::chrono::duration_cast<std::chrono::microseconds>(time1).count();
	std::cout << msec1 << " msec" << std::endl;



	//�v���J�n
	start = std::chrono::system_clock::now();

	//�v������������
	//�ړ�
	std::string m = move(a);

	//�v���I��
	end = std::chrono::system_clock::now();


	// �����ɗv��������
	auto time2 = end - start;

	// �����ɗv�������Ԃ��~���b�ɕϊ�
	printf("�ړ��ɂ�肩���鎞��\n");
	auto msec2 = std::chrono::duration_cast<std::chrono::microseconds>(time2).count();
	std::cout << msec2 << " msec" << std::endl;


	return 0;
}