#include<iostream>
#include"Musify.h"
using namespace std;

// Main Function
int main() {
    Musify m;
    m.makePlayList({"song1.mp3"});
    string firstSong="song1.mp3";
    m.play(firstSong);
    return 0;
}