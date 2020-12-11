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

//Our BST
Node *treeRoot = new Node;

//Mutex used for thread synchronization
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

// Generate 100 numbers between 0 and 100000 and insert to binary search tree
void *threadFunction(void *dummyPtr)
{
  pthread_mutex_lock( &mutex1 );
  printf("Thread number %ld\n",pthread_self());
  int randNum;
  // Generate 100 random numbers and insert to the tree
  for (int i = 0; i < 100; i++)
  {
  randNum = rand() % 100000;
  // Insert to the tree??

  bstInsert(treeRoot,randNum);
  }
  pthread_mutex_unlock( &mutex1 );
  return NULL;
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
  //Return value as an int
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

  //Convert command line argument to integer
  int threadCount = changeToInt(argv[1]);
  pthread_t thread_id[threadCount];

  cout << "Creating specified amount of Threads: " << threadCount << endl;

  if (pthread_mutex_init(&mutex1, NULL) != 0) {
      perror("Mutex");
      exit(-1);
      }

  //Create each thread
  for (int i=0; i < threadCount; i++)
  {
    if (pthread_create(&thread_id[i],NULL,threadFunction,NULL) !=0)
      {
        perror("pthread_create");
        exit(-1);
      }
  }
  //Join each thread???
  for (int i = 0; i < threadCount; i++)
  {
    if (pthread_join(thread_id[i], NULL) != 0)
    {
		    perror("pthread_join");
		    exit(-1);
	  }
  }

  cout << "Printing tree in order!"<< endl;
  inorder(treeRoot);

  cout << "Destroying mutex..." << endl;
  pthread_mutex_destroy (&mutex1);

  return 0;
}
