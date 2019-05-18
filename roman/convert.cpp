// Sam Rowe 
// Simple program to convert numbers and roman numerals
// 17.5.19

#include<iostream>
#include<string>
#include<cmath>

using namespace std;

static void useage(string arg)
{
	cerr
	<< "Usage: " << arg << " <option> NUMBER\n"
	<< "Options:\n"
	<< "\t-h --help\tShow this message\n"
	<< "\t-e --encode\tEncode decimal as roman numeral\n"
	<< "\t-d --decode\tDecode roman numeral as decimal\n"
	<< endl;
}

int main(int argc, char* argv[])
{

if (argc < 3) { // if incorrect arg amount
	cout << "Incorrect number of arguments :-\n" << endl; 
	useage(argv[0]); // passes executable name into useage()
	return 1;
}

string roman = ""; // input if -d, output if -e
long int decimal = 0; // see above
bool decode; // set if decode flag is set

string arg = argv[1];

if ((arg == "-h")||(arg =="--help"))
{
	useage(argv[0]);
	return 1;
}
else if ((arg == "-e")||(arg == "--encode"))
{
	decimal = atoi(argv[2]);
	decode = false;
}
else if ((arg == "-d")||(arg == "--decode"))
{
	roman = argv[2];
	decode = true;
}
else {
	cerr << "Error - incorrect useage" << endl;
	useage(argv[0]);
	return 1;
}

if (!decode)
{

/* filters the number through roman numeral denominations using if statements,
 * extracting the value
 * 
 * there is probably a more efficient way of doing this, however:-
 * lookup tables seem clunky
 * unique data types cause more problems than they solve,
 */
	if ( decimal <=0)
	{
		cerr << "invalid value, must be a positive integer" << endl;
		cout << "0" << endl;
		return 1;
	}

	if ( decimal >= 1000)
	{
		int M = floor(decimal/1000);
		decimal = decimal%1000;

		for (int i=0; i<M; i++)
		{
			roman+="M";
		}
	}

	if( decimal >=900 )
	{
		decimal=decimal%900;
		roman+="CM";
	}
	else

	if( decimal  >=500 )
	{
		decimal=decimal%500;
		roman+="D";
	}
	else

	if ( decimal >=400 )
	{
		decimal=decimal%400;
		roman+="CD";
	}

	if ( decimal >= 100 )
	{
		int C = floor(decimal/100);
		decimal=decimal%100;

		for (int i=0; i<C; i++)
		{
			roman+="C";
		}
	}

	if ( decimal >= 90 )
	{
		decimal=decimal%90;
		roman+="XC";
	}
	else

	if ( decimal >= 50 )
	{
		decimal=decimal%50;
		roman+="L";
	}
	else
 
	if( decimal >= 40 )
	{
		decimal=decimal%40;
		roman+="XL";
	}
	
	if ( decimal >=10 )
	{
		int X = floor(decimal/10);
		decimal=decimal%10;
		
		for (int i=0; i<X; i++)
		{
		roman+="X";
		}
	}
	if ( decimal >= 9 )
	{
		decimal=decimal%9;
		roman+="IX";
	}
	else

	if ( decimal >= 5 )
	{
		decimal=decimal%5;
		roman+="V";
	}
	else 

	if ( decimal >= 4 )
	{
		decimal=0;
		roman+="IV";
	}
	
	if ( decimal > 0 )
	{
		for (int i=0; i < decimal; i++)
		{
			roman+="I";
		}
	}


// error handling
	if (roman == "")
	{
		cerr << "The number was not encoded" << endl;
		return 1;
	}

// output
	cout << roman << endl;
	return 0;

}

else // Decode
{
cout <<  "Coming soon!" << endl;
//plan
	//case similar to above
	//if substring[0] = M
	//thousand
	//remove M
	//if substring[0] = C
		//if substring[1]= M
		// 900
		// else substring[1]=D
		// 400
		// else 
		//100
	//if subs = D
	//500
	//et cetera
}
}	
