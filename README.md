
# 🎵 Music Playlist Manager (C++)

A simple **console-based Music Playlist Manager** built using **C++**, demonstrating core concepts of **Object-Oriented Programming (OOP)** and **File Handling**.

---

## 📌 Features

* ➕ Add new songs to playlist
* 📃 Display all songs
* 🔍 Search songs by title
* ❌ Delete songs
* ✏️ Rename songs
* 💾 Save playlist to file
* 📂 Load playlist from file
* 🚫 Prevent duplicate songs

---

## 🧠 Concepts Used

This project demonstrates:

* **Classes & Objects**
* **Constructors & Destructor**
* **Operator Overloading (`==`, `<<`)**
* **Encapsulation (private members + getters/setters)**
* **Arrays (static storage)**
* **File Handling (`ifstream`, `ofstream`)**
* **Exception Handling (`stoi`, `stof`)**

---

## 🏗️ Project Structure

```
Music-Playlist-Manager/
│
├── main.cpp        # Main source code
├── README.md       # Project documentation
└── My Playlist.txt (generated file)
```

---

## ⚙️ How It Works

### 🔹 Song Class

Represents a song with:

* Title
* Artist
* Duration

Includes:

* Constructors (default, parameterized, copy)
* Operator overloading:

  * `==` → checks duplicate songs (by title)
  * `<<` → formatted output

---

### 🔹 Playlist Class

Manages up to **100 songs** using an array.

Key functions:

* `addSong()` → Adds a song (checks duplicates)
* `displayAll()` → Shows all songs
* `searchSong()` → Finds song by title
* `deleteSong()` → Removes song
* `renameSong()` → Updates song title
* `saveToFile()` → Saves playlist
* `loadFromFile()` → Loads playlist

---

## 💻 How to Run

### 🔧 Compile

```bash
g++ main.cpp -o playlist
```

### ▶️ Run

```bash
./playlist
```

---

## 🖥️ Sample Menu

```
====== MUSIC PLAYLIST MANAGER ======
1. Add Song
2. Display All Songs
3. Search Song
4. Delete Song
5. Rename Song
6. Save Playlist to File
7. Load Playlist from File
0. Exit
=====================================
```

---

## 💾 File Format

Saved playlist file (`My Playlist.txt`) format:

```
Playlist Name
Number of Songs
Title1
Artist1
Duration1
Title2
Artist2
Duration2
...
```

---

## ⚠️ Limitations

* Maximum **100 songs** (fixed array)
* Search is **exact match only**
* No sorting or advanced filtering
* No GUI (console-based)

---

## 🚀 Future Improvements

* Use **dynamic memory / vectors**
* Add **sorting (by title/artist/duration)**
* Partial search (substring match)
* Playlist merging
* GUI using Qt or similar framework

---

## 👤 Author

**Sameep Batra**
**Saptaparna Dey**

---

## 📜 License

This project is open-source and free to use for learning purposes.

---

