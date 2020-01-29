#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// ģ��ʵ��strcmp
int my_strcmp(const char* str1, const char* str2){
	// У��
	assert(str1);
	assert(str2);

	int ret = 0;
	//ret = *str1 - *str2;
	// ��ǿתΪ�޷�������, �������ֻ���еڰ�λ���
	// Ϊ0 => ������� �����ѭ��, ��ȡ��(!ret)
	// && *str1 �����������ַ�������Ҳ�Ϊ'\0'
	while (!(ret = *(unsigned char*)str1 - *(unsigned char*)str2) && *str1){
		str1++, str2++;
	}
	if (ret > 0){
		return 1;
	}
	else if (ret < 0){
		return -1;
	}
	else{
		return 0;
	}
}

// ���Ϊ1, ǰ�ߴ�Ϊ1, ǰ��СΪ-1
int main(){
	const char* str1 = "hello world!";
	const char* str2 = "hello world!";

	//int ret = strcmp(str1, str2);
	int ret = my_strcmp(str1, str2);
	printf("%d\n", ret);

	system("pause");
	return 0;
}







