#include<string>
#include<vector>
#include<utility>
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
    std::vector<std::pair<std::string,Song*>> playlists;
public:
    void makePlayList(const std::string& listName,std::initializer_list<std::string> songs) {
        Song dummy("-");
        Song* runner=&dummy;
        for(std::string song:songs) {
            runner->next=new Song(song);
            runner=runner->next;
        }
        playlists.push_back({listName,dummy.next});
    }
    void play(const std::string& listName) {
        Song* head=nullptr;
        for(std::pair<std::string,Song*> playlist:playlists)
            if(playlist.first==listName) { head=playlist.second; break; }
        if(!head) throw std::runtime_error("Playlist Not Found!");
        else {
            std::string command="mpv --no-video \"songs/"+listName+"/"+head->songName+"\" &";
            system(command.c_str());
        }
    }
    void stop() { system("killall mpv"); }
    ~Musify() {
        while(!playlists.empty()) {
            Song* current=playlists.back().second;
            while(current) {
                Song* target=current;
                current=current->next;
                delete target;
            }
            playlists.pop_back();
        }
    }
};