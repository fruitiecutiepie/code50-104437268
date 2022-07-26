SELECT title, name FROM movies
JOIN stars JOIN people
ON stars.movie_id = movies.id AND stars.person_id = people.id
WHERE name IN ('Johnny Depp', 'Helena Bonham Carter');