#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

class QuickFindUF
{
  private:
     int *id;
     int *sz;

   public:
     QuickFindUF(int N);
     ~QuickFindUF();

     //Eager Approach
     bool isConnectedEA(int p, int q);
     void unionQfEA(int N, int p, int q);
     void quickFind_EagerApproach(int N);


     //Lazy Approach - with weights
     int root(int i);
     bool isConnectedLA(int p, int q);
     void unionQfLA(int N, int p, int q);
     void quickFind_Weighted(int N);

     void printUnion(int N);

};

QuickFindUF::QuickFindUF(int N)
{
  id = new int[N];
  sz = new int[N];

  for(int i =0 ; i < N; i++)
  {
    id[i] = i;
    sz[i] = 1;
  }
}

QuickFindUF::~QuickFindUF()
{
  if(id != NULL)
  {
    delete[] id;
    id = NULL;
  }
}

bool QuickFindUF::isConnectedEA(int p, int q)
{
  return (id[p] == id[q]);
}

/*
  atmost 2N + 2 array accesses

  no of array accesses  =
  initialize - N
  union - N
  find - 1 (constant)
*/
void QuickFindUF::unionQfEA(int N, int p, int q)
{
  int pid = id[p];
  int qid = id[q];

  for(int i = 0 ; i < N; i++)
  {
    if(id[i] == pid)
    {
      id[i] = qid;
    }
  }
}

void QuickFindUF::printUnion(int N)
{
  for(int i = 0 ; i < N; i++)
  {
    printf("\t[%d]: %d ", i, id[i]);
  }
  printf("\n");
}

void QuickFindUF::quickFind_EagerApproach(int N)
{
  bool isConn = false;
  int p, q;

  std::fstream myfile("uf_input.txt", std::ios_base::in);

  printf("Inital Tree: ");
  printUnion(N);
  printf("\n");

  while (myfile >> p >> q)
  {
    printf("pair %d %d: ", p, q);
    isConn = isConnectedEA(p, q);
    if(isConn == false)
    {
      unionQfEA(N, p, q);
      printUnion(N);
      printf("\n");
    }
    else
    {
      printf("\t%d and %d are connected\n\n", p, q);
    }
  }
}

/*
chase parent pointers until we reach root
depth of i array accesses
*/
int QuickFindUF::root(int i)
{
  while(i != id[i])
  {
    i = id[i];
  }
  return i;
}

//check if p and q have same roots
bool QuickFindUF::isConnectedLA(int p, int q)
{
  return (root(p) == root(q));
}

/*
change root of p to point to root of q
extra array sz[] to count no of objects in the tree rooted at i
link root of smaller tree to root of larger tree
*/
void QuickFindUF::unionQfLA(int N, int p, int q)
{
  int i = root(p);
  int j = root(q);

  if(sz[i] < sz[j])
  {
    id[i] = j;
    sz[j] += sz[i];
  }
  else
  {
    id[j] = i;
    sz[i] += sz[j];
  }
}

void QuickFindUF::quickFind_Weighted(int N)
{
  bool isConn = false;
  int p, q;

  printf("Inital Tree: ");
  printUnion(N);
  printf("\n");

  //while(cin >> p >> q)
  std::fstream myfile("uf_input.txt", std::ios_base::in);
  while (myfile >> p >> q)
  {
    printf("pair %d %d: ", p, q);
    isConn = isConnectedLA(p, q);
    if(isConn == false)
    {
      unionQfLA(N, p, q);
      printUnion(N);
      printf("\n");
    }
    else
    {
      printf("\t%d and %d are connected\n\n", p, q);
    }
  }
}
int main()
{
  int N = 10;
  int opt;

  QuickFindUF *uf = new QuickFindUF(N);

  printf("Union Find Algorithms to try:\n");
  printf("\t 1. Quick Find Eager Approach\n");
  printf("\t 2. Quick Find Lazy Approach\n");
  printf("\nEnter your option: ");
  cin >> opt;

  switch(opt)
  {
    case 1:
    {
      uf->quickFind_EagerApproach(N);
      break;
    }
    case 2:
    {
      uf->quickFind_Weighted(N);
      break;
    }
    default:
    {
      printf("Invalid option, Better luck next time!!");
      break;
    }
  }

  return 0;
}
