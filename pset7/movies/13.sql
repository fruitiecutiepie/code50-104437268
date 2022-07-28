SELECT title FROM movies
JOIN stars JOIN people
ON stars.movie_id = movies.id
AND stars.person_id = people.id
WHERE name = "Kevin Bacon"
AND birth = 1958;