#include "StringQueue.h"
#include <iostream>
#include "logger.h"

StringQueue::StringQueue()
{
}

StringQueue::~StringQueue()
{
}

void StringQueue::add(string s)
{
	unique_lock<mutex> locker(mMutex);

	// acquire lock using mutex & wait for queue to be have at least one free entry
	mCond.wait(locker, [this]() {return mBuffer.size() < mSize; });

	// add string to head of queue
	Logger::GetLogger()->Log("[%s] Added String %s", typeid(this).name(), s.c_str());
	mBuffer.push(s);

	// unlock
	locker.unlock();

	// notify waiting thread
	mCond.notify_all();
}

void StringQueue::add(string* s, int size)
{
	for (int i = 0; i < size; i++) {
		this->add(s[i]);
	}
}

string StringQueue::remove()
{
	unique_lock<mutex> locker(mMutex);

	// acquire lock using mutex & wait for queue to be have at least one string
	mCond.wait(locker, [this]() {return mBuffer.size() > 0; });

	// Read string and remove entry from queue
	string s = mBuffer.back();
	mBuffer.pop();
	Logger::GetLogger()->Log("[%s] Removed String %s", typeid(this).name(), s.c_str());

	// unlock
	locker.unlock();

	// Notify waiting threads
	mCond.notify_all();
	return s;
}
