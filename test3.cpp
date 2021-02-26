#include <iostream> 
#include <vector> 
#include <chrono> 
#include <ctime> 
#include <algorithm> 
#include <pthread.h> 
#include <unistd.h> 
using namespace std; 
const long long N = 90000000; 
typedef struct A{ 
  long long from;
  long long to; 
}
a_t, *pa_t; 
pthread_mutex_t mutex; 
void* run(void *arg) 
{ 
  pa_t at = (pa_t)arg;
  long long from = at->from, to = at->to; 
  pthread_mutex_unlock(&mutex); 
  long long ret = 0; 
  for (long long i = from+1; i <= to; i++) 
  { 
    ret += i; 
  } 
  return (void*)ret; 
} 
int main() 
{ 
  int n;
  cout << "CPU number : " << sysconf(_SC_NPROCESSORS_CONF) << endl; 
  cout << "Please enter the number of threads used: "; 
  cin >> n; 
  pthread_t pthid[n] = {0}; 
  pthread_mutex_init(&mutex, NULL); 
  long long from, to; 
  //计时 
  auto start = std::chrono::system_clock::now(); 
  std::time_t start_time = std::chrono::system_clock::to_time_t(start);
  cout << "start time: " << std::ctime(&start_time);
  for(int i = 0; i < n; ++i)
  { 
    pthread_mutex_lock(&mutex); 
    a_t arg; 
    arg.from = i*N/n; 
    arg.to = (i+1)*N/n; 
    pthread_create(&pthid[i], NULL, run, (void*)&arg);
  } 
  long long sum = 0; 
  void* ret; 
  for(int i = 0; i < n; ++i)
  { 
    pthread_join(pthid[i], &ret); 
    cout << "pthid = "<< pthid[i] << ", ret = " << (long long)ret << endl; 
    sum += (long long)ret; 
  } 
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start; 
  std::time_t end_time = std::chrono::system_clock::to_time_t(end); 
  cout << "sum = " << sum << endl; cout << "end time: " << std::ctime(&end_time); cout << "time cost: " << elapsed_seconds.count() << "s" << endl; return 0;
}
