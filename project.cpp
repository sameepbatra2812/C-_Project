#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Song {
private:
    string title;
    string artist;
    float  duration; 

public:
    
    Song() {
        title    = "Unknown";
        artist   = "Unknown";
        duration = 0.0;
    }

    
    Song(string t, string a, float d) {
        title    = t;
        artist   = a;
        duration = d;
    }

    
    Song(const Song& s) {
        title    = s.title;
        artist   = s.artist;
        duration = s.duration;
    }

    
    ~Song() {
       
    }

    
    string getTitle()    { return title;    }
    string getArtist()   { return artist;   }
    float  getDuration() { return duration; }


    void setTitle(string t)   { title  = t; }
    void setArtist(string a)  { artist = a; }

   
    bool operator==(Song& other) {
        return title == other.title;
    }

   
    friend ostream& operator<<(ostream& out, Song& s) {
        out << "  Title   : " << s.title    << "\n"
            << "  Artist  : " << s.artist   << "\n"
            << "  Duration: " << s.duration << " min\n";
        return out;
    }
};



class Playlist {
private:
    Song   songs[100]; 
    int    count;      
    string name;       

public:
 
    Playlist() {
        count = 0;
        name  = "My Playlist";
    }

    Playlist(string n) {
        count = 0;
        name  = n;
    }

 
    ~Playlist() {
        cout << "\n[Playlist \"" << name << "\" removed from memory]\n";
    }

    string getName()  { return name;  }
    int    getCount() { return count; }


    void addSong(Song s) {
        if (count >= 100) {
            cout << "Playlist is full!\n";
            return;
        }
       
        for (int i = 0; i < count; i++) {
            if (songs[i] == s) {
                cout << "Song already exists!\n";
                return;
            }
        }
        songs[count] = s;
        count++;
        cout << "Song added successfully!\n";
    }


    void displayAll() {
        if (count == 0) {
            cout << "Playlist is empty.\n";
            return;
        }
        cout << "\n===== Playlist: " << name << " =====\n";
        for (int i = 0; i < count; i++) {
            cout << "\n[" << i + 1 << "]\n";
            cout << songs[i]; 
        }
        cout << "==============================\n";
        cout << "Total songs: " << count << "\n";
    }

    void searchSong(string keyword) {
        bool found = false;
        cout << "\nSearch results for \"" << keyword << "\":\n";
        for (int i = 0; i < count; i++) {
            if (songs[i].getTitle() == keyword) {
                cout << songs[i];
                found = true;
            }
        }
        if (!found) cout << "No song found.\n";
    }

    void deleteSong(string title) {
        for (int i = 0; i < count; i++) {
            if (songs[i].getTitle() == title) {
                
                for (int j = i; j < count - 1; j++) {
                    songs[j] = songs[j + 1];
                }
                count--;
                cout << "Song deleted successfully!\n";
                return;
            }
        }
        cout << "Song not found.\n";
    }

 
    void renameSong(string oldTitle, string newTitle) {
        for (int i = 0; i < count; i++) {
            if (songs[i].getTitle() == oldTitle) {
                songs[i].setTitle(newTitle);
                cout << "Song renamed successfully!\n";
                return;
            }
        }
        cout << "Song not found.\n";
    }

    
    void saveToFile() {
        string filename = name + ".txt";
        ofstream file(filename);

        if (!file) {
            cout << "Error opening file!\n";
            return;
        }

        file << name << "\n";
        file << count << "\n";

        for (int i = 0; i < count; i++) {
            file << songs[i].getTitle()    << "\n";
            file << songs[i].getArtist()   << "\n";
            file << songs[i].getDuration() << "\n"; 
        }

        file.close();
        cout << "Playlist saved to \"" << filename << "\"\n";
    }

    void loadFromFile(string filename) {
        ifstream file(filename);

        if (!file) {
            cout << "Error opening file!\n";
            return;
        }

        getline(file, name);

       
        string countLine;
        getline(file, countLine);
        count = stoi(countLine);


        for (int i = 0; i < count; i++) {
            string t, a, dStr;
            getline(file, t);       
            getline(file, a);       
            getline(file, dStr);    
            float d = stof(dStr);   
            songs[i] = Song(t, a, d);
        }

        file.close();
        cout << "Playlist loaded from \"" << filename << "\"\n";
    }
};


int main() {
    Playlist pl("My Playlist");
    int choice;

    do {
        cout << "\n====== MUSIC PLAYLIST MANAGER ======\n";
        cout << "1. Add Song\n";
        cout << "2. Display All Songs\n";
        cout << "3. Search Song\n";
        cout << "4. Delete Song\n";
        cout << "5. Rename Song\n";
        cout << "6. Save Playlist to File\n";
        cout << "7. Load Playlist from File\n";
        cout << "0. Exit\n";
        cout << "=====================================\n";
        cout << "Enter choice: ";
        string choiceStr;
        getline(cin, choiceStr);
      
        try { choice = stoi(choiceStr); }
        catch (...) { choice = -1; }

        if (choice == 1) {
            string t, a;
            float  d;
            cout << "Enter title   : "; getline(cin, t);
            cout << "Enter artist  : "; getline(cin, a);
            string dStr;
            cout << "Enter duration: "; getline(cin, dStr);
            try { d = stof(dStr); } catch (...) { cout << "Invalid duration, setting to 0.\n"; d = 0.0f; }
            Song s(t, a, d);
            pl.addSong(s);
        }
        else if (choice == 2) {
            pl.displayAll();
        }
        else if (choice == 3) {
            string keyword;
            cout << "Enter title to search: ";
            getline(cin, keyword);
            pl.searchSong(keyword);
        }
        else if (choice == 4) {
            string title;
            cout << "Enter title to delete: ";
            getline(cin, title);
            pl.deleteSong(title);
        }
        else if (choice == 5) {
            string oldT, newT;
            cout << "Enter current title: "; getline(cin, oldT);
            cout << "Enter new title    : "; getline(cin, newT);
            pl.renameSong(oldT, newT);
        }
        else if (choice == 6) {
            pl.saveToFile();
        }
        else if (choice == 7) {
            string fname;
            cout << "Enter filename (e.g. My Playlist.txt): ";
            getline(cin, fname);
            pl.loadFromFile(fname);
        }
        else if (choice == 0) {
            cout << "Goodbye!\n";
        }
        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
