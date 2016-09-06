/**
 * 1、安装curllib url：https://curl.haxx.se/download.html
 *       tar -zxf xxx.tar.gz
 *       cd xxxx
 *       ./configure --prefix=/usr/local/curl
 *       make
 *       make install
 * 2、 cp /usr/local/curl /usr/include
 * 3、编译时加上 -lcurl
 *
 * http://blog.csdn.net/huyiyang2010/article/details/7664201#comments
 */
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <curl/curl.h>

using namespace std;

#define FILENAME   "curlposttest.log"

size_t write_data(void* buffer,size_t size,size_t nmemb,void *stream)
{
	FILE *fptr = (FILE*)stream;
	fwrite(buffer,size,nmemb,fptr);
	return size*nmemb;
}
int post(const string & strPost){
	cout<< strPost << endl;
	CURL *curl;
	CURLcode res;
	FILE* fptr;
	//struct curl_slist *http_header = NULL;

	if ((fptr = fopen(FILENAME,"w")) == NULL)
	{
		cout<<stderr<<"fopen file error:"<<FILENAME<<endl;
		return -1;
	}
	try{
		curl = curl_easy_init();
		if (!curl)
		{
			cout<<stderr<<"curl init failed"<<endl;
			return -1;
		}

		curl_easy_setopt(curl,CURLOPT_URL,"http://test.5iquant.com/sig/sys/test"); //url地址
		curl_easy_setopt(curl,CURLOPT_POSTFIELDS,strPost.c_str()); //post参数
//		curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data); //对返回的数据进行操作的函数地址
//		curl_easy_setopt(curl,CURLOPT_WRITEDATA,fptr); //这是write_data的第四个参数值
//		curl_easy_setopt(curl,CURLOPT_POST,1); //设置问非0表示本次操作为post
//		curl_easy_setopt(curl,CURLOPT_VERBOSE,1); //打印调试信息
//		curl_easy_setopt(curl,CURLOPT_HEADER,1); //将响应头信息和相应体一起传给write_data
//		curl_easy_setopt(curl,CURLOPT_FOLLOWLOCATION,1); //设置为非0,响应头信息location
		//curl_easy_setopt(curl,CURLOPT_COOKIEFILE,"/Users/zhu/CProjects/curlposttest.cookie");

		res = curl_easy_perform(curl);

		if (res != CURLE_OK)
		{
			switch(res)
			{
			case CURLE_UNSUPPORTED_PROTOCOL:
				cout<<stderr<<"不支持的协议,由URL的头部指定"<<endl;
			case CURLE_COULDNT_CONNECT:
				cout<<stderr<<"不能连接到remote主机或者代理"<<endl;
			case CURLE_HTTP_RETURNED_ERROR:
				cout<<stderr<<"http返回错误"<<endl;
			case CURLE_READ_ERROR:
				cout<<stderr<<"读本地文件错误"<<endl;
			default:
				cout<<stderr<<"返回值"<<res<<endl;
			}
			return -1;
		}
	}catch(exception& e){
		cout<<"error: "<<e.what()<<endl;
	}
	curl_easy_cleanup(curl);
}

int main()
{
	string data_post = "email=myemail@163.com&password=mypassword&autologin=1&submit=登 录&type=user";
	for(int i=0;i<1000;i++){
		int num = post(data_post);
		cout<<i<<endl;
	}

}

