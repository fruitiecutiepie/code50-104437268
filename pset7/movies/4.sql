SELECT COUNT(title) FROM movies
    JOIN ratings
    WHERE rating = 10.0 AND ratings.movie_id = movies.id;