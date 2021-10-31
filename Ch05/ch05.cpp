#include "../../std_lib_facilities.h"

int main()
{
	try
	{
		//1.
		cout << "Success!\n";

		//2.
		cout << "Success!\n";

		//3.
		cout << "Success" << "!\n";

		//4.
		cout << "Success" << "!\n";

		//5.
		int res = 7;
		vector <int> v(10);
		v[5] = res;
		cout << "Success!\n";

		//6.
		vector <int> v6(10);
		v6[5] = 7;
		if (v6[5] == 7) cout << "Success!\n";

		//7.
		if (true)
		{
			cout << "Success!\n";
		}
		else
		{
			cout << "Fail!\n";
		}

		//8.
		bool c8 = false;
		if (c8 == false)
		{
			cout << "Success!\n";
		}
		else cout << "Fail!\n";
	

		//9.
		string s9 = "ape";
		bool c9 = "fool" > s9;
		if (c9) cout << "Success!\n";

		//10.
		string s10 = "ape";
		if (s10 != "fool") cout << "Success!\n";

		//11.
		string s11 = "ape";
		if (s11 != "fool") cout << "Success!\n";

		//12.
		string s12 = "ape";
		string help = " ";
		if (help != s12 + "fool") cout << "Success!\n";

		//13.
		vector<char> v13(5);
		for (int i = 0; i < v13.size(); ++i)
			cout << "Success!\n";


		//14.
		vector<char> v14(5);
		for (int i = 0; i <= v14.size(); ++i)
		{
			cout << "Success!\n";
		}

		//15.
		string s15 = "Success!\n";
		for (int i = 0; i < s15.size(); ++i)
			cout << s15[i];


		//16.
		if (true)
			cout << "Success!\n";
		else
			cout << "Fail!\n";


		//17.
		int x17 = 2000;
		int c17 = x17;
		if (c17 == 2000) cout << "Success!\n";

		//18.
		string s18 = "Success!\n";
		for (int i = 0; i < 10; i++)
		{
			cout << s18[i];
		}

		//19.
		vector <int> v19(5);
		for (int i = 0; i <= v19.size(); ++i)
		{
			cout << "Success!\n";
		}

		//20.
		int i20 = 0;
		int j20 = 9;
		while (j20 < 10) ++j20;
		if (j20 > i20) cout << "Success!\n";

		//21.
		double x21 = 2;
		double divider = x21 - 1;
		double d21 = (5 / divider);
		if (d21 == 2 * (x21 + 0.5))
			cout << "Success!\n";

		//22.
		vector <string> s22;
		s22.push_back("Success!\n");
		for (int i = 0; i < s22.size(); ++i)
			cout << s22[i];

		//23.
		int i23 = 0, j23 = 11;
		while (i23 < 10) ++i23;
		if (j23 > i23) cout << "Success!\n";

		//24.
		double x24 = 2;
		double div = x24 - 1;
		double d24 = (5 / div);
		if (d24 = 2 * (x24 + 0.5))
			cout << "Success!\n";


		//25.
		cout << "Success!\n";


		keep_window_open();
		return 0;
	}
	catch (exception& e)
	{
		cerr << "error: " << e.what() << '\n';
		keep_window_open();
		return 1;
	}
	catch (...)
	{
		cerr << "Oops: unknown exception!\n";
		keep_window_open();
		return 2;
	}
}