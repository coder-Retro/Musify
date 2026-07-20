#include<iostream>
#include"Musify.h"
using namespace std;

// Main Function
int main() {
    Musify m;
    string listName="List1";
    m.makePlayList("List1",{"song1.mp3"});
    m.play(listName);
    return 0;
}