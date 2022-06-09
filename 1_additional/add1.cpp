#include<iostream>
#include<chrono>
int maxi(int n, int* arg, int i)
{
	int a;
	if (i == n - 1)//идём  до последнего элемента в массиве
		return i;
	a = maxi(n, arg, i + 1);//  n-кол-во элементов,arg-массив откуда берем ,i+1 будем вызывать следующий элемент
	if (arg[a] > arg[i])
		return a;
	return i;
}
int main()
{
	int n;
	std::cin >> n;
	srand(time(0));
	int arg[1000];
	for (int i = 0; i < n; i++)
	{
		arg[i] = rand() % 1000 + 1;
		std::cout << arg[i] << " ";
	}
	std::cout << std::endl;
	int max = maxi(n, arg, 0);
	std::cout << arg[max] << " " << std::endl;
}