#include <cmath>
#include <iostream>
using namespace std;

int binToDec(int binSkill) {
    int decSkill = 0;
    for (int i = 0; binSkill; ++i) {
        if (binSkill % 10)
            decSkill += pow(2, i);
        binSkill /= 10;
    }
    return decSkill;
}

int powersOfTwo(int num) {
    int numPower = 0;
    while(num) {
        int maxPower = log2(num);
        num -= pow(2, maxPower);
        ++numPower;
    }
    return numPower;
}

void maxSkillInTeam(int skills[], int N) {
    int maxSkills = 0;
    int numMaxSkills = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int teamSkill = skills[i] | skills[j];
            if (teamSkill > maxSkills) {
                maxSkills = teamSkill;
                numMaxSkills = 1;
            } else if (teamSkill == maxSkills) {
                ++numMaxSkills;
            }
        }
    }
    cout << powersOfTwo(maxSkills) << endl << numMaxSkills << endl;
}

int main() {
    int N, M;
    cin >> N >> M;
    int skills[N];
    for (int i = 0; i < N; ++i) {
        int skill;
        cin >> skill;
        skills[i] = binToDec(skill);
    }
    maxSkillInTeam(skills, N);
    return 0;
}
