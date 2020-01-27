#include <stdio.h>
#include <assert.h>// 参数合法校验
#include <stdlib.h>

#pragma warning(disable:4996)
// 模拟实现strcat
// 不能被修改 就用const修改
char* my_strcat(char* dst, const char* src){
	
	assert(dst != NULL);
	assert(src != NULL);
	// 先使我们的指针指向dst 的"\0"处
	char* ret = dst;// 保存一份dst
	// '0' => 48    '\0' => 0
	while (*dst){
		dst++;
	}// dst已经指向'\0'
	while (*dst++ = *src++);// src赋值给dst  判断dst的值是否为'\0' 是的话 返回ret即可

	return ret;
}

int main(){
	const char* str = "hello world!\n"; 
	//str为变量,在函数里定义的变量就在栈上开辟空间(大小4字节;内容为h的地址)
	// "hello world!" 在字符常量区开辟空间
	char buf[64];
	strcpy(buf, str);
	my_strcat(buf, str);

	printf("%s\n", buf);
	system("pause");
	return 0;
}








