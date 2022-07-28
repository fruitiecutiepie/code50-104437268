SELECT DISTINCT(name) FROM people
    JOIN directors JOIN ratings JOIN movies
    ON directors.movie_id = movies.id
    AND directors.person_id = people.id
    AND ratings.movie_id = movies.id
    WHERE RATING >= 9.0;