SELECT title FROM movies
JOIN stars JOIN people
ON movies.id = stars.movie_id AND people.id = stars.person_id
WHERE name = 'Johnny Depp' AND name = 'Helena Bonham Carter';