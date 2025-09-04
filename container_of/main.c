#include <stdio.h>

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE*)0)->MEMBER)

/* container_of() - Calculate address of object that contains address ptr
 * @ptr: pointer to member variable
 * @type: type of the structure containing ptr
 * @member: name of the member variable in struct @type
 *
 * Return: @type pointer of object containing ptr
 *
 * 如果有兩個結構體，各自成員內有一個是共用的資料（記憶體位址共用）
 */
#define container_of(ptr, type, member)                            \
    __extension__({                                                \
        const __typeof__(((type *) 0)->member) *(__pmember) = (ptr); \
        (type *) ((char *) __pmember - offsetof(type, member));    \
    })

struct data{
	short a;
	char b;
	float c;
};
struct link_list {
	struct link_list *priv;
	struct link_list *next;
};
struct object{
	struct link_list list;
	struct data d;
	float f;
};

struct object_{
	short a;
	char b;
	struct data *d;
	int i;
};

int main (){
	struct object obj = {.d.a = 25, .d.b = 'A', .d.c = 12.45, .f = 13.125};
	struct object_ obj1 = {.a = 10, .d = &(obj.d), .b = 'B', .i = 12345};
	void *p_obj = container_of(&(obj.d), struct object, d);	// 獲取結構體成員記憶體位址,回推原生結構體記憶體位址開頭
	printf ("c : %f\n", ((struct object *)p_obj)->d.c);

	struct object *p_obj1 = container_of((obj1.d), struct object, d);	// 同理
	printf ("d : %f\n", p_obj1->f);
}
