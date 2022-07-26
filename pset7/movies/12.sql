SELECT title FROM movies
JOIN stars JOIN people
ON movies.id = stars.movie_id AND people.id = stars.person_id
WHERE people.id = (SELECT id FROM people WHERE name IN ('Johnny Depp','Helena Bonham Carter');