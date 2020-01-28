#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// 模拟strstr(字符串查找)
// 在str = "abcd123xy4abcdxyzwabcd4321" 中找 sub_str = "xyz"
// 至少需要两次循环 外部循环确定以谁开头,内层循环是进行字符串相等的逐个比较
// 需要定义(一个指向a =>start, 一个指向x =>sub_str
// 分别有两个遍历的指针往后走 =>start_p, p)4个指针
// 先比较*p和*start_p, 如果不相等,start往后移动一位,start_p与start再次相等,start_p指向start
// 再次比较*p和*start_p, 当*p指向'\0'时,最后直接返回start的值

// 若优化: 只要*start 指向字符串前面(比如2)时,只要保证start < (长串当中-若干字符)
// 需用str的总长度 - sub_str的总长度,p + 长度差 + 1 = 所需值,
// 字符串长度的确定需要遍历 ,=> 需要循环, 复杂 效率有可能降低, 不建议

// KMP算法
char* my_strstr(const char* str, const char* sub_str){
	assert(str);
	assert(sub_str);

	const char* start = str;
	const char* start_p = /*str*/NULL;
	const char* p = /*sub_str*/NULL;// 后面有重新赋值
	// 控制起始查找位置
	// 只要*start != '\0',一直找
	while (*start){
		p = sub_str;
		start_p = start;
		// 控制具体一次查找的过程 在两者都不为0的情况下,从前往后比较*start_p和*p,
		// 循环结束的可能:
		// 1. start_p 为空, 为'\0'
		// 2. p 为'\0'
		// 3. 两者不相等
		// 但只要*p = '\0', 找到最结尾, start_p 最多就是'\0',
		while (*start_p && *p && *start_p == *p){
			start_p++;
			p++;
		}
		if (*p == '\0'){
			return start;
		}
		start++;// 第一次内部循环没找到, 更新start_p和p的起始位置
	}
	return NULL;// 整个循环都没找到
}
int main1(){
	const char* str = "abcd123xy4abcdxyzwabcd4321";
	const char* sub_str = "xyz";

	//char* ret = strstr(str, sub_str);
	char* ret = my_strstr(str, sub_str);
	printf("%s\n", ret);
	system("pause");
	return 0;
}

// 模拟实现strcmp(字符串比较 => 根据字符串的ASCII码值进行比较)
// 两个字符串相等且不等于'\0' => 继续往后走
// 循环结束可能:
// 1. 不相等(大于/小于)
// 2. 相等 ret = 0
int main(){
	const char* str1 = "hello world!";
	const char* str2 = "Hello world!";

	int ret = strcmp(str1, str2);
	printf("%d\n", ret);
	system("pause");
	return 0;

}














