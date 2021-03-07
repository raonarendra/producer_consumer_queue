#pragma once
#include "StringQueue.h"

class Tester
{
public:
	static string* GetStringArray(int *n);
	static void DestroyStringArray(string* s_arr);
	static void SetNumberOfRuns(int run);

//private:
	static const string TextSample;
	static int MaxRuns;
	static int NumRuns;
};

