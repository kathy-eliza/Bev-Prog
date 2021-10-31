/*
calculator08buggy.cpp
Helpful comments removed.
We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "../../std_lib_facilities.h"

struct Token
{
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string val) :kind(ch), name(val) { }		//Hianyzo sor
};

class Token_stream
{
	bool full;
	Token buffer;
	
	public:
	Token_stream() :full(0), buffer(0) { }
	Token get();
	void unget(Token t) { buffer = t; full = true; }
	void ignore(char);
};

	const char let = '#';	//Drill 10.) Change the "declaration keyword" from let to #.
	const char exitprog = 'E';
	const char print = ';';
	const char number = '8';
	const char name = 'a';
	const char sqroot = 'S';	//Drill 7.) Give the user a square root function sqrt().
	const char power = 'P';		//Drill 9.) Allow the user to use pow(x,i).

	Token Token_stream::get()
	{
		if (full)
		{
			full = false; return buffer;
		}
		char ch;
		cin >> ch;
		switch (ch)
		{
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case ';':
		case '=':
		case 'k':	//Drill Ch07/6.)Add a predefined name k meaning 1000.
		case ',':
		{
			return Token(ch);
		}
		case '#':
		{
			return Token(let);
		}
		case '.':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{
			cin.unget();
			double val;
			cin >> val;
			return Token(number, val);
		}
		default:
		{
			if (isalpha(ch))	//a ch egy betu-e?
			{
				string s;
				s += ch;
				while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))	//beolvassa: chars, strings vagy digits
				{
				s += ch;		//ERROR s = ch;
				}
				cin.unget();	//a legutobbi beolvasott karaktert visszateszi a streambe
				if (s == "exit") return Token(exitprog); //Error: if (s == "quit") return Token(name);
				if (s == "sqrt") return Token(sqroot);	//Drill 7.) Give the user a square root function sqrt().
				if (s == "pow") return Token(power);	//Drill 9.) Allow the user to use pow(x,i).
				
				return Token(name, s);
				
			}
			error("Bad token");
			return Token(' '); //Hianyzo sor
		}
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind)
	{
		full = false;
		return;
	}
		full = false;
		char ch;
		while (cin >> ch)
	{
		if (ch == c) return;
	}
}

struct Variable
{
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;

double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
{
	if (names[i].name == s)
{
	return names[i].value;
}
}
	error("get: undefined name ", s);
	return 0.0; //Hianyzo sor
}

void set_value(string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
	{
		if (names[i].name == s)
		{
		names[i].value = d;
		return;
		}
	}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (int i = 0; i<names.size(); ++i)
	{
	if (names[i].name == s) return true;
	}
	return false;
}

Token_stream ts;

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case '(':
	{
	double d = expression();
	t = ts.get();
	if (t.kind != ')') error("')' expected");
	return d; //Hianyzo sor
	}
	case '-':
	{
		return -primary();
	}
	case '+':
	{
		return primary();
	}
	case number:
	{
		return t.value;
	}
	case sqroot:		//Drill 7.) Give the user a square root function sqrt().
	{
	t = ts.get();
	if (t.kind != '(')
	{
		error("'(' expected");
	}
	ts.unget(t);
	double d = primary();
	if (d < 0.0)
	{
		error("negative square root");
	}
	return sqrt(d);
	}
	case power: //Drill 9.) Allow the user to use pow(x,i).
	{
	t = ts.get();
	if (t.kind != '(')
	{
		error("'(' expected");
	}

	double x = expression();

	t = ts.get();
	if (t.kind != ',')
	{
		error("',' expected");
	}
	int n = int(expression());
	t = ts.get();
	if (t.kind == ')')
	{
		return pow(x, n);
	}
	else
	{
		error("Expected ')'");
	}
	}
	case name:
	{
		return get_value(t.name);
	}
	default:
	{
		error("primary expected");
		return 0.0; //Hianyzo sor
	}
	}
}

double term()
{
	double left = primary();
	while (true)
	{
	Token t = ts.get();
	switch (t.kind)
	{
	case 'k':		//Drill 6.) Add a predefined name k meaning 1000.
	{
	left *= 1000;
	break;
	}
	case '*':
	{
	left *= primary();
	break;
	}
	case '/':
	{
	double d = primary();
	if (d == 0) error("divide by zero");
	left /= d;
	break;
	}
	default:
	{
	ts.unget(t);
	return left;
	}
}
}
}

double expression()
{
	double left = term();
	while (true)
	{
		Token t = ts.get();
		switch (t.kind)
		{
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}


	double declaration()
	{
		Token t = ts.get();
		if (t.kind != 'name') error("name expected in declaration"); //ERROR if (t.kind != 'a')
		string name = t.name;
		if (is_declared(name)) error(name, " declared twice");
		Token t2 = ts.get();
		if (t2.kind != '=') error("= missing in declaration of ", name);
		double d = expression();
		names.push_back(Variable(name, d));
		return d;
	}

	double statement()
	{
		Token t = ts.get();
		switch (t.kind)
		{
		case let:
			return declaration();
		default:
			ts.unget(t);
			return expression();
		}
	}

	void clean_up_mess()
	{
		ts.ignore(print);
	}

	const string prompt = "> ";
	const string result = "= ";

void calculate()
{
	while (true) try
	{
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print)
		{
			t = ts.get();
		}
		if (t.kind == exitprog) return;
		
		ts.unget(t);
		cout << result << statement() << endl;
	}
		catch (runtime_error& e)
		{
			cerr << e.what() << endl;
		clean_up_mess();
		}
}

int main()
{
try
{
	calculate();
	return 0;
}
catch (exception& e)
{
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c&& c != ';');
	return 1;
}
catch (...)
{
cerr << "exception\n";
char c;
while (cin >> c && c != ';');
return 2;
}
}
