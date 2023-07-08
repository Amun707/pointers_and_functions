#include<iostream>
//Указатели и функции
#include<cstdlib>
#include<ctime>

//Заполнение массива случайными числами
template<typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}
//Вывод массива в консоль
template<typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }" << std::endl;
}


//не рабочий вариант ф-ии std::swap
void my_swap(int var1, int var2) {
	int tmp = var1;
	var1 = var2;
	var2 = tmp;
}

//Рабочий вариант ф-ии std::swap, принимающий адреса переменных
void p_swap(int* var1, int* var2) {
	int tmp = *var1;
	*var1 = *var2;
	*var2 = tmp;
}


void sum_arr_to_pointer(int *arr, const int length, int* pointer);


void compare(int* var1, int* var2);

int main() {
	system("chcp 1251>nul");
	int n, m;

	//Указатели, как параметры функции
	n = 10, m = 15;
	std::cout << "n = " << n << "; m = " << m << std::endl;//n = 10; m = 15;
	//my_swap(n, m);//не работает, т.к. параметры это копии аргументов
	p_swap(&n, &m);//работает т.к, меняем значения конкретных переменных, а не их копий
	std::cout << "n = " << n << "; m = " << m << std::endl;//n = 15; m = 10;


	//Задача 1.Запись в переменную через указатель
	std::cout << "Задача 1.\nМассив: ";
	const int size = 10;
	int arr[size];
	fill_arr(arr, size, 1, 11);
	print_arr(arr, size);

	int result;//переменная для суммы элементов массива
	sum_arr_to_pointer(arr, size, &result);
	std::cout << "Сумма эл-ов массива: " << result << "\n\n";

	//Задача 2. Функция сравнения
	std::cout << "Задача 2.\nВведите два числа -> ";
	std::cin >> n >> m;
	compare(&n, &m);
	std::cout << "n = " << n << "; m = " << m << std::endl;



	return 0;
}


void compare(int* var1, int* var2) {
	if (*var1 > *var2) {
		*var1 *= *var1;
		*var2 *= *var2;
		return;
	}
	*var1 = 0;
	*var2 = 0;
}




void sum_arr_to_pointer(int* arr, const int length, int* pointer) {
	int sum = 0;
	for (int i = 0; i < length; i++)
		sum += arr[i];
	*pointer = sum;
}