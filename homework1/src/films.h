#pragma once

struct films{
    char *film_name;
    int release_date;
    char *genre;
    int avg_audience_rating;
};

struct all_films{
    size_t size;
    struct films *list_of_films;
};

int create_film_list(struct all_films **new_film_p);

void print(const struct all_films *all_films);

void print_list(const struct all_films *all_films, int release_year, int lowest_rating, int highest_rating, const char *need_genre);

void deletion(struct all_films *all_films);