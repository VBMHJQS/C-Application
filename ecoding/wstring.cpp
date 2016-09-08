#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <fstream>

int main(int argc, char *argv[])
{
   std::wstring str = L"123,我是谁？我爱钓鱼岛！";

   std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;

   std::string narrowStr = conv.to_bytes(str);
   {
      std::ofstream ofs ("c:\\test.txt");
      ofs << narrowStr;
   }

   std::wstring wideStr = conv.from_bytes(narrowStr);
   {
      std::locale::global(std::locale("Chinese-simplified"));
      std::wofstream ofs (L"c:\\testW.txt");
      ofs << wideStr;
   }
｝
