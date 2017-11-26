#include <iostream>
#include "gaussian.h"

using namespace std;

int main() {
  Gaussian mygaussian(30.0, 20.0);
  Gaussian othergaussian(10.0, 30.0);

  cout << "average " << mygaussian.getMu() << endl;
  cout << "evaluation " << mygaussian.evaluate(15.0) << endl;

  Gaussian product = mygaussian.multiply(othergaussian);
  cout << "mul results sigma " << product.getSigma2() << endl;
  cout << "mul results average " << product.getMu() << endl;

  Gaussian sum = mygaussian.add(othergaussian);
  cout << "add results sigma " << sum.getSigma2() << endl;
  cout << "add results average " << sum.getMu() << endl;

  return 0;
}