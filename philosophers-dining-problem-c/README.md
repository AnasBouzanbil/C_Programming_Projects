

</p>
<p align="center">
<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FmgC5H%2FbtrB4db7asB%2FIYl8ydAMbC5YQ1JXkxKfMK%2Fimg.png" width="250">

<p/>

# Project Info
The Philosophers' Dining Problem is a classic problem in computer science and concurrency control that deals with coordination between multiple processes or threads. It was first introduced by Edsger Dijkstra in 1965.
In the problem, there are n philosophers sitting around a table, each with their own plate and fork. The philosophers alternate between thinking and eating, and they need to use two forks to eat. The problem is to ensure that each philosopher can eat without getting into a deadlock or a starvation situation.
##

 
Imagine five philosophers sitting at a circular table with a bowl of rice and chopsticks. Each philosopher is very hungry and wants to eat, but they only have one chopstick each. To eat, they need to pick up the chopstick on their left and the chopstick on their right. But here's the catch: the chopsticks are shared between two philosophers, and they cannot eat if their neighboring philosopher is already using the chopstick they need.

Now, your task as a 42' student is to come up with a solution that allows all the philosophers to eat without getting stuck in a deadlock or starving to death. It's like a game of musical chairs, but with chopsticks and philosophers instead!
##
## FAQ

#### what is Deadlock
</p>
<p align="center">
<img src="https://github.com/Elhazin/PNG/blob/main/Screen%20Shot%202023-05-01%20at%207.56.37%20PM.png" width="500">

<p/>
A deadlock is a state in computer programming where two or more processes are blocked and unable to continue executing because each process is waiting for the other to release a resource that it holds. This creates a situation where both processes are stuck and can no longer make progress, resulting in a "deadlock" where neither process can proceed. This can lead to a system hang, causing the affected processes and potentially the entire system to become unresponsive. Deadlocks can occur in multi-process or multi-threaded systems, and are a common synchronization problem in computer science.


#### What is Datarace ?
</p>
<p align="center">
<img src="https://www.installsetupconfig.com/win32programming/threadprocesssynchronizationapis11_files/winthreadprocesssynchronizationcode018.png" width="500">

<p/>
A data race is a condition in computer programming where multiple threads attempt to access and modify a shared piece of data concurrently, leading to unpredictable results. It occurs when the execution order of operations on the shared data is not well defined, leading to a race between the threads to access and modify the same memory location. This can result in data inconsistencies, errors, and crashes, making data races a major concern in multithreaded programming.


#### What is thread ?

A thread in C can be thought of as a tiny, independent piece of a puzzle that helps to complete a larger picture. Think of a puzzle with multiple pieces, each piece represents a thread and each thread is unique in its own way, contributing to the overall solution. Just like a puzzle piece, a thread performs a specific task and works in harmony with other threads to complete the program efficiently.

#### what is Mutex

 A mutex (short for mutual exclusion) is a synchronization primitive that is used to protect shared resources from concurrent access by multiple threads.
## Acknowledgements

 - [Intro to threads](https://www.youtube.com/watch?v=ldJ8WGZVXZk)
 - [Thread functions in C](https://www.geeksforgeeks.org/thread-functions-in-c-c/)
 - [Mutex lock for Linux Thread Synchronization](https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/)

## Authors

- [@Elhazin](https://www.github.com/Elhazin)


## Functions

| function  | Description                |
| :-------- | :------------------------- |
| `pthread_create()` | this function takes four arguments is used to create the thread |
| `pthread__mutex_lock()` | this function is used to acquire a lock on a mutex object |
| `pthread__mutex_init()` |this function   is used to initialize a mutex object before it can be used for synchronization |
| `pthread_mutex_unlock()` |  this function is used to release a lock on a mutex object that was previously acquired using pthread_mutex_lock.|


## how to create thread

let us create an example of how we can create a thread in C 
```c
void* function(void* str) {
    printf("Our Thread is created!\n");
    return (NULL);
}

int main() {
  pthread_t thread_id;
  int ret;

  ret  = pthread_create(&thread_id NULL, function, NULL);
  if (ret != 0) {
      printf("thread creation is failed with error {%d}\n", ret);
      return (1);
  }   
  pthread_join(my_thread, NULL);    
    return (0);
}
```
      and now we have created our thread


## Feedback

If you have any feedback, please reach out to me at [Elhazin#9704] on Discord 



</p>
<p align="center">
<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FccOHbk%2FbtrmXuGtLet%2FJzUaL05K8W5AgwZqFkKjC0%2Fimg.png" width="500">

<p/>
