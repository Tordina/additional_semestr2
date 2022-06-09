#include<iostream>
#define N 20
void mergesort(int* mas, int a, int b)
{
    if (a == b)
    {
        return;
    }
    int m = (a + b) / 2;//середина последовательности 
    // рекурсивно вызываем функцию сортировки для каждой половины
    mergesort(mas, a, m);
    mergesort(mas, m + 1, b);
    int i = a;  // начало первого пути
    int j = m + 1; // начало второго пути
    int mas1 [N]; 
    for (int k = 0; k < b - a + 1; k++)  
    {
        // записываем в формируемую последовательность меньший из элементов двух путей
        // или остаток первого пути если j > b
        if ((j > b) || ((i <= m) && (mas[i] < mas[j])))
        {
            mas1[k] = mas[i];
            i++;
        }
        else
        {
            mas1[k] = mas[j];
            j++;
        }
    }
    // получившийся массив
    for (int k = 0; k < b - a + 1; k++)
    {
        mas[a + k] = mas1[k];
    }
}
int main()
{
    int mas[N];
    for (int i = 0; i < N; i++)
    {
        mas[i] = rand() % 100;
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
    mergesort(mas, 0, N - 1); 
    for (int i=0; i < N; i++)
    {
        std::cout << mas[i] << " ";
    }
}