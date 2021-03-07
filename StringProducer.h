#ifndef __STRING_PRODUCER_H__
#define __STRING_PRODUCER_H__
#include "StringQueue.h"

using namespace std;

class StringProducer
{
public:
	/**
	* Contructor for StringProducer.
	*/
	StringProducer(StringQueue* buffer);

	/**
	* Destructor for StringProducer.
	*/
	~StringProducer();

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

#endif // __STRING_PRODUCER_H__
