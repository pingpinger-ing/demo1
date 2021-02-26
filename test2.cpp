#include <iostream> 
#include <vector> 
#include <thread> 
#include <future> 
#include <condition_variable>
#include <mutex> #include <chrono> 
#include <ctime> #include <algorithm> 
using namespace std;
const long long N = 900000000; 
mutex m; 
long long run(long long from, long long to) 
{ 
  long long ret = 0; 
 for (long long i = from+1; i <= to; i++) 
 { ret += i; } 
 cout <<"thread ID："<< this_thread::get_id() <<", ret="<<ret<< endl; return ret; 
} 

int main() 
{ int n; 
 long long sum = 0; 
 cout << "CPU number : " << thread::hardware_concurrency() << endl; cout << "Please enter the number of threads used: "; cin >> n; //计时 
 auto start = std::chrono::system_clock::now(); 
 vector<future<long long>> result; 
 std::time_t start_time = std::chrono::system_clock::to_time_t(start); 
 cout << "start time: " << std::ctime(&start_time); 
 for(long long i = 0; i < n; ++i)
 {
   result.push_back(async(run, i*N/n, (i+1)*N/n)); 
 } 
 for(long long i = 0; i < n; ++i)
 { 
   sum += result[i].get(); 
 } 
 auto end = std::chrono::system_clock::now(); 
 std::chrono::duration<double> elapsed_seconds = end-start;
 std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 cout << "sum = " << sum << endl; cout << "end time: " << std::ctime(&end_time); cout << "time cost: " << elapsed_seconds.count() << "s" << endl; return 0; 
}
