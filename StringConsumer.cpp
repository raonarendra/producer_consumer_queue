#include "StringConsumer.h"

#include "logger.h"

StringConsumer::StringConsumer(StringQueue* buffer)
{
	this->mBuffer = buffer;
	this->mRun = true;
}

StringConsumer::~StringConsumer()
{
}

void StringConsumer::SetThreadRunning(bool run)
{
	mRun = run;
}

void StringConsumer::run()
{
	while (mRun) {
		// wait for a string to be available and then remove it.
		string s = mBuffer->remove();
		LOGGER->Log("[%s] PROCESS String %s", typeid(this).name(), s.c_str());

		// Do whatever with the string
		// <code to send string to server>

		//this_thread::sleep_for(chrono::milliseconds(1000));
	}
}
