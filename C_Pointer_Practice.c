#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include <string.h>

void main() {

	int a;

	char ch = 'Q';

	a = 10;

 

	int *pa = &a;//포인터 변수, 주소를 저장하는 변수 &=주소를 나타내는 연산자 * = 값을 나타내는 연산자

	int *pc = &ch;

 

	int temp[10];

	temp[0] = 40;

	temp[1] = 55;

	temp[2] = 70;

	printf("변수 a가 담긴 값:%d\n", a);//int a=10; ===10출력	//*이 앞에 붙으면 값

	printf("변수 a가 저장된 주소:%p\n", &a);//&x주소일때 %p사용

	printf("포인터변수 pa가 가르키는 주소(변수 a가 저장된 주소):%p\n", pa);//int *pa;   pa=&a;

	printf("주소 pa에 저장된 값(변수 a에 저장된 값):%d\n", *pa);//*다음 일반변수 사용 불가 =error //값을 나타내는 연산자 //*pa담긴 값 ===10출력

	printf("%p\n", *(&pa));

 

	printf("\n변수 a에 담긴 데이터의 크기=%d\n", sizeof(a));

	printf("a의 주소의 크기=%d\n", sizeof(&a));//4byte=32bit 단위의 메모리를 사용중이기 때문에 4가 출력

	printf("포인터변수 pa의 크기=%d", sizeof(*pa));

 

	printf("\n\n변수 ch가 담긴 값:%c\n", ch);//int ch=10; ===Q출력	//*이 앞에 붙으면 값

	printf("변수 ch가 저장된 주소:%p\n", &ch);//&x주소일때 %p사용

	printf("포인터변수 pc가 가르키는 주소(변수 ch가 저장된 주소):%p\n", pc);//int *pc;   pc=&ch;

	printf("주소 pc에 저장된 값(변수 ch에 저장된 값):%c\n", *pc);//*다음 일반변수 사용 불가 =error //값을 나타내는 연산자 //*pc담긴 값 ===Q출력

	printf("%p\n", *(&pc));

 

	printf("\n변수 ch에 담긴 데이터의 크기=%d\n", sizeof(ch));

	printf("ch의 주소의 크기=%d\n", sizeof(&ch));//4byte=32bit 단위의 메모리를 사용중이기 때문에 4가 출력

	printf("포인터변수 pc의 크기=%d", sizeof(*pc));

}
