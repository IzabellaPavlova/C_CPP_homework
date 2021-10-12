#include <stdio.h>
#include "films.h"

int main() {

    struct all_films *new_film = NULL;

    int film_list_is_created = create_film_list(&new_film);

    if(film_list_is_created == 0){
        printf("A list of films was not created\n");
        return 0;
    }

    printf("The films you've entered:\n");
    print(new_film);

    int release_year = 1888;
    printf("Enter a release year: ");
    scanf("%d", &release_year);

    int lowest_rating = 0;
    int highest_rating = 10;
    printf("Enter a lowest rating: ");
    scanf("%d", &lowest_rating);
    printf("Enter a highest rating: ");
    scanf("%d", &highest_rating);

    char *need_genre = NULL;
    printf("Enter a genre: ");
    scanf("%s", &need_genre);

    printf("\nThis is the list of recomendations for you: \n");
    print_list(new_film, release_year, lowest_rating, highest_rating, need_genre);

    deletion(new_film);

    return 0;
}