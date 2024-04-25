#include <iostream>

using namespace std;

int main() 
{

  string name, grade;
  double credit;

  double sumCredit = 0.0;
  double temp;
  double res = 0.0;
  for(int i = 0; i < 20; i++) 
  {
    cin >> name >> credit >> grade;
    if(grade == "P") continue;
    
    sumCredit += credit;
    if(grade == "F") continue;

    if(grade[0] == 'A') temp = 4;
    else if (grade[0] == 'B') temp = 3;
	else if (grade[0] == 'C') temp = 2;
    else temp = 1;

    if (grade[1] == '+') temp += 0.5;

    res += credit * temp;
  }

  cout << res / sumCredit;

  return 0;
}