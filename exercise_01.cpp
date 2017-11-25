#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

vector<float> sense(vector<float> p, string Z, int run);

vector<float> move(vector<float> p, int U, int run);

vector<float> normalize(vector<float> p);

void printP(vector<float> p);

int main()
{
  vector<float> p(5, 0.2);
  vector<string> measurements{"red", "green"};
  vector<int> motions{1, 1};

  for (int i = 0; i < measurements.size(); i++)
  {
    p = sense(p, measurements[i], i);
    p = move(p, motions[i], i);
  }

  printP(p);

  return 0;
  }

  vector<float> sense(vector<float> p, string Z, int run)
  {
    vector<string> world{"green", "red", "red", "green", "green"};
    float pHit = 0.6;
    float pMiss = 0.2;
    vector<float> q;

    for (int i = 0; i < p.size(); i++)
    {
      bool hit = Z == world[i];
      q.push_back(p[i] * (hit * pHit + (1 - hit) * pMiss));
    }

    q = normalize(q);

    return q;
  }

  vector<float> move(vector<float> p, int U, int run)
  {
    float pExact = 0.8;
    float pOvershoot = 0.1;
    float pUndershoot = 0.1;
    vector<float> q;

    for (int i = 0; i < p.size(); i++)
    {
      int position = (p.size() - U + i);
      float s = pExact * p[position % p.size()];
      s = s + pOvershoot * p[(position - 1) % p.size()];
      s = s + pUndershoot * p[(position + 1) % p.size()];
      q.push_back(s);
    }

    return q;
  }

  vector<float> normalize(vector<float> p)
  {
    vector<float> q;
    float sum = accumulate(p.begin(), p.end(), 0.0f);
    for (int i = 0; i < p.size(); i++) {
      q.push_back(p[i] / sum);
    }
    return q;
  }

  void printP(vector<float> p)
  {
    for (int i = 0; i < p.size(); i++)
    {
      cout << p[i] << " ";
    }
    cout << endl;
  }