#include <iostream>
#include <string>
using namespace std;
class Heap {
	int* array;//������ ������� ����� ����� ����� � ���� �������
	int d;//���-�� �������
	int size;//������ ����
	void swap(int i, int j) {//������ ������� ����� ������ i - j
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
	//��� ���������� �������� ������������ ����
	void shiftUp(int i) {//�������������� ���������� ��� ������� i,
						 //����� ���������� �������� ����� i
		while (i > 0) {
			if (array[i] < array[(int)floor((i - 1) / d)]) {//���������� � ������� ������� ������ ��� ���������� ���������� � 0 
				swap(i, (int)floor((i - 1) / d));       
			}
			i--;
		}
	}
	//��� �������� �������� ������������ ����
	void shiftDown(int i) {//�������������� ���������� ��� ������� i ����� ���������� �������� ����� i
						   
		while (i * d + 1 < size - 1) {//�������, ���� �� �������
			//����������� ���
			int minOfHeap = array[i * d + 1];//����������� ������� �������
			int j = i * d + 1;//����������� �������
			for (int r = 2; r <= d; r++) {//������������� ����, ������� �� ������� ��������
				if (array[i * d + r] < minOfHeap) {//���� ������� ���� ������ ��������� ������������
					minOfHeap = array[i * d + r];//�� ������ ��� �����������
					j = i * d + r;//
				}
			}
			//ShiftDown
			if (array[i] > array[j] && j < size) {//���� ������� ��������� ������� ������, ��� ������� �������
				swap(i, j);//�� ������ �� �������
			}
			i = j;
		}
	}
	//���������� ����
	void setHeap(int* arr) {//������ ����
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
	//������� ������ �������� � ����
	void insert(int element) {
		array[size] = element;
		shiftUp(size);//������� �������������� ����������
		size++;
	}
	//������� ������� � ����������� ������ �� ����
	void delete_min() {
		swap(0, size - 1);
		size--;
		shiftDown(0);
	}
	//������� ������������ ��������
	int getMin() {
		return array[0];
	}

};
int main() {
	int sizeOfHeap;//������ ����
	int insertElement;//������� ��� �������
	setlocale(LC_ALL, "ru");
	cout << "Input heap size:" << endl;
	cin >> sizeOfHeap;
	cout << "Input heap:" << endl;
	int* array = new int[sizeOfHeap];
	for (int i = 0; i < sizeOfHeap; i++) {
		cin >> array[i];
	}
	//�������� �������-���� �� ������ ������(������ ������, ���-�� ������� ����, ������)
	Heap heap(array, 3, sizeOfHeap);//d-3 ����
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
