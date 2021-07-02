#include <bits/stdc++.h>
using namespace std;

void pursueYourDream();
bool breakThrough();
void workingHard();
void SUCCESS();

int main() {
    while(true) {
        try {
            pursueYourDream();
        }
        catch(exception mistakes) {
            workingHard();
            if(breakThrough()) {
                break;
            }
        }
    }
    SUCCESS();
    return 0;
}

