-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Look for a crime scene report that matches the date and the location of the crime
SELECT *
FROM crime_scene_reports
WHERE year = 2021
AND month = 7
AND day = 28
AND street = 'Humphrey Street';
-- Found: Humphrey Street bakery; 10:15 AM; interviews with three witnesses, each mentioned the bakery.

-- Look for interviews that matches the date and the location of the crime
SELECT *
FROM interviews
WHERE year = 2021
AND month = 7
AND day = 28;
-- Found witnesses: Ruth, Eugene, and Raymond

SELECT *
FROM bakery_security_logs
WHERE year = 2021
AND month = 7
AND day = 28
AND hour = 10
AND minute in (10,11,12,13,14,15,16,17,18,19,20)
AND activity = 'exit';