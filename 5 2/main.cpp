#include <iostream>

#define fData(system) f##system

int a = 0;
int fget()
{
	return a;
}

void fset(int num)
{
	a = num;
}

//void function(int num)
//{
//	std::cout << num * 2 << std::endl;
//}
//
//void function(int* num)
//{
//	std::cout << *num * 2 << std::endl;
//}

#define �ѽ½�

int main()
{
#if false
	int* ptr; // <= ������
	int num = 5;
	
	std::cout << num << std::endl;
	std::cout << &num << std::endl; // <= 5�� ����� num�� �ּҸ� ����Ų��

	ptr = &num; // <= 5�� ����� num �� �ּҸ� ptr �� �˰Ե�

	std::cout << *ptr << std::endl; // <= ptr �� ����� num �� �ּҿ� �ִ� �� 5�� ������

	auto fPtr = function; // <= �Լ��� �ּҸ� �ѱ�

	fPtr(); // <= fPtr �� �ִ� function �Լ� ȣ����
#endif
#if false
	int num = 6;
	int ptr = (int)&num;
	int pptr = (int)&ptr;

	std::cout << (int*)ptr << " " << (int**)pptr << std::endl;

	std::cout << *(int*)ptr << " " << **(int**)pptr << std::endl;
#endif
#if false
	int num = 77;
	function(num); // <= num ���� ��� �ٸ� ������ ���� ������
	std::cout << num << std::endl; 

	function(num);
	function(&num);
#endif

	// ��ȯŸ��(*������)(�Ű�����) = �Լ��ּ�;

	//int(*a)() = fget;



	fData(set)(4);
	std::cout << fData(get)();


	return(0);
}