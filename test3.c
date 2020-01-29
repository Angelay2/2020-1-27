#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// 模拟实现strcmp
int my_strcmp(const char* str1, const char* str2){
	// 校验
	assert(str1);
	assert(str2);

	int ret = 0;
	//ret = *str1 - *str2;
	// 先强转为无符号整形, 再相减就只进行第八位相减
	// 为0 => 两者相等 需继续循环, 则取反(!ret)
	// && *str1 隐含了两个字符串相等且不为'\0'
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

// 相等为1, 前者大为1, 前者小为-1
int main(){
	const char* str1 = "hello world!";
	const char* str2 = "hello world!";

	//int ret = strcmp(str1, str2);
	int ret = my_strcmp(str1, str2);
	printf("%d\n", ret);

	system("pause");
	return 0;
}







