#include <iostream>
using namespace std;

int main() {

    enum Rating { G, PG, PG13, R, NC17 };

    Rating movieRating = PG13;

    if (movieRating = R) {    
        cout << "This movie is rated R." << endl;
    } else {
        cout << "This movie is not rated R." << endl;
    }

    Rating nextRating = PG-1;   

    cout << "Next rating value: " << nextRating << endl

    return 0;
}