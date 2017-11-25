#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

typedef vector<vector<double>> matrix;

matrix transpose(matrix m);

double dot_product(vector<double> m1, vector<double> m2);

matrix multiply(matrix m1, matrix m2);

void print_matrix(matrix m);

int main()
{
  vector<double> v1{1, 2, 3};
  vector<double> v2{4, 5, 6};
  vector<double> v3{7, 8, 9};
  matrix m1{v1, v2};
  matrix m2{v1, v3};
  matrix m3 = transpose(m2);
  print_matrix(multiply(m1, m3));
}

matrix transpose(matrix m)
{
  matrix new_matrix;
  for (int j = 0; j < m[0].size(); j++)
  {
    vector<double> new_row;
    for (int i = 0; i < m.size(); i++)
    {
      new_row.push_back(m[i][j]);
    }
    new_matrix.push_back(new_row);
  }
  return new_matrix;
}

double dot_product(vector<double> v1, vector<double> v2)
{
  double sum = 0;
  for (int i = 0; i < v1.size(); i++)
  {
    sum += v1[i] * v2[i];
  }
  return sum;
}

matrix multiply(matrix m1, matrix m2)
{
  if (m1[0].size() != m2.size())
  {
    throw invalid_argument("matrix 1 columns must match matrix 2 rows");
  }
  matrix product;
  matrix m2_T = transpose(m2);
  for (int i = 0; i < m1.size(); i++)
  {
    vector<double> new_row;
    for (int j = 0; j < m2_T.size(); j++)
    {
      new_row.push_back(dot_product(m1[i], m2_T[j]));
    }
    product.push_back(new_row);
  }
  return product;
}

void print_matrix(matrix m)
{
  for (int i = 0; i < m.size(); i++)
  {
    for (int j = 0; j < m[0].size(); j++)
    {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
}