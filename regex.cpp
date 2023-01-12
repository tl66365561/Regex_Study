//regex
#include<regex>
#include<iostream>
using namespace std;
#include<string>

/*
���﷨����
^ ��������
$ ������β
\d ƥ������ 
\s ƥ��ո�
\w ƥ��һ���ַ�
\b ƥ�䵥�ʿ�ͷ�������λ��
. ƥ�����ⵥ���ַ�
* *ǰ�ĵ����ַ�(�����ո�)���Գ��������
+ +ǰ�ĵ����ַ�(�������ո�)���ٳ���һ��
��:?ǰ�ĵ����ַ�������һ��
[^x]ƥ�����x����������ַ�
[^aeiou]ƥ�����aeiou������ĸ����������ַ�

() ���� (123) ��ƥ�䵽��123ȡ����
[] ��Χ [a-z] ƥ�����е�Сд��ĸ
{} ���� {4,9} 

�����ýӿڡ�
regex: һ��������ʽ��
regex_match :ȫ��ƥ��
regex_search: ����ƥ��
regex_replace:�滻ƥ��
sregex_iterator: ���regex_search����һ��string������ƥ����Ӵ�
smatch/match_resultss: ������ ������string�������Ľ��

*/




int main()
{

	smatch results;
	string str;//�������ַ���

	//��regex_match��
	regex r1("a*");
	cout << regex_match("aaaAAA", r1) << endl; //0
	cout << regex_match("aaaAAA", regex("a*", regex::icase)) << endl; //1

	//��regex_search��
	regex r2("������|ӣľ����|�ɵ���");
	str = "��ϲ�������㻹���ɵ���?";

	if (regex_search(str, results, r2))//regex_search�ҵ���һ��ƥ��ͻ᷵��
	{
		cout << results[0];//������
		cout << results[1];//���ᱨ����û����ʾ;
	}

	//�������ƥ��������н��: ������ �ɵ���
	string::const_iterator iterStart = str.begin(); //����������
	string::const_iterator iterEnd = str.end();
	string temp;
	while (regex_search(iterStart, iterEnd, results, r2))
	{
		temp = results[0];
		cout << temp << endl;
		iterStart = results[0].second; //����������ʼλ�ã�����ʣ�µ��ַ���
	}
	
	//��regex_replace��
	//1.�ַ����滻 
	cout << str<<endl;
	cout << regex_replace(str, r2, "��ľ����")<<endl;//��ϲ����ľ���ӻ��ǳ�ľ���ӣ�
	cout << str << endl;//���ı�


	string str2 = "Hello_2019!";
	regex r3(".{3}");  //ƥ��3�������ַ��»���
	/*
	if (regex_search(str2, results, r3))//regex_search�ҵ���һ��ƥ��ͻ᷵��
	{
		cout << results[0]<<endl;
	}

	string::const_iterator iterStart2 = str2.begin(); //����������
	string::const_iterator iterEnd2 = str2.end();
	string temp2;
	while (regex_search(iterStart2, iterEnd2, results, r3))
	{
		temp2 = results[0];
		cout << temp2 << endl;
		iterStart2 = results[0].second; //����������ʼλ�ã�����ʣ�µ��ַ���
	}
	*/
	
	
	//��sregex_iterator��:�Զ���������regex_search()��Ѱ���ļ�����ƥ��
	sregex_iterator it(str2.begin(), str2.end(), r3);
	sregex_iterator end_it;
	for (  ; it != end_it; ++it)
	{
		cout << it->str() << endl;
	}
		
}

//����regexʾ��