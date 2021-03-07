#include "Tester.h"

const string Tester::TextSample = "TEXT_EXAMPLE";
int Tester::NumRuns = 0;
int Tester::MaxRuns = 0;

string* Tester::GetStringArray(int* n)
{
	if (NumRuns >= MaxRuns)
	{
		*n = 0;
		return NULL;
	}

	string* s_arr = new string[MAX_STRS_QUEUE];
	int num_strings = std::rand() % MAX_STRS_QUEUE + 1; // 1 to MAX_STRS strings

	for(int i=0;i<num_strings;i++)
	{
		string s = "R" + to_string(NumRuns) + "_S" + to_string(i+1);
		s = s + " : " + TextSample;
		s_arr[i] = s;
	}

	*n = num_strings;
	NumRuns++;

	return s_arr;
}

void Tester::DestroyStringArray(string* s_arr)
{

	if (s_arr != NULL)
	{
		delete[] s_arr;
	}
}

void Tester::SetNumberOfRuns(int run)
{
	MaxRuns = run;
}
