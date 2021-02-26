#include <iostream> 
#include <chrono> 
#include <ctime> 
#define N 90000000 
using namespace std; 
int main()
{ 
	   long long sum = 0; 
	   auto start = std::chrono::system_clock::now(); 
	   std::time_t start_time = std::chrono::system_clock::to_time_t(start); 
	   cout << "start time: " << std::ctime(&start_time); 
	   for(long long i = 1; i <= N; ++i)
	   { 
		   sum += i; 
	   } 
	   auto end = std::chrono::system_clock::now(); 
	   std::chrono::duration<double> elapsed_seconds = end-start; 
	   std::time_t end_time = std::chrono::system_clock::to_time_t(end); 
	   cout << "sum = " << sum << endl; cout << "end time: " << std::ctime(&end_time); 
	   cout << "time cost: " << elapsed_seconds.count() << "s" << endl; return 0; 
	  }



