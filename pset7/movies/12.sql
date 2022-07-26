SELECT title, name, person_id FROM movies
JOIN stars JOIN people
ON movies.id = stars.movie_id AND people.id = stars.person_id
WHERE name IN ('Johnny Depp','Helena Bonham Carter');