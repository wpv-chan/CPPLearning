//ex15_1_1
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <deque>

using namespace std;

class Player{
    char* name;
    double score;

public:
    Player() {
        score = 0;
    }
    void setName(char name[]) {
        int length = strlen(name);
        this -> name = new char[length];
        strcpy(this -> name, name);
    }
    void setScore(double score) {
        this -> score = score;
    }
    char* getName() {
        return name;
    }
    double getScore() {
        return score;
    }
    bool operator < (const Player& right) {
        return score < right.score;
    }
};

double process(deque<double> score) {
    double average;

    sort(score.begin(), score.end());
    score.erase(score.begin());
    score.erase(score.end());

    deque<double>::const_iterator i;
    for(i = score.begin(); i < score.end(); i++) {
        average += *i;
    }

    average /= score.size();
    return average;
}

void SortPlayer(vector<Player> player) {
    sort(player.begin(), player.end(), less<Player>());
}

void DisplayPlayer(vector<Player> player) {
    vector<Player>::iterator i;
    for(i = player.begin(); i < player.end(); i++) {
        cout<<"Name: "<<i -> getName()<<endl;
        cout<<"Score: "<<i -> getScore()<<endl;
        cout<<endl;
    }
}

int main() {
    char name[10];
    double score_each;
    Player player;
    vector<Player> vectorPlayer;
    deque<double> score;
    for(int j = 0; j < 5; j++) {
        cout<<"Pls input the "<<j+1<<" player's name: ";
        cin>>name;
        player.setName(name);
        for(int i = 0; i < 10; i++) {
            cout<<"Pls input the "<<i+1<<" first judge's score: ";
            cin>>score_each;
            score.push_back(score_each);
        }
        player.setScore(process(score));
        score.clear();
        vectorPlayer.push_back(player); 
    }

    SortPlayer(vectorPlayer);
    DisplayPlayer(vectorPlayer);
    return 0;
}