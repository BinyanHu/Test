//#include<iostream>
//#include <fstream>
//#include <stdio.h>
//#include <math.h>
//#include<string>
//#include<bitset>
//
//#define DEPTH 256
//#define WIDTH 8
//
//using namespace std;
//
//void main()
//{
//	ifstream bins;
//	bins.open("E:\\Shool Works\\2017 - 2018_2\\Computer Architecture and Organization\\bubble.cbin");
//	if (!bins.is_open())
//	{
//		cout << "Can not creat file!\r\n";
//		return;
//	}
//
//	ofstream bubble;
//	bubble.open("E:\\Shool Works\\2017 - 2018_2\\Computer Architecture and Organization\\bubble.dec");
//	if (!bubble.is_open())
//	{
//		cout << "Can not creat file!\r\n";
//		return;
//	}
//	else
//	{
//		string binArr;
//		for (size_t i = 1; i <= 22; i++)
//		{
//			bins >> binArr;
//			for (char& binStr: binArr)
//			{
//
//			}
//			bitset<20> bin(binArr);			
//			bubble << i << " : " << bin.to_ulong() << ";" << endl;
//		}
//	}
//
//	bins.close();
//	bubble.close();
//	
//	system("pause");
//}