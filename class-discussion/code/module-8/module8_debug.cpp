#include <iostream>
#include <string>
using namespace std;

class Movie {
    string title;
    int year;

public:
    Movie(string t, int y) {
        title = t;
        year = y;
    }

    string getTitle() {
        return title;
    }
    int getYear() {
        return year;
    }
};

int main() {

    Movie film("Jurassic Park", 1993);

    cout << "Movie: " << film.getTitle() << " (" << film.getYear() << ")" << endl;
    int total = film.getYear();

    return 0;
}