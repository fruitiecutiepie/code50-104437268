# Spotify Search Bar
#### Video Demo:  <URL HERE>
#### Description:
Spotify Search Bar is a console application that mimics a search bar by using Spotify Web API to perform data manipulation of songs, artists, and album details.

## How it Works

The program starts by checking the user's internet connection. This is done to ensure the program will be able to reach Spotify's server.

Then, the program prompt the user for input of songs, artists, or albums. It then requests data from Spotify Web API and displays the first 5 output of each type. If there are no results, the program will let the user know and prompt them for another input.

After the results are displayed, the program asks the user whether they want to search for another keyword or not. If the user answers "y", the program will perform another search for the new keyword. If the user answers "n", the program will ask whether or not they want to know more about a specific track, artist, or album. Based on user's enquiries, the program might show them the details of the enquired track, artist, or album. This includes API-exclusive fun facts such as the genre, followers, and popularity of an artist.

After that, the program will ask whether or not the user want to perform another search. If the user answers "y", the program will iterate. Else, the program will exit.

Users can see the expected responses and adjust accordingly by viewing the bracketed information in the question. All responses other than the options provided in the brackets and outside the scope will not be accepted.

## Confession
This project is far from perfect. It does not cover every bug and can be more well-optimised. Future improvements will have to be made. For example, there are too much iteration involving the process of extracting user inputs and displaying results. These problems should be solved by turning those processes into functions and/or using recursion. For now, it will, at least, deliver its promises 90% of the time.

## Real Confession
This project took me about 24 hours in total. I could have done better, but unfortunately current circumstances and implications shifted my priority list. Also, this program is not really useful other than for curiosity purposes. However, I learned some things about using API, which was not taught in the CS50 course. I chose Python for the language because it's easier (frankly). Nevertheless, and most importantly, I had fun doing this project. Rest assured that I will continue my programming journey (I am pursuing an IT degree right now!) and make more personal projects outside the scope of this course.