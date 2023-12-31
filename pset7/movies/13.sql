SELECT DISTINCT(name)
FROM movies
    JOIN stars JOIN people
    ON stars.movie_id = movies.id
    AND stars.person_id = people.id
    WHERE movies.id IN
    (
        SELECT movies.id
        FROM movies
            JOIN stars JOIN people
            ON stars.movie_id = movies.id
            AND stars.person_id = people.id
            WHERE name = "Kevin Bacon"
            AND birth = 1958
    )
    EXCEPT
    SELECT name
    FROM movies
        JOIN stars JOIN people
        ON stars.movie_id = movies.id
        AND stars.person_id = people.id
        WHERE name = "Kevin Bacon"
        AND birth = 1958;