#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <thread>
using namespace std;
int main() {
	long times = 500000000;
	measure([times]() {           //双线程
		long ans1 = 0, ans2 = 0;
		std:：thread t1 = thread(NumberAdd, 0, times / 2, ref(ans1));
		std:：thread t2 = thread(NumberAdd, times / 2, times, ref(ans2));
		t1.join();
		t2.join();
		cout << "result of two treads: " << ans1 + ans2 << endl;
		}
	);
	
	measure([times]() {           //单线程
		long ans = 0;
		NumberAdd(0, times, ans);
		cout << "result of single treads: " << ans<< endl;
		}
	);
}
void NumberAdd(long start, long end, long &ans) {
	int sum = 0;
	for (long i = start; i < end; i++) 
		sum = sum + 1;
	ans = sum;
}


