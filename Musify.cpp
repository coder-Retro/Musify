#include<iostream>
#include<string>
#include<cstdlib>
#include<unistd.h>
using namespace std;

// Struct Song
struct Song {
    string songName;
    Song* next;
    Song(string songName): songName(songName), next(nullptr) {}
};

// Musify Class
class Musify {
private:

public:
    void play(const string& song) {
        string com="mpv --no-video \"" + song + "\" &";
        system(com.c_str());
    }
};

// Main Function
int main() {
    play("song1.mp3");
    return 0;
}