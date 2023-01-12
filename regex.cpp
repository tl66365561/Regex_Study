//regex
#include<regex>
#include<iostream>
using namespace std;
#include<string>

/*
【语法规则】
^ 限制行首
$ 限制行尾
\d 匹配数字 
\s 匹配空格
\w 匹配一般字符
\b 匹配单词开头或结束的位置
. 匹配任意单个字符
* *前的单个字符(包括空格)可以出现任意次
+ +前的单个字符(不包括空格)至少出现一次
？:?前的单个字符最多出现一次
[^x]匹配除了x以外的任意字符
[^aeiou]匹配除了aeiou几个字母以外的任意字符

() 分组 (123) 将匹配到的123取出来
[] 范围 [a-z] 匹配所有的小写字母
{} 长度 {4,9} 

【常用接口】
regex: 一个正则表达式类
regex_match :全文匹配
regex_search: 搜索匹配
regex_replace:替换匹配
sregex_iterator: 配合regex_search遍历一个string中所有匹配的子串
smatch/match_resultss: 容器类 保存在string中搜索的结果

*/




int main()
{

	smatch results;
	string str;//待检索字符串

	//【regex_match】
	regex r1("a*");
	cout << regex_match("aaaAAA", r1) << endl; //0
	cout << regex_match("aaaAAA", regex("a*", regex::icase)) << endl; //1

	//【regex_search】
	regex r2("流川枫|樱木花道|仙道彰");
	str = "你喜欢流川枫还是仙道彰?";

	if (regex_search(str, results, r2))//regex_search找到第一个匹配就会返回
	{
		cout << results[0];//流川枫
		cout << results[1];//不会报错但是没有显示;
	}

	//输出所有匹配的子序列结果: 流川枫 仙道彰
	string::const_iterator iterStart = str.begin(); //迭代器声明
	string::const_iterator iterEnd = str.end();
	string temp;
	while (regex_search(iterStart, iterEnd, results, r2))
	{
		temp = results[0];
		cout << temp << endl;
		iterStart = results[0].second; //更新搜索起始位置，搜索剩下的字符串
	}
	
	//【regex_replace】
	//1.字符串替换 
	cout << str<<endl;
	cout << regex_replace(str, r2, "赤木晴子")<<endl;//你喜欢赤木晴子还是赤木晴子？
	cout << str << endl;//不改变


	string str2 = "Hello_2019!";
	regex r3(".{3}");  //匹配3个任意字符下划线
	/*
	if (regex_search(str2, results, r3))//regex_search找到第一个匹配就会返回
	{
		cout << results[0]<<endl;
	}

	string::const_iterator iterStart2 = str2.begin(); //迭代器声明
	string::const_iterator iterEnd2 = str2.end();
	string temp2;
	while (regex_search(iterStart2, iterEnd2, results, r3))
	{
		temp2 = results[0];
		cout << temp2 << endl;
		iterStart2 = results[0].second; //更新搜索起始位置，搜索剩下的字符串
	}
	*/
	
	
	//【sregex_iterator】:自动反复调用regex_search()来寻找文件所有匹配
	sregex_iterator it(str2.begin(), str2.end(), r3);
	sregex_iterator end_it;
	for (  ; it != end_it; ++it)
	{
		cout << it->str() << endl;
	}
		
}

//典型regex示例