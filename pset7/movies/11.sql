SELECT title FROM movies
JOIN stars JOIN ratings JOIN people
ON stars.movie_id = movies.id
AND stars.person_id = people.id
AND ratings.movie_id = movies.id
WHERE name = "Chadwick Boseman"
ORDER BY rating DESC
LIMIT 5;