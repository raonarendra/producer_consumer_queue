#ifndef __STRING_QUEUE_H__
#define __STRING_QUEUE_H__

#include <string>
#include <queue>
#include <condition_variable>
#include <mutex>

using namespace std;

// min 3
#define MAX_STRS_QUEUE 5

class StringQueue
{
private:
	queue<string> mBuffer;
	const unsigned int mSize = MAX_STRS_QUEUE - 2;
	condition_variable mCond;
	mutex mMutex;

public:
	/**
	* Constructor for StringQueue.
	*/
	StringQueue();

	/**
	* Destructor for StringQueue.
	*/
	~StringQueue();

	/**
	* Add a string to queue at head.
	*/
	void add(string s);

	/**
	* Add string array to queue.
	*/
	void add(string *s, int size);

	/**
	* Get string at the head of queue.
	*/
	string remove();
};

#endif // __STRING_QUEUE_H__