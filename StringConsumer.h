#ifndef __STRING_CONSUMER_H__
#define __STRING_CONSUMER_H__

#include "StringQueue.h"

using namespace std;

class StringConsumer
{
public:
	/**
	* Contructor for StringConsumer.
	*/
	StringConsumer(StringQueue* buffer);

	/**
	* Destructor for StringConsumer.
	*/
	~StringConsumer();

	/**
	* Enable/Disbale thread run.
	*/
	void SetThreadRunning(bool run);

	/**
	* Thread function for Consumer.
	*/
	void run();

private:
	StringQueue* mBuffer;
	bool mRun;
};

#endif // __STRING_CONSUMER_H__

