//������

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void type_of(int num);
void type_of(double num);
void type_of(char num);

int sum_AB(int A, int B) {
	if (B == A + 1) 
		return A + B;
		return sum_AB(A, B - 1) + B;
}

template <typename T>                                                      // ��� ����� ������ ������� ��� �������
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;   //��������� ������ arr ���������� ������� �� ��������� begin �� end ( ������� ������ 3 �� 19)
}

// ����� ������� arr � �������
template <typename T>                                         // ��� ����� ������ ������� ��� �������- ��������� ������
void show_arr(T arr[], const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
		std::cout << "\b\b]\n";
}


template <typename T>
void middle_sort(T arr[], const int length) {
	int first_index = 0, last_index = 0;
	//������ ������������� �������
	for (int i = 0; i < length; i++)
		if (arr[i] < 0) {
			first_index = i;
			break;
		}

	//������ ���������� �������������� ��������
	for (int i = length - 1; i > 0; i--)
		if (arr[i] < 0) {
			last_index = i;
			break;
		}
	//����������� ����������
	for (int i = last_index - 1; i > 0; i--)
		for (int j = first_index + 1; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);

	//������� ����������
	sort(arr + first_index + 1, arr + last_index - 1);

}

template <typename T> 
void move_arr(T arr[], const int length, int num) {
	if (num >= 0)	//������ �����
		for (int j = 0; j < num; j++)
			for (int i = length - 2; i >= 0; i--)
				std::swap(arr[i], arr[i + 1]);
	else			//������ �����
		for (int j = num; j < 0; j++)
		for (int i = 0; i < length - 1; i++)
			std::swap(arr[i], arr[i + 1]);

}




int main() {
		setlocale(LC_ALL, "Russian");
		int n, m;
		//������ 1
		std::cout << "������ 1.\n";
		std::cout << "12 - "; type_of(12);
		std::cout << "9.11 - "; type_of(9.11);
		std::cout << 'T - '; type_of('T');


		//������ 2. �������� ����� �� � �� �
		std::cout << "������ 2. ������� 2 �����: \n";
		std::cin >> n >> m;
		std::cout << "����� ����� �� " << n << " �� " << m << " ����� " << sum_AB(n, m) << ".\n\n";


		//������ 3. ����������
		std::cout << "������ 3.\n����������� ������: \n";
		const int size3 = 20;
		int arr3[size3];
		fill_arr(arr3, size3, -20, 21);
		show_arr(arr3, size3);
		middle_sort(arr3, size3);
		std::cout << "�������� ������: \n";
		show_arr(arr3, size3);
		std::cout << '\n';

		//������ 4. ����� �������
		std::cout << "������ 4.\n����������� ������: \n";
		const int size4 = 5;
		int arr4[size4]{ 1, 2, 3, 4, 5 };
		show_arr(arr4, size4);
		std::cout << "������� ���������� �������: ";
		std::cin >> n;
		move_arr(arr4, size4, n);
		std::cout << "�������� ������: \n";
		show_arr(arr4, size4);












	return 0;
}
void type_of(int num) {
	std::cout << "Int\n";
}
void type_of(double num) {
	std::cout << "Double\n";
}
void type_of(char num) {
	std::cout << "Char\n";
}



