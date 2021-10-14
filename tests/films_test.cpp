#include <gtest/gtest.h>
#include <iostream>

extern "C" {
#include "films.h"
}

char first_film_name[] = "Venom";
int first_film_release = 2021;
char first_film_genre[] = "Action";
int first_film_rating = 6;

char second_film_name[] = "Duna";
int second_film_release = 2021;
char second_film_genre[] = "Sci-fi";
int second_film_rating = 9;

int find_release_year = 2021;
int lowest_rating = 5;
int highest_rating = 9;
char find_genre[] = "Action";

const films first_film = {first_film_name, first_film_release, first_film_genre, first_film_rating};
const films second_film = {second_film_name, second_film_release, second_film_genre, second_film_rating};


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

