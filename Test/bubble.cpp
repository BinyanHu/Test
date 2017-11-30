//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//vector<int> Data{ 0,1,2,3,4,5,6,7,8,9 };
//
//void main()
//{
//	size_t i = 1;
//	while (i < Data.size()) 
//	{
//		size_t j = 0;
//		while ((j + i) < Data.size()) 
//		{
//			cout << "R3=" << j << ", R4=" << j + 1 << endl;
//			cout << "R5=" << Data[j] << ", R6=" << Data[j + 1] << endl;
//			cout << endl;
//			if (Data[j + 1] < Data[j]) 
//			{
//				int tmp = Data[j];
//				Data[j] = Data[j + 1];
//				Data[j + 1] = tmp;
//				//cout << "Result: R5" << j + 1 << ": " << Data[j + 1] << ", " << j << ": " << Data[j] << endl;
//			}
//			j++;
//		}
//		i++;
//	}
//
//	for (const int val : Data)
//	{
//		cout << val << " ";
//	}
//	cout << endl;
//
//	system("pause");
//}
