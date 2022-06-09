#include <iostream>
struct list
{
	int field;// поле данных
	struct list* next;// указатель на следующий элемент
	struct list* prev;// указатель на предыдущий элемент
};
struct list* init(int a)// а- значение первого узла
{
	struct list* lst;
	// выделение памяти под корень списка
	//malloc-выдяляет память
	lst = (struct list*)malloc(sizeof(struct list));
	lst->field = a;
	lst->next = lst;// указатель на следующий узел
	lst->prev = lst;// указатель на предыдущий узел
	return(lst);
}
//функция добавления 
struct list* addelem(list* lst, int number)
{
	struct list* temp, * p;
	temp = (struct list*)malloc(sizeof(list));
	p = lst->next;// сохранение указателя на следующий узел
	lst->next = temp; // предыдущий узел указывает на создаваемый
	temp->field = number; // сохранение поля данных добавляемого узла
	temp->next = p; // созданный узел указывает на следующий узел
	temp->prev = lst;// созданный узел указывает на предыдущий узел
	p->prev = temp;
	return(temp);
}
//функция удаления
struct list* deletelem(list* lst)
{
	struct list* prev, * next;
	prev = lst->prev;
	next = lst->next;
	prev->next = lst->next;// переставляем указатель
	next->prev = lst->prev;// переставляем указатель
	free(lst);// освобождаем память удаляемого элемента
	return(prev);
}
//вывод элементов
void listprint(list* lst)
{
	struct list* p;
	p = lst;
	do {
		//в обратном порядке
		p = p->prev;
		printf("%d ", p->field); 
		//в обычном порядке
		/*printf("%d ", p->field);
		p = p->next;*/
	} while (p != lst);
}

int main()
{
	int n;
	std::cin >> n;
	srand(time(0));
	list* head = init(rand());
	for (int i = 0; i < n; i++)
		addelem(head, rand() % 10000);
	listprint(head);
	deletelem(head->next);
	std::cout << std::endl;
	listprint(head);
	addelem(head->next->next,400);
	std::cout << std::endl;
	listprint(head);
}