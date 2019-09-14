#include <iostream>
#include <stdio.h>
using namespace std;

class QuickFindUF
{
  private:
     int *id;

   public:
     QuickFindUF(int N);
     ~QuickFindUF();
     bool isConnected(int p, int q);
     void unionQf(int N, int p, int q);
     void printUnion(int N);
};

QuickFindUF::QuickFindUF(int N)
{
  id = new int[N];

  for(int i =0 ; i < N; i++)
  {
    id[i] = i;
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

bool QuickFindUF::isConnected(int p, int q)
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
void QuickFindUF::unionQf(int N, int p, int q)
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
    printf("\t[%d]: %d\n", i, id[i]);
  }
}
int main()
{
  bool isConn = false;
  int N = 10;
  int p, q;
  QuickFindUF *uf = new QuickFindUF(N);
  uf->printUnion(N);
  while(cin >> p >> q)
  {
    isConn = uf->isConnected(p, q);
    if(isConn == false)
    {
      uf->unionQf(N, p, q);
      uf->printUnion(N);
    }
    else
    {
      printf("\t\t%d and %d are connected\n", p, q);
    }
  }

  return 0;
}
