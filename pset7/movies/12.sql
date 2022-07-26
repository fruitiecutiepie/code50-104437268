SELECT title, name, person_id FROM movies
JOIN stars JOIN people
ON movies.id = stars.movie_id
AND stars.person_id = (SELECT id FROM people WHERE name = 'Johnny Depp')
AND stars.person_id = (SELECT id FROM people WHERE name = 'Helena Bonham Carter');