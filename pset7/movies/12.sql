SELECT title, stars.person_id FROM movies
JOIN stars
ON stars.movie_id = movies.id
WHERE stars.person_id = (SELECT id FROM people WHERE name = 'Johnny Depp' AND (SELECT id FROM people WHERE name = 'Helena Bonham Carter'));