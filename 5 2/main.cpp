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

#define 한승쌤

int main()
{
#if false
	int* ptr; // <= 포인터
	int num = 5;
	
	std::cout << num << std::endl;
	std::cout << &num << std::endl; // <= 5가 저장된 num의 주소를 가르킨다

	ptr = &num; // <= 5가 저장된 num 의 주소를 ptr 이 알게됨

	std::cout << *ptr << std::endl; // <= ptr 에 저장된 num 의 주소에 있는 값 5를 보여줌

	auto fPtr = function; // <= 함수의 주소를 넘김

	fPtr(); // <= fPtr 에 있는 function 함수 호출함
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
	function(num); // <= num 값을 들고 다른 변수를 만들어서 가져감
	std::cout << num << std::endl; 

	function(num);
	function(&num);
#endif

	// 반환타입(*변수명)(매개변수) = 함수주소;

	//int(*a)() = fget;



	fData(set)(4);
	std::cout << fData(get)();


	return(0);
}