//#include<iostream>
//#include<random>
//#include<string>
////#include<ctime>
//
//using namespace std;
//
//int main()
//{
//	default_random_engine generator;
//	uniform_real_distribution<float> uniDis(0, 100);
//	normal_distribution<float> normalDis(60, 10);
//	poisson_distribution<int> poisDis(55);
//
//	//cout << "uniform" << endl;
//	//for (size_t i = 0; i < 100; i++)
//	//{
//	//	cout << uniDis(generator) << endl;
//	//}
//	//cout << endl;
//
//	//cout << "normal" << endl;
//	//for (size_t i = 0; i < 100; i++)
//	//{
//	//	cout <<"B " << normalDis(generator) << endl;
//	//}
//	//cout << endl;
//
//	//cout << "poisson" << endl;
//	//for (size_t i = 0; i < 100; i++)
//	//{
//	//	cout << poisDis(generator) << endl;
//	//}
//	//cout << endl;
//
//	vector<float> vals;
//
//	for (int i = 0; i < 100; i++)
//	{
//		float val;
//		string str;
//		//cin >> str;
//		cin >> val;
//		vals.push_back(val);
//	}
//	for (float val : vals)
//	{
//		cout << val << ' ';
//	}
//
//	//random_shuffle(vals.begin(), vals.end());
//
//	//cout << endl;
//	//for (int i = 0; i <= 49; i++)
//	//{
//	//	cout << vals[i] << endl;
//	//}
//	//cout << endl;
//	//for (int i = 50; i <= 99; i++)
//	//{
//	//	cout << vals[i] << endl;
//	//}
//
//	system("pause");
//}