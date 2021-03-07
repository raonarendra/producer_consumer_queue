#include "StringProducer.h"

#include "logger.h"
#include "Tester.h"

StringProducer::StringProducer(StringQueue* buffer)
{
	this->mBuffer = buffer;
	this->mRun = true;
}

StringProducer::~StringProducer()
{

}

void StringProducer::SetThreadRunning(bool run)
{
	mRun = run;
}

void StringProducer::run()
{
	while (mRun) {
		int n;
		string *s_arr = Tester::GetStringArray(&n);
		if (s_arr != NULL && n > 0)
		{
			LOGGER->Log("[%s] Produced %d strings.", typeid(this).name(), n);
			mBuffer->add(s_arr, n);
		}
		else
		{
			break;;
		}

		Tester::DestroyStringArray(s_arr);

		LOGGER->Log("[%s] Producer loop. MaxRuns: %d, Current Run: %d", typeid(this).name(),
			Tester::MaxRuns, Tester::NumRuns);

		//this_thread::sleep_for(chrono::milliseconds(5000));
	}

	LOGGER->Log("[%s] Producer Exited.", typeid(this).name());
}
