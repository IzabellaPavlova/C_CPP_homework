#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "films.h"

#define MIN_RELEASE_DATE 1888
#define MAX_RELEASE_DATE 2021
#define MIN_AVG_RATING 0
#define MAX_AVG_RATING 10

int create_film_list(struct all_films **new_film_p){
    if(!new_film_p){
        return 0;
    }
    *new_film_p = (struct all_films *)malloc(sizeof(struct all_films));
    struct all_films *new_film = *new_film_p;
    if(!new_film){
        return 0;
    }
    int size = 0;
    do{
        printf("Enter the number of films you want to add: ");
        scanf("%d", &size);
    } while (!(size >= 1));
    new_film->size = (size_t)size;
    new_film->list_of_films = (struct films *)malloc(new_film->size * sizeof(struct films));
    if (!new_film->list_of_films){
        return 0;
    }
    for (size_t i = 0; i < new_film->size; ++i){
        new_film->list_of_films[i].film_name = NULL;
        new_film->list_of_films[i].release_date = NULL;
        new_film->list_of_films[i].genre = NULL;
        new_film->list_of_films[i].avg_audience_rating = NULL;
        char *string = NULL;
        int number = NULL;
        printf("Enter a film name:\n");
        scanf("%s", &string);
        if (!string) {
        return 0;
        }
        new_film->list_of_films[i].film_name = string;
        printf("Enter a release date (min: %d - max: %d):\n", MIN_RELEASE_DATE, MAX_RELEASE_DATE);
        scanf("%d", &number);
        if (!number) {
        return 0;
        }
        new_film->list_of_films[i].release_date = number;
        printf("Enter a film genre:\n");
        scanf("%s", &string);
        if (!string) {
        return 0;
        }
        new_film->list_of_films[i].genre = string;
        printf("Enter an average rating (min: %d - max: %d):\n", MIN_AVG_RATING, MAX_AVG_RATING);
        scanf("%d", &number);
        if (!number) {
        return 0;
        }
        new_film->list_of_films[i].avg_audience_rating = number;
    }
    return 1;
}

void print(const struct all_films *all_films){
    for (size_t i = 0; i < all_films->size; ++i){
        printf("Film name: %s\n", &all_films->list_of_films[i].film_name);
        printf("Release date: %d\n", all_films->list_of_films[i].release_date);
        printf("Film genre: %s\n", &all_films->list_of_films[i].genre);
        printf("Average rating: %d\n\n", all_films->list_of_films[i].avg_audience_rating);
    }
}

void print_list(const struct all_films *all_films, int release_year, int lowest_rating, int highest_rating, const char *need_genre){
    for (size_t i = 0; i < all_films->size; ++i){
        if (all_films->list_of_films[i].release_date = release_year){
            if (all_films->list_of_films[i].avg_audience_rating >= lowest_rating){
                if (all_films->list_of_films[i].avg_audience_rating <= highest_rating){
                    const char * string = all_films->list_of_films[i].genre;
                    if (strcmp(&string, &need_genre) == 0){
                        printf("\nFilm name: %s\n", &all_films->list_of_films[i].film_name);
                        printf("Release date: %d\n", all_films->list_of_films[i].release_date);
                        printf("Film genre: %s\n", &all_films->list_of_films[i].genre);
                        printf("Average rating: %d\n\n", all_films->list_of_films[i].avg_audience_rating);
                    }
                }
            }
        }
        else{
            printf("The are no films with such parametrs");
        }
    }
}

void deletion(struct all_films *all_films){
    if (!all_films){
        return;
    }
    if (all_films->list_of_films){
        free(all_films->list_of_films);
    }
    free(all_films);
}
