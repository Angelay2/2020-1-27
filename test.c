#include <stdio.h>
#include <assert.h>// �����Ϸ�У��
#include <stdlib.h>

#pragma warning(disable:4996)
// ģ��ʵ��strcat
// ���ܱ��޸� ����const�޸�
char* my_strcat(char* dst, const char* src){
	
	assert(dst != NULL);
	assert(src != NULL);
	// ��ʹ���ǵ�ָ��ָ��dst ��"\0"��
	char* ret = dst;// ����һ��dst
	// '0' => 48    '\0' => 0
	while (*dst){
		dst++;
	}// dst�Ѿ�ָ��'\0'
	while (*dst++ = *src++);// src��ֵ��dst  �ж�dst��ֵ�Ƿ�Ϊ'\0' �ǵĻ� ����ret����

	return ret;
}

int main(){
	const char* str = "hello world!\n"; 
	//strΪ����,�ں����ﶨ��ı�������ջ�Ͽ��ٿռ�(��С4�ֽ�;����Ϊh�ĵ�ַ)
	// "hello world!" ���ַ����������ٿռ�
	char buf[64];
	strcpy(buf, str);
	my_strcat(buf, str);

	printf("%s\n", buf);
	system("pause");
	return 0;
}








