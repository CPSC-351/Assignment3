/*
Assignment 3

use g++
*/


#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "bst.h"

using namespace std;

Node *treeRoot = new Node;

// Generate 100 numbers between 0 and 100000 and insert to binary search tree
void *threadFunction(void *dummyPtr)
{

  int randNum;
  // Generate 100 random numbers and insert to the tree
  for (int i = 0; i < 100; i++)
  {
  randNum = rand() % 100000;
  // Insert to the tree??
  cout << "Inserting rangom number to bst: " << randNum << endl;
  bstInsert(treeRoot,randNum);
  }

}

// Change command line argument
int changeToInt(char* threadCount)
{
  //Check that the content is an integer
  if (atoi(threadCount) == 0)
    {
      cout << "Please enter an integer number." << endl;
      exit(-1);
    }
  else
  return (atoi(threadCount));

}

int main(int argc, char** argv)
{
  /* Check the command line arguments */
  if(argc < 2)
  {
    fprintf(stderr, "USAGE: %s <number>\n", argv[0]);
    exit(-1);
  }

  int threadCount = changeToInt(argv[1]);
  pthread_t thread_id[threadCount];

  cout << "Creating specified amount of Threads: " << threadCount << endl;

  //Create each thread
  for (int i=0; i < threadCount; i++)
  {
    pthread_create(&thread_id[i],NULL,threadFunction,NULL);
  }
  //Join each thread???
  for (int i = 0; i < threadCount; i++)
  {
    pthread_join(thread_id[i], NULL);
  }

  return 0;
}
/*
main()
{
   pthread_t thread_id[NTHREADS];
   int i, j;

   for(i=0; i < NTHREADS; i++)
   {
      pthread_create( &thread_id[i], NULL, thread_function, NULL );
   }

   for(j=0; j < NTHREADS; j++)
   {
      pthread_join( thread_id[j], NULL);
   }

   / Now that all threads are complete I can print the final result.     /
   / Without the join I could be printing a value before all the threads /
   / have been completed.

   printf("Final counter value: %d\n", counter);
}

void *thread_function(void *dummyPtr)
{
   printf("Thread number %ld\n", pthread_self());
   pthread_mutex_lock( &mutex1 );
   counter++;
   pthread_mutex_unlock( &mutex1 );
} '''

*/
