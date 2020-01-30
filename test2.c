#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// ģ��ʵ��memcpy(�ڴ濽�� => ���ֽ�Ϊ��λ => ���ں����� => �κ����Ͷ����Կ�)
// dst�ɱ�д��, �������޹�; src�Ǳ���ȡ,���ܱ�д��,�������޹�;
void my_memcpy(void* dst, const void* src, int num){
	assert(dst);
	assert(src);
	//void* ret = dst;// �ȱ���һ��  ������һ������ ��һ������ʡȥ, �Ѿ��ֱ�ָ��
	// Ϊ�˱�֤�����Ļ�����λΪ1�ֽ�, Ӧ�ð�void*ǿת��Ϊchar*,
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
// ����״��: aabcd1234
// ʵ��״��: aaaaaaaaa
// �Ȱ�a����b,���ǵ�һ�ο�aʱ,�Ѿ��Ѻ����b Ҳ��Ϊa��
// �ڴ濽���ڼ�����ڴ��ص�����
// ��������: �����忽���ֲ� ���߰Ѿֲ���������
int main2(){
	char src[32] = "abcd1234";
	my_memcpy(src + 1, src, strlen(src) + 1);
	printf("%s\n", src);
	system("pause");
	return 0;
}

//����״��: bcd1234
int main(){
	char src[32] = "abcd1234";
	my_memcpy(src, src + 1, strlen(src) + 1);
	printf("%s\n", src);
	system("pause");
	return 0;
}
