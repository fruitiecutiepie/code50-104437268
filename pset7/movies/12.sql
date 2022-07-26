SELECT title, name, person_id FROM movies
JOIN stars JOIN people
ON movies.id = stars.movie_id AND people.id = stars.person_id
WHERE people_id = (SELECT id FROM people WHERE name = 'Johnny Depp')
                AND (SELECT id FROM people WHERE name = 'Helena Bonham Carter');