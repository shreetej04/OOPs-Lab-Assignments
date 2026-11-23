/*
Develop a program in C++ to create a database for an Online Music Management System containing the following information: Song Title, Song ID, Artist Name, Album Name, Genre (Pop/Rock/Classical/Jazz, etc.), Duration, Playlist / Category. Construct the database with suitable member functions. Make use of: Constructor, Default Constructor, Copy Constructor, and Destructor. Perform the following operations:
a) Add a new song record
b) Display song details
c) Play a song (increase play count/check availability if restricted)
d) Add to playlist / remove from playlist
e) View current song availability and play statistics
*/

#include <iostream>
#include <string>
using namespace std;

class Song
{
public:
    int songID;
    string title, artist, album, genre, playlist;
    float duration;
    int playCount;
    bool available;

    // Default Constructor
    Song()
    {
        songID = 0;
        title = "";
        artist = "";
        album = "";
        genre = "";
        playlist = "None";
        duration = 0;
        playCount = 0;
        available = true;
    }

    // Parameterized Constructor
    Song(int id, string t, string ar, string al,
         string g, float d, string p)
    {
        songID = id;
        title = t;
        artist = ar;
        album = al;
        genre = g;
        duration = d;
        playlist = p;
        playCount = 0;
        available = true;
    }

    // Copy Constructor
    Song(const Song &s)
    {
        songID = s.songID;
        title = s.title;
        artist = s.artist;
        album = s.album;
        genre = s.genre;
        duration = s.duration;
        playlist = s.playlist;
        playCount = s.playCount;
        available = s.available;
    }

    // Display Song Details
    void displaySong()
    {
        cout << "\n-----------------------------";
        cout << "\nID       : " << songID;
        cout << "\nTitle    : " << title;
        cout << "\nArtist   : " << artist;
        cout << "\nAlbum    : " << album;
        cout << "\nGenre    : " << genre;
        cout << "\nDuration : " << duration << " mins";
        cout << "\nPlaylist : " << playlist;
        cout << "\nPlay Count : " << playCount;
        cout << "\n-----------------------------\n";
    }

    // Play Song
    void playSong()
    {
        if (available)
        {
            playCount++;
            cout << "\nPlaying: " << title
                 << " by " << artist << "...";
            cout << "\nUpdated Play Count: " << playCount << endl;
        }
        else
        {
            cout << "\nSong is not available!\n";
        }
    }

    // Update Playlist
    void updatePlaylist(string p)
    {
        playlist = p;
        cout << "\nPlaylist updated successfully!\n";
    }

    // Remove from Playlist
    void removePlaylist()
    {
        playlist = "None";
        cout << "\nSong removed from playlist!\n";
    }

    // Play Statistics
    void viewStatistics()
    {
        cout << "\n----- Play Statistics -----";
        cout << "\nSong: " << title;
        cout << " (ID: " << songID << ")";
        cout << "\nCurrent Playlist Status: " << playlist;
        cout << "\nTotal Times Played: " << playCount << endl;
    }

    // Destructor
    ~Song()
    {
        if (songID != 0)
        {
            cout << "\n[Destructor]: Cleaning up resources "
                 << "for Song ID: " << songID << endl;
        }
    }
};

int main()
{
    Song defaultSong;   // Default Constructor

    Song *songs[50];
    int count = 0;
    int choice, id, i;
    string title, artist, album, genre, playlist;
    float duration;

    do
    {
        cout << "\n----- ONLINE MUSIC MANAGEMENT SYSTEM -----";
        cout << "\n1) Add New Song Record";
        cout << "\n2) Display All Songs";
        cout << "\n3) Play a Song";
        cout << "\n4) Update / Remove Playlist";
        cout << "\n5) View Play Statistics";
        cout << "\n6) Test Copy Constructor";
        cout << "\n7) Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (count >= 50)
            {
                cout << "\nSong Database is Full!\n";
                break;
            }

            cout << "\nEnter Song ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Song Title: ";
            getline(cin, title);

            cout << "Enter Artist Name: ";
            getline(cin, artist);

            cout << "Enter Album Name: ";
            getline(cin, album);

            cout << "Enter Genre: ";
            getline(cin, genre);

            cout << "Enter Duration (mins): ";
            cin >> duration;

            cin.ignore();

            cout << "Enter Playlist: ";
            getline(cin, playlist);

            songs[count] = new Song(id, title, artist,
                                    album, genre,
                                    duration, playlist);

            count++;

            cout << "\nSong Record Added Successfully!\n";
            break;

        case 2:
            if (count == 0)
            {
                cout << "\nNo Songs Available!\n";
            }
            else
            {
                cout << "\n----- ALL SONG RECORDS -----";

                for (i = 0; i < count; i++)
                {
                    songs[i]->displaySong();
                }
            }
            break;

        case 3:
            cout << "\nEnter Song ID to play: ";
            cin >> id;

            for (i = 0; i < count; i++)
            {
                if (songs[i]->songID == id)
                {
                    songs[i]->playSong();
                    break;
                }
            }

            if (i == count)
            {
                cout << "\nSong ID Not Found!\n";
            }
            break;

        case 4:
            cout << "\nEnter Song ID: ";
            cin >> id;

            for (i = 0; i < count; i++)
            {
                if (songs[i]->songID == id)
                {
                    int ch;

                    cout << "\n1) Update Playlist";
                    cout << "\n2) Remove from Playlist";
                    cout << "\nEnter your choice: ";
                    cin >> ch;

                    if (ch == 1)
                    {
                        cin.ignore();
                        cout << "Enter New Playlist: ";
                        getline(cin, playlist);

                        songs[i]->updatePlaylist(playlist);
                    }
                    else if (ch == 2)
                    {
                        songs[i]->removePlaylist();
                    }
                    else
                    {
                        cout << "\nInvalid Choice!\n";
                    }

                    break;
                }
            }

            if (i == count)
            {
                cout << "\nSong ID Not Found!\n";
            }
            break;

        case 5:
            cout << "\nEnter Song ID: ";
            cin >> id;

            for (i = 0; i < count; i++)
            {
                if (songs[i]->songID == id)
                {
                    songs[i]->viewStatistics();
                    break;
                }
            }

            if (i == count)
            {
                cout << "\nSong ID Not Found!\n";
            }
            break;

        case 6:
            if (count == 0)
            {
                cout << "\nNo Song Available to Copy!\n";
            }
            else
            {
                cout << "\nCreating a copy of the first song "
                     << "using Copy Constructor...\n";

                {
                    Song copy(*songs[0]);

                    copy.songID = 1101;
                    copy.title += " (Copy)";

                    copy.displaySong();
                }
            }
            break;

        case 7:
            cout << "\nExiting program...\n";
            break;

        default:
            cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 7);

    // Delete dynamically created song objects
    for (i = 0; i < count; i++)
    {
        delete songs[i];
    }

    return 0;
}
/*
----- ONLINE MUSIC MANAGEMENT SYSTEM -----
1) Add New Song Record
2) Display All Songs
3) Play a Song
4) Update / Remove Playlist
5) View Play Statistics
6) Test Copy Constructor
7) Exit
Enter your choice: 1

Enter Song ID: 101
Enter Song Title: Salvatore 
Enter Artist Name: Lana Del Rey
Enter Album Name: Fantasy 
Enter Genre: Pop
Enter Duration (mins): 3:24
Enter Playlist: 
Song Record Added Successfully!

----- ONLINE MUSIC MANAGEMENT SYSTEM -----
1) Add New Song Record
2) Display All Songs
3) Play a Song
4) Update / Remove Playlist
5) View Play Statistics
6) Test Copy Constructor
7) Exit
Enter your choice: 2

----- ALL SONG RECORDS -----
-----------------------------
ID       : 101
Title    : Salvatore 
Artist   : Lana Del Rey
Album    : Fantasy 
Genre    : Pop
Duration : 3 mins
Playlist : 24
Play Count : 0
-----------------------------

----- ONLINE MUSIC MANAGEMENT SYSTEM -----
1) Add New Song Record
2) Display All Songs
3) Play a Song
4) Update / Remove Playlist
5) View Play Statistics
6) Test Copy Constructor
7) Exit
Enter your choice: 4

Enter Song ID: 4

Song ID Not Found!

----- ONLINE MUSIC MANAGEMENT SYSTEM -----
1) Add New Song Record
2) Display All Songs
3) Play a Song
4) Update / Remove Playlist
5) View Play Statistics
6) Test Copy Constructor
7) Exit
Enter your choice: 7

Exiting program...

[Destructor]: Cleaning up resources for Song ID: 101
*/
