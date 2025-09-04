#include <stdio.h>

/*
 * 將記憶體位址對齊為0x00,然後type casting 成TYPE結構變數
 * 並指到結構體內隨意成員，最後在將偏移量type casting 成 size_t
 */
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE*)0)->MEMBER)

struct data{
	short a;
	char b;
	float c;
};

int main(){
	struct data x = {.a = 25, .b = 'A', .c = 12.45};

	void *p_short = (void *)&x + offsetof(struct data, a);
	printf ("a = %d\n", *((short *)p_short));
//	printf ("offset : %d\n", (size_t) &(((struct data*)0)->c));

	char *p_char = (void *)&x + offsetof(struct data, b);
	printf ("b = %c\n", *((char *)p_char));

	float *p_float = (void *)&x + offsetof(struct data, c);
	printf ("c = %f\n", *((float *)p_float));
}
