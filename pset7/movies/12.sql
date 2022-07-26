SELECT title, name, person_id FROM movies
JOIN stars JOIN people
ON stars.movie_id = movies.id
AND stars.person_id IN (SELECT id FROM people WHERE name = 'Johnny Depp') AND (SELECT id FROM people WHERE name = 'Helena Bonham Carter');