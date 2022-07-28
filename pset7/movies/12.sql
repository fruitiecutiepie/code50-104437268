SELECT title
FROM movies
    JOIN stars JOIN people
    ON stars.movie_id = movies.id
    AND stars.person_id = people.id
    WHERE name = 'Johnny Depp'
INTERSECT
SELECT title
FROM movies
    JOIN stars JOIN people
    ON stars.movie_id = movies.id
    AND stars.person_id = people.id
    WHERE name = 'Helena Bonham Carter';