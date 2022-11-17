# Spotify Search Bar
#### Video Demo:  <URL HERE>
#### Description:
Spotify Search Bar is a program that mimics a search bar by using Spotify Web API to perform data manipulation of songs, artists, and album details. It is written fully in Python.

The program starts by checking the user's internet connection. Without functioning internet, the program will not be able to reach Spotify's server. Then, the program prompt the user for input of songs, artists, or albums. It then requests data from Spotify Web API and displays the first 5 output of each type. If there is no results, however, the program will let the user know and prompt them for another input. After the results are displayed, the program asks the user whether they want to search for another keyword or not. If the user answers "y", the program will search for the new keyword. If the user answers "n", the program will ask whether they want to know more about a specific track, artist, or album, and which number

## Confession
This project is not perfect. It does not cover every bug and it can be more optimised. Future improvements will have to be made. For example, there are too much iteration involving the process of extracting user inputs and displaying results. These problems should be solved by turning those processes into functions.