#include<string>
#include<vector>
#include<cstdlib>
#include<stdexcept>
#include<unistd.h>

// Musify Class
class Musify {
private:
    struct Song {
        std::string songName;
        Song* next;
        Song(std::string songName): songName(songName), next(nullptr) {}
    };
    std::vector<Song*> playlists;
public:
    void makePlayList(std::initializer_list<std::string> songs) {
        Song dummy("-");
        Song* runner=&dummy;
        for(std::string song:songs) {
            runner->next=new Song(song);
            runner=runner->next;
        }
        playlists.push_back(dummy.next);
    }
    void play(const std::string& firstSong) {
        Song* head=nullptr;
        for(Song* start:playlists)
            if(start->songName==firstSong) { head=start; break; }
        if(!head) throw std::runtime_error("Playlist Not Found!");
        else {
            std::string command="mpv --no-video \"songs/" + head->songName + "\" &";
            system(command.c_str());
        }
    }
    void stop() { system("killall mpv"); }
    ~Musify() {
        while(!playlists.empty()) {
            Song* current=playlists.back();
            while(current) {
                Song* target=current;
                current=current->next;
                delete target;
            }
            playlists.pop_back();
        }
    }
};