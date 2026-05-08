#include <iostream>
#include <string>
using namespace std;

class Movie {
    string title;
    int year;

public:
    Movie(string title, int y) {
        title = title;
        year = y;
    }

    string getTitle() {
        return title;
    }
    int setYear() {
        return year;
    }
};

int main() {

    Movie film("Jurassic Park", 1993);

    cout << "Movie: " << film.getTitle() << " (" << film.getYear() << ")" << endl;

    return 0;
}