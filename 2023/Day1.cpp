#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

int calibrationValues(vector<string> lines){
  int sum=0;

  for(int i=0; i<lines.size(); i++) {
    string line = lines[i];
    char firstDigit;
    char lastDigit;

    for (char ch : line) {
      if (isdigit(ch)) {
        firstDigit = ch;
        break;
      }
    }
    
    for (auto it = line.rbegin(); it != line.rend(); it++) {
      if (isdigit(*it)) {
        lastDigit = *it;
        break;
      }
    }

    int calibrationValue = (firstDigit - '0') * 10 + (lastDigit - '0');
    sum += calibrationValue;
  }
  return sum;
}

int calibrationValue2(vector<string> lines){
  int sum=0;
  vector<string> numbers = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  
  for(auto line: lines){
    int firstDigit = 0;
    int lastDigit = 0;

    for(int i=0;i<line.size();i++){
      string currDigit = "0";

      if (isdigit(line[i])) currDigit = line[i];

      for(int j=0;j<numbers.size();j++){
        if(i <= line.size()-numbers[j].size() && line.substr(i, numbers[j].size()) == numbers[j] ){
          currDigit = to_string(j+1);
          break;
        }
      }

      if(firstDigit == 0) firstDigit = stoi(currDigit);
      if(currDigit!="0") lastDigit = stoi(currDigit);
    }

    int calibrationValue = firstDigit*10 + lastDigit;

    sum += calibrationValue;
  }
  return sum;
}

int main(){
  ifstream file("inputs/day1.txt");
  vector<string> lines;
  string line;
  while(getline(file, line)){
    lines.push_back(line);
  }
  cout << calibrationValue2(lines) << endl;
  return 0;
}