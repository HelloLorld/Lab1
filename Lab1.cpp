#include <iostream>

struct list
{
	int inf;
	list* next;
};

list* create(int);			//Функция создания
list* insert(list*, int);	//Функция вставки

int main()
{
	std::cout<<"How many elements?\n";
	int n=0;
	int chek = 0;	

	//Блок проверки ввода
	while (chek != 1)
	{
		while (!(std::cin >> n))
		{

			std::cin.clear();
			std::cout << "Just a integer number!\nEnter number[0;10]: ";
			std::cin.ignore(32767, '\n');
		}
		if ((n >= 0) && (n <= 10)) chek = 1;
		if (chek == 0)	std::cout<<"Wrong enter!\nEnter number[0;10]: ";
	}

	if (n == 0)
	{
		std::cout<<"The list was not created.";
		exit(0);
	}

	//Вызов функции создания
	list* head = create(n);
	list* cur = head;
	std::cout << "Specify the element before which you want to insert a new element:";
	int ins=0;
	chek = 0;
	//Блок проверки ввода
	while (chek != 1)
	{
		while (!(std::cin >> ins))
		{

			std::cin.clear();
			std::cout << "Just a integer number!\nEnter number[0;"<<n<<"]:";
			std::cin.ignore(32767, '\n');
		}
		if ((ins >= 0) && (ins <= n)) chek = 1;
		if (chek == 0)	std::cout << "Wrong enter!\nEnter number[0;" << n << "]:";
	}
	//Вызов функции вставки
	head = insert(head, ins);
	cur = head;
	//Вывод конечного списка
	while (cur)
	{
		std::cout << cur->inf << "\t";
		cur = cur->next;
	}
	return 0;
}

//Функция создания списка
list* create(int n)
{
	list* head = new list;
	head->next = nullptr;
	head->inf = 0;
	list* cur = head;
	for (int i = 1; i < n; i++)
	{
		cur->next = new list;
		cur = cur->next;
		cur->inf = i;
		cur->next = nullptr;
	}
	return head;
}

//Функция вставки элемента в список
list* insert(list* head, int n)
{
	list* cur = head;
	list* tmp = new list;
	tmp->inf = 2020;
	if (n == 1)
	{
		tmp->next = head;
		head = tmp;
		return head;
	}
	for (int i = 0; i < n-2; i++)
	{
		cur = cur->next;
	}
	std::cout << "cur:" << cur->inf<<std::endl;
	tmp->next = cur->next;
	cur->next = tmp;
	return head;
}
