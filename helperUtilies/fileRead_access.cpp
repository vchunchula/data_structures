#include <iostream>
#include <fstream>

using namespace std;

int main()
{

  int N = 24;
  int data[N], a;

#if 1
  std::fstream myfile("uf_input.txt", std::ios_base::in);
  while (myfile >> a)
  {
    std::cout<< a<<std::endl;
  }

  #else
  std::ifstream input("uf_input.txt");
  for (int i = 0; i < N; i++)
  {
    input >> data[i];
    std::cout<< data[i]<<std::endl;
  }
  #endif

}
