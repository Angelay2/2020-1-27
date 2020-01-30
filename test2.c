#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// 模拟实现memcpy(内存拷贝 => 以字节为单位 => 不在乎类型 => 任何类型都可以拷)
// dst可被写入, 与类型无关; src是被读取,不能被写入,与类型无关;
void my_memcpy(void* dst, const void* src, int num){
	assert(dst);
	assert(src);
	//void* ret = dst;// 先保存一份  由于下一步操作 这一步操作省去, 已经分别指向
	// 为了保证操作的基本单位为1字节, 应该把void*强转换为char*,
	char* dst_p = (char*)dst;
	const char* src_p = (const char*)src;
	
	while (num--){
		*dst_p = *src_p;
		dst_p++, src_p++;
	}
	return dst;
}

int main1(){
	const char* src = "hello world!";

	char dst[64];

	//memcpy(dst, src, strlen(src) + 1);
	my_memcpy(dst, src, strlen(src) + 1);
	printf("%s\n", dst);

	system("pause");
	return 0;
}
// 理想状况: aabcd1234
// 实际状况: aaaaaaaaa
// 先把a拷给b,但是第一次拷a时,已经把后面的b 也变为a了
// 内存拷贝期间出现内存重叠问题
// 典型问题: 把整体拷给局部 或者把局部拷给整体
int main2(){
	char src[32] = "abcd1234";
	my_memcpy(src + 1, src, strlen(src) + 1);
	printf("%s\n", src);
	system("pause");
	return 0;
}

//理想状况: bcd1234
int main(){
	char src[32] = "abcd1234";
	my_memcpy(src, src + 1, strlen(src) + 1);
	printf("%s\n", src);
	system("pause");
	return 0;
}
