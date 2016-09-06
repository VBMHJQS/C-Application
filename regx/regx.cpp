#include <cstdio>
#include <cstring>
#include <regex.h>
#include <iostream>
using namespace std;

#define SUBSLEN 10              /* 匹配子串的数量 */
#define EBUFLEN 128          /* 错误消息buffer长度 */
#define BUFLEN 1024          /* 匹配到的字符串buffer长度 */
int main()
{
	size_t       len;
	regex_t       re;      /* 存储编译好的正则表达式，正则表达式在使用之前要经过编译 */
	regmatch_t    subs [SUBSLEN]; /* 存储匹配到的字符串位置 */
	char          matched [BUFLEN];     /* 存储匹配到的字符串 */
	char          errbuf [EBUFLEN]; /* 存储错误消息 */
	int          err, i;
	char          src    [] = "I1606"; /* 源字符串 */
	char          pattern [] = "^[A-Za-z]+"; /* pattern字符串 */
	cout<<"String : "<<src<<endl;
	cout<<"Pattern : "<<pattern<<endl;
	/* 编译正则表达式 */
	err = regcomp(&re, pattern, REG_EXTENDED);
	if (err) {
		len = regerror(err, &re, errbuf, sizeof(errbuf));
		cout<<"error: regcomp: "<<errbuf<<endl;
		//return 1;
	}
	cout<<"Total has subexpression: "<<re.re_nsub<<endl;
	/* 执行模式匹配 */
	err = regexec(&re, src, (size_t) SUBSLEN, subs, 0);
	if (err == REG_NOMATCH) { /* 没有匹配成功 */
		cout<<"Sorry, no match ..."<<endl;
		regfree(&re);
		return 0;
	} else if (err) {   /* 其它错误 */
		len = regerror(err, &re, errbuf, sizeof(errbuf));
		cout<<"error: regexec: "<< errbuf<<endl;
		return 1;
	}
	/* 如果不是REG_NOMATCH并且没有其它错误，则模式匹配上 */
	cout<<"\nOK, has matched ..."<<endl;
	for (i = 0; i <= re.re_nsub; i++) {
		len = subs[i].rm_eo - subs[i].rm_so;
		if (i == 0) {
			cout<<"begin: "<<subs[i].rm_so<<", len ="<<len<<endl; /* 注释1 */
		} else {
			cout<<"subexpression "<<i<<" begin: "<<subs[i].rm_so<<", len ="<<len<<endl;
		}
		memcpy (matched, src + subs[i].rm_so, len);
		matched[len] = '\0';
		cout<<"match: "<< matched<<endl;
	}
	regfree(&re); /* 用完了别忘了释放 */
	return (0);
}
