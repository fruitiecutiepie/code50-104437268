-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Look for a crime scene report that matches the date and the location of the crime
SELECT description
FROM crime_scene_reports
WHERE year = 2021
AND month = 7
AND day = 28
AND street = 'Humphrey Street';
-- Found: Humphrey Street bakery; 10:15 AM; interviews with three witnesses, each mentioned the bakery.

-- Look for interviews that matches the date and the location of the crime
SELECT transcript
FROM interviews
WHERE year = 2021
AND month = 7
AND day = 28;
-- Found witnesses: Ruth, Eugene, and Raymond.

-- Look for cars that exited the bakery within ten minutes of the theft
SELECT license_plate
FROM bakery_security_logs
WHERE year = 2021
AND month = 7
AND day = 28
AND hour = 10
AND minute BETWEEN 10 AND 20
AND activity = 'exit';
-- Found possible license plate: 5P2BI95, 94KL13X, 6P58WS2, 4328GD8, or G412CB7.

-- Look for ATM transactions on Leggett Street earlier that morning
SELECT account_number, amount
FROM atm_transactions
WHERE year = 2021
AND month = 7
AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';
-- Found 8 possible account numbers.

-- Look for phone calls for < 1 minute as the thief was leaving the bakery -> accomplice

-- Look for earliest flight out of Fiftyville tomorrow (29-7-21)