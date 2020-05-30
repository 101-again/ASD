#include <iostream>
#include <string>
using namespace std;
class Heap {
	int* array;//массив который будет нашей кучей в этом задании
	int d;//кол-во сыновей
	int size;//размер кучи
	void swap(int i, int j) {//меняет местами ключи вершин i - j
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
	//при добавлении элемента переделываем кучу
	void shiftUp(int i) {//восстановление инварианта для вершины i,
						 //после уменьшения значения ключа i
		while (i > 0) {
			if (array[i] < array[(int)floor((i - 1) / d)]) {//округление в меньшую сторону потому что индексация начинается с 0 
				swap(i, (int)floor((i - 1) / d));       
			}
			i--;
		}
	}
	//при удалении элемента переделываем кучу
	void shiftDown(int i) {//восстановление инварианта для вершины i после уменьшения значения ключа i
						   
		while (i * d + 1 < size - 1) {//смотрим, есть ли потомки
			//Минимальный сын
			int minOfHeap = array[i * d + 1];//минимальный элемент массива
			int j = i * d + 1;//минимальный элемент
			for (int r = 2; r <= d; r++) {//просматриваем цикл, начиная со второго элемента
				if (array[i * d + r] < minOfHeap) {//если элемент кучи меньше заданного минамального
					minOfHeap = array[i * d + r];//то делаем его минимальным
					j = i * d + r;//
				}
			}
			//ShiftDown
			if (array[i] > array[j] && j < size) {//если элемент заданного массива больше, чем элемент массива
				swap(i, j);//то меняем их местами
			}
			i = j;
		}
	}
	//заполнение кучи
	void setHeap(int* arr) {//строим кучу
		for (int i = 0; i < size; i++) {
			array[i] = arr[i];
			shiftUp(i);
		}
	}
public:
	Heap(int* array, int d, int s) {
		this->d = d;
		size = s;
		this->array = new int[size];
		setHeap(array);
	}
	~Heap() {
	};
	void print(const string& str, int n, bool temp)
	{
		if (n < size)
		{
			cout << str;        
			cout << "|_:" << array[n] << endl;
			for (int i = 1; i < d; i++) {
				if (temp)      
					print(str + "|   ", d * n + i, true);
				else           
					print(str + "    ", d * n + i, true);
			}
			if (temp)      
				print(str + "|   ", d * n + d, false);
			else           
				print(str + "    ", d * n + d, false);
		}
	}
	//вставка нового элемента в кучу
	void insert(int element) {
		array[size] = element;
		shiftUp(size);//функция восстановления инварианта
		size++;
	}
	//удалить элемент с минимальным ключом из кучи
	void delete_min() {
		swap(0, size - 1);
		size--;
		shiftDown(0);
	}
	//возврат минимального элемента
	int getMin() {
		return array[0];
	}

};
int main() {
	int sizeOfHeap;//размер кучи
	int insertElement;//элемент для вставки
	setlocale(LC_ALL, "ru");
	cout << "Input heap size:" << endl;
	cin >> sizeOfHeap;
	cout << "Input heap:" << endl;
	int* array = new int[sizeOfHeap];
	for (int i = 0; i < sizeOfHeap; i++) {
		cin >> array[i];
	}
	//создание объекта-кучи на основе класса(массив вершин, кол-во сыновей макс, размер)
	Heap heap(array, 3, sizeOfHeap);//d-3 куча
	heap.print("", 0, false);

	int status = true;
	
	while (status) {
		int choice;
		cout << "1-Insert element, 2-Delete min element, 3-Exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1: {
			cout << "Input element: ";
			cin >> insertElement;
			heap.insert(insertElement);
			heap.print("", 0, false);
			break;
		}
		case 2: {
			cout << "Min element: " << heap.getMin() << endl;
			heap.delete_min();
			heap.print("", 0, false);
			break;
		}
		case 3: {
			status = false;
			break;
		}
		default: {
			cout << "Error" << endl;
			break;
		}
		}
	}

	system("pause");
	return 0;
}
