#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
using namespace std;

bool isPossible(string game){
  map<string, int> colorCount = {
    {"red", 12},
    {"green", 13},
    {"blue", 14},
  };

  // this string stream consist of all the sets of the game
  istringstream eachGame(game);
  string set;

  while(getline(eachGame, set, ';')){
    // Each set is seperated by s ;, Hence we get here each set of current game 
    // cout<<"Current set of game is: "<<set<<endl;

    istringstream colors(set);

    string eachColor;
    while(getline(colors, eachColor, ',')){
      // each color is seperated by a comma, hence we get here each color of current set
      // cout<<eachColor<<" ";
      for(int idx=1;idx<eachColor.length();idx++){
        if(eachColor[idx]==' '){
          string count = eachColor.substr(0, idx+1);
          string color = eachColor.substr(idx+1);
          cout<<color<<" : "<<count<<endl;

          if(colorCount[color] < stoi(count)) return false;
        }
      }
    }
  }
  return true;
}

vector<int> possibleGames(vector<string> inputLines){
  vector<int> possibleGames;

  for(int i=0;i<inputLines.size();i++){
    string line = inputLines[i];

    int index = line.find(":");
    string game = line.substr(index+1, line.length()-index-1);

    if(isPossible(game)) possibleGames.push_back(i+1);
  }
  return possibleGames;
}

int power(string game){
  istringstream eachGame(game);
  string set;

  int power=1;
  map<string, int> minReq = {
    {"red", 0},
    {"green", 0},
    {"blue", 0},
  };

  while(getline(eachGame, set, ';')){
    istringstream colors(set);
    string eachColor;

    while(getline(colors, eachColor, ',')){

      for(int idx=1;idx<eachColor.length();idx++){
        if(eachColor[idx]==' '){
          string count = eachColor.substr(0, idx+1);
          string color = eachColor.substr(idx+1);
          cout<<color<<" : "<<count<<endl;

          minReq[color] = max(stoi(count), minReq[color]);
        }
      }
    }
  }
  for(auto it: minReq){
    power*=it.second;
  }
  return power;
}


vector<int> powers(vector<string> inputLines){
  vector<int> allPowers;

  for(int i=0;i<inputLines.size();i++){
    string line = inputLines[i];

    int index = line.find(":");
    string game = line.substr(index+1, line.length()-index-1);

    int pp = power(game);
    allPowers.push_back(pp);
  }
  return allPowers;
}

int main(){
  ifstream file("inputs/day2.txt");
  vector<string> inputLines;
  while(!file.eof()){
    string line;
    getline(file, line);
    inputLines.push_back(line);
  }

  // vector<int> games = possibleGames(inputLines);
  // int gameSum=0;
  // for(int game: games) gameSum+=game;
  // cout<<gameSum<<endl;

  vector<int> allPowers = powers(inputLines);
  int powerSum=0;
  for(int power: allPowers) powerSum+=power;
  cout<<powerSum<<endl;
}