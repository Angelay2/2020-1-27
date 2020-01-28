#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// ģ��strstr(�ַ�������)
// ��str = "abcd123xy4abcdxyzwabcd4321" ���� sub_str = "xyz"
// ������Ҫ����ѭ�� �ⲿѭ��ȷ����˭��ͷ,�ڲ�ѭ���ǽ����ַ�����ȵ�����Ƚ�
// ��Ҫ����(һ��ָ��a =>start, һ��ָ��x =>sub_str
// �ֱ�������������ָ�������� =>start_p, p)4��ָ��
// �ȱȽ�*p��*start_p, ��������,start�����ƶ�һλ,start_p��start�ٴ����,start_pָ��start
// �ٴαȽ�*p��*start_p, ��*pָ��'\0'ʱ,���ֱ�ӷ���start��ֵ

// ���Ż�: ֻҪ*start ָ���ַ���ǰ��(����2)ʱ,ֻҪ��֤start < (��������-�����ַ�)
// ����str���ܳ��� - sub_str���ܳ���,p + ���Ȳ� + 1 = ����ֵ,
// �ַ������ȵ�ȷ����Ҫ���� ,=> ��Ҫѭ��, ���� Ч���п��ܽ���, ������

// KMP�㷨
char* my_strstr(const char* str, const char* sub_str){
	assert(str);
	assert(sub_str);

	const char* start = str;
	const char* start_p = /*str*/NULL;
	const char* p = /*sub_str*/NULL;// ���������¸�ֵ
	// ������ʼ����λ��
	// ֻҪ*start != '\0',һֱ��
	while (*start){
		p = sub_str;
		start_p = start;
		// ���ƾ���һ�β��ҵĹ��� �����߶���Ϊ0�������,��ǰ����Ƚ�*start_p��*p,
		// ѭ�������Ŀ���:
		// 1. start_p Ϊ��, Ϊ'\0'
		// 2. p Ϊ'\0'
		// 3. ���߲����
		// ��ֻҪ*p = '\0', �ҵ����β, start_p ������'\0',
		while (*start_p && *p && *start_p == *p){
			start_p++;
			p++;
		}
		if (*p == '\0'){
			return start;
		}
		start++;// ��һ���ڲ�ѭ��û�ҵ�, ����start_p��p����ʼλ��
	}
	return NULL;// ����ѭ����û�ҵ�
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

// ģ��ʵ��strcmp(�ַ����Ƚ� => �����ַ�����ASCII��ֵ���бȽ�)
// �����ַ�������Ҳ�����'\0' => ����������
// ѭ����������:
// 1. �����(����/С��)
// 2. ��� ret = 0
int main(){
	const char* str1 = "hello world!";
	const char* str2 = "Hello world!";

	int ret = strcmp(str1, str2);
	printf("%d\n", ret);
	system("pause");
	return 0;

}














