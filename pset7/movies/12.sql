SELECT DISTINCT(title) FROM movies
JOIN stars JOIN people
ON stars.movie_id = movies.id
AND stars.person_id = ((SELECT id FROM people WHERE name = 'Johnny Depp')
AND (SELECT id FROM people WHERE name = 'Helena Bonham Carter'));