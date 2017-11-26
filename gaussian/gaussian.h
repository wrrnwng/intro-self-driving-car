class Gaussian
{
private:
  float mu, sigma2;

public:
  Gaussian();
  Gaussian(float, float);

  void setMu(float);
  void setSigma2(float);

  float getMu();
  float getSigma2();

  float evaluate(float);
  Gaussian multiply(Gaussian);
  Gaussian add(Gaussian);
};
