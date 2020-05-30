// Обменная поразрядная сортировка
#include <iostream>
#include <ctime>

using namespace std;

int swaps = 0, compares = 0;

void sort(int* array, int low, int high,unsigned bit) {

	if (bit == 0 || low >= high) {
		compares++;
		return;
	}

	int i, j, temp;
	for (i = low, j = high; i <= j;) {
		if ((array[i] & bit) == 0) {
			i++;
			compares++;
			continue;
		}
		if ((array[j] & bit) != 0) {
			j--;
			compares++;
			continue;
		}
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		i++;
		j--;
		swaps++;
	}
	sort(array, low, j, bit >> 1);
	sort(array, i, high, bit >> 1);
}

void mainsort( int* B, int n ){
	int max, i;
	unsigned m;
	for (max = 0, i = 0; i < n; i++) {
		if (B[i] > max) {
			max = B[i];
		}
	}
	for (m = 1; m < max; m <<= 1);
	m >>= 1;
	sort(B, 0, n - 1, m);
}


int main() {
	setlocale(0, "");
	int size;
	cout << "Введите размерность массива: ";
	cin >> size;

	int* array = new int[size];
	for (int i = 0; i < size; i++) {
		array[i] = i;
	}

	

	clock_t time, start, finish;
	start = clock();
	mainsort(array, size);
	finish = clock();
	time = finish - start;
	cout << "По возрастанию" << endl;
	cout << "Time:" << time << endl;
	cout << "Swaps:" << swaps << endl;
	cout << "Compares:" << compares << endl;

	swaps = 0, compares = 0;

	int* array1 = new int[size];
	int k = size;
	for (int i = 0; i < size; i++) {
		array1[i] = k;
		k--;
	}

	start = clock();
	mainsort(array1, size);
	finish = clock();
	time = finish - start;
	cout << "По убыванию" << endl;
	cout << "Time:" << time << endl;
	cout << "Swaps:" << swaps << endl;
	cout << "Compares:" << compares << endl;

	swaps = 0, compares = 0;

	int* array2 = new int[size];
	for (int i = 0; i < size; i++) {
		array2[i] = rand();
	}

	cout << "Исходный" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << array2[i] << " ";
	}
	cout << endl;

	start = clock();
	mainsort(array2, size);
	finish = clock();
	time = finish - start;
	cout << "Случайный порядок" << endl;
	cout << "Time:" << time << endl;
	cout << "Swaps:" << swaps << endl;
	cout << "Compares:" << compares << endl;

	cout << "Отсортированный" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << array2[i] << " ";
	}

	system("pause");
	return 0;
}

