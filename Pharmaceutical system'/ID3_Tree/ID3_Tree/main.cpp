#include "stdafx.h"
#include <iostream>  
#include "ID3.h"  
#include <fstream>

using namespace std;

enum outlook { first, third, second };  //枚举名、变量
enum temp { A, B, C };
enum hum { NORMAL, HIGH };
enum windy { NO, YES };

int samples[14][4] =
{
	{ first   ,       A ,      NORMAL  ,       NO },
	{ first   ,       A ,      NORMAL  ,       YES },
	{ third,       A ,      NORMAL  ,       NO },
	{ second    ,       B,      NORMAL  ,       NO },
	{ second    ,       C,      HIGH,       NO },
	{ second    ,       C,      HIGH,       YES },
	{ third,       C,      HIGH,       YES },
	{ first   ,       B,      NORMAL  ,       NO },
	{ first   ,       C,      HIGH,       NO },
	{ second    ,       B,      HIGH,       NO },
	{ first   ,       B,      HIGH,       YES },
	{ third,       B,      HIGH  ,       YES },
	{ third,       A ,      NORMAL,       NO },
	{ second    ,       B,      HIGH  ,       YES }
};

int main()
{
	ID3 Tree(4);
	Tree.PushData((int *)&samples[0], 0);
	Tree.PushData((int *)&samples[1], 0);
	Tree.PushData((int *)&samples[2], 1);
	Tree.PushData((int *)&samples[3], 1);
	Tree.PushData((int *)&samples[4], 1);
	Tree.PushData((int *)&samples[5], 0);
	Tree.PushData((int *)&samples[6], 1);
	Tree.PushData((int *)&samples[7], 0);
	Tree.PushData((int *)&samples[8], 1);
	Tree.PushData((int *)&samples[9], 1);
	Tree.PushData((int *)&samples[10], 1);
	Tree.PushData((int *)&samples[11], 1);
	Tree.PushData((int *)&samples[12], 1);
	Tree.PushData((int *)&samples[13], 0);

	Tree.Build();
	Tree.Print();
	cout << endl;
	ofstream outfile;
	outfile.open("123.txt", ios::app);
	for (int i = 0; i < 14; ++i)

	{
		outfile << "predict value :    " << Tree.Match((int *)&samples[i]) << endl;
	}
	outfile.close();


	return 0;
}




//int main(int argc, char** argv) {
//    ofstream outfile;
//    outfile.open("4322223.txt");
//    outfile<<"是是是对对对\n";
//    outfile.close();
//    return 0;
//}
