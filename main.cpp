#include <iostream>
#include <thread>

#include "StringQueue.h"
#include "StringProducer.h"
#include "StringConsumer.h"

#include "Tester.h"

using namespace std;

int main() {
	StringQueue b;
	StringProducer p(&b);
	StringConsumer c(&b);

	// Set up tester
	Tester::SetNumberOfRuns(3);

	std::thread producer_thread(&StringProducer::run, &p);
	std::thread consumer_thread(&StringConsumer::run, &c);

	producer_thread.join();
	consumer_thread.join();

	getchar();
	return 0;
}