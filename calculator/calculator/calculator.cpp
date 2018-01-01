// calculator.cpp : Defines the entry point for the console application.
//
//expression()包含term()包含primary()包含number()
/*
Expression:
term
expression+ -term

term:
primary
term * / % primary

primary:
number
(expression)

number:
floating number
*/

//从term（）起手，为expression+expression+。。。。   3+（3*5）     3是expression，+上3*5，3*是说明为term，返回的是个term 所以是expression+term。
#include "stdafx.h"

#include<iostream>
using namespace std;
double primary();//一定要先声明
double term();
double expression();
class Token {
public:
	Token()
	{

	}
	
	Token(char ch)
	{
		kind = ch;
		value = 0;
	}
	Token(char ch, double val) :kind(ch), value(val) {}
	char kind;
	double value;
};//对于3+5+7这里先命令primary取一个数字3返回到term()，，再用Token取一个+，这时term返回一个3给expression，+就被term吞了，所以expression再取就是个5。所以要用putback把+放回去
class Token_stream {

public:
	Token_stream()
	{
		buffer = 0;
		full = false;
	};//构造函数//
	Token get();
	void putback(Token t);
private:
	bool full;
	Token buffer;
};

Token Token_stream::get() {
		if (full)
		{
			full = false; return buffer;
		}
		char ch;
		cin >> ch;//？输入22，即使是22也是一个个读，这里得到一个以字符形式读入的2，发现是数字
		switch (ch) {
		case';':case'q':case'(':case')':case'+':case'-':
		case'*':case'/':
			return Token(ch);
		case'.':case'1':case'2':case'3':case'4':
		case'5':case'6':case'7':case'8':
		{cin.putback(ch);//将char的2再放回，
		double val;
		cin >> val;//再用double 类型读入22. char1字节，double8字节可以读22了
		return Token('8', val);
		}
		default:
			cerr << "bad token" << endl;
		}
	};
void Token_stream::putback(Token t)
{
	if (full)cerr << "wrong";
	buffer = t;
	full = true;
}




	Token_stream ts;
	double expression()//最底层
	{
		double left = term();
		Token t = ts.get();
		while (true)
		{
			switch (t.kind) {
			case'+':
			{left += term();
			t = ts.get();
			break;
			}
			case'-':
			{ left -= term();
			t = ts.get();
			break;
			}
			default:
				ts.putback(t);
				return left;
			}
		}
	}
	double term()//2层
	{
		double left =primary();
		Token t = ts.get();
		while (true)
		{
			switch (t.kind) {
			case'*':
			{ left *= primary();
			t = ts.get();
			break;
			}
			case'/':
			{double d = primary();
			if (d == 0)
				cout << "error:d";
			left /= d;
			t = ts.get();
			break;
			}
			default:
				ts.putback(t);
			return left;
			}
		}
	}
	double primary()//三层
	{
		Token t = ts.get();
		switch (t.kind) {
		case'(':
		{double d = expression();
		t = ts.get();
		//if (t.kind != '(')cerr << "w1rong" << endl;
		return d;
		}
		case'8':return t.value;
		//default:
			//cerr << "w2rong" << endl;
		}
	}
	int main()
	{
		cout << "please input the equation with the ';'to the end:" << endl;
		try {
			double val = 0;
			while (1)
				//cout << "=" << expression() << endl;
			{
				Token t = ts.get();
				if (t.kind == 'q')break;
				if (t.kind == ';')
				{
					cout << "=" << val << endl;
				}
				else
				{
					ts.putback(t);
					val = expression();
				}
			}
			
		}
		catch (exception& e) {
			cerr << e.what() << endl;
		
			return 1;
		}
		catch (...) {
			cerr << "exception" << endl;
			
			return 2;
		}
		return 0;
	}