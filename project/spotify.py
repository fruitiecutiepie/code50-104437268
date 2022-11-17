import requests


# Checks connection
url = "http://1.1.1.1"
timeout = 10
try:
    request = requests.get(url, timeout=timeout)
except (requests.ConnectionError, requests.Timeout) as exception:
    input('Unable to connect to the Internet. Please check your internet connection and try again later. ')


# POST
CLIENT_ID = '508742e2a4f3489d827d3186578e2bf2'
CLIENT_SECRET = 'ca308d44dfdc422fb9e1eb224d10a66b'
AUTH_URL = 'https://accounts.spotify.com/api/token'

auth_response = requests.post(AUTH_URL, {
    'grant_type': 'client_credentials',
    'client_id': CLIENT_ID,
    'client_secret': CLIENT_SECRET,
})
auth_response_data = auth_response.json()
access_token = auth_response_data['access_token']


# Web API requests
BASE_URL = 'https://api.spotify.com/v1/'
headers = {'Authorization': 'Bearer ' + access_token}


# Query parameter
while True:
    search_query = input('Search for songs/artists/albums: ')
    while search_query == '':
        search_query = input('Search for songs/artists/albums: ')
    search_type = ['track,artist,album']
    params = {'q': search_query, 'type': search_type, 'limit': 5}


    # Search for query
    query_info = requests.get(BASE_URL + 'search',
                              headers=headers,
                              params=params
                              )
    query_info = query_info.json()


    # Track overview
    print('\nSONGS')

    if query_info['tracks']['items'] == []:
        print('No results found. Please try another keyword. ')

    t_track_name = []
    t_track_popularity = []
    t_track_track_number = []
    t_track_link = []
    t_album_name = []
    t_album_total_tracks = []
    t_album_release_date = []
    t_album_link = []
    t_artist_name = []
    t_artist_link = []

    for tracks in range(len(query_info['tracks']['items'])):
        t_track_name.append(query_info['tracks']['items'][tracks]['name'])
        t_track_popularity.append(query_info['tracks']['items'][tracks]['popularity'])
        t_track_track_number.append(query_info['tracks']['items'][tracks]['track_number'])
        t_track_link.append(query_info['tracks']['items'][tracks]['external_urls']['spotify'])
        t_album_name.append(query_info['tracks']['items'][tracks]['album']['name'])
        t_album_total_tracks.append(query_info['tracks']['items'][tracks]['album']['total_tracks'])
        t_album_release_date.append(query_info['tracks']['items'][tracks]['album']['release_date'])
        t_album_link.append(query_info['tracks']['items'][tracks]['album']['external_urls']['spotify'])
        t_artist_name_each_track = []
        t_artist_link_each_track = []
        for artists in range(len(query_info['tracks']['items'][tracks]['album']['artists'])):
            t_artist_name_each_track.append(query_info['tracks']['items'][tracks]['album']['artists'][artists]['name'])
            t_artist_link_each_track.append(query_info['tracks']['items'][tracks]['album']['artists'][artists]['external_urls']['spotify'])
        t_artist_name.append(t_artist_name_each_track)
        t_artist_link.append(t_artist_link_each_track)

        t_dict = {'track': 'Track: ' + str(t_track_name[tracks]),
                  'artist': 'Artist: ' + str(t_artist_name[tracks]),
                  }

        track_info = str(tracks + 1) + ' ' + t_dict['track'] + '\n  ' + t_dict['artist']
        print(track_info)


    # Artist overview
    print('\nARTISTS')

    if query_info['artists']['items'] == []:
        print('No results found. Please try another keyword. ')

    a_artist_name = []
    a_artist_genre = []
    a_artist_followers = []
    a_artist_popularity = []
    a_artist_link = []

    for artists in range(len(query_info['artists']['items'])):
        a_artist_name.append(query_info['artists']['items'][artists]['name'])
        a_artist_genre.append(query_info['artists']['items'][artists]['genres'])
        a_artist_followers.append(query_info['artists']['items'][artists]['followers']['total'])
        a_artist_popularity.append(query_info['artists']['items'][artists]['popularity'])
        a_artist_link.append(query_info['artists']['items'][artists]['external_urls']['spotify'])
        a_dict = {'artist': 'Artist: ' + str(a_artist_name[artists]),
                  }

        artist_info = str(artists + 1) + ' ' + a_dict['artist']
        print(artist_info)


    # Album overview
    print('\nALBUMS')

    if query_info['albums']['items'] == []:
        print('No results found. Please try another keyword. ')

    al_album_name = []
    al_album_total_tracks = []
    al_album_release_date = []
    al_album_link = []
    al_artist_name = []
    al_artist_link = []

    for albums in range(len(query_info['albums']['items'])):
        al_album_name.append(query_info['albums']['items'][albums]['name'])
        al_album_total_tracks.append(query_info['albums']['items'][albums]['total_tracks'])
        al_album_release_date.append(query_info['albums']['items'][albums]['release_date'])
        al_album_link.append(query_info['albums']['items'][albums]['external_urls']['spotify'])
        al_artist_name_each_album = []
        al_artist_link_each_album = []
        for artists in range(len(query_info['albums']['items'][albums]['artists'])):
            al_artist_name_each_album.append(query_info['albums']['items'][albums]['artists'][artists]['name'])
            al_artist_link_each_album.append(query_info['albums']['items'][albums]['artists'][artists]['external_urls']['spotify'])
        al_artist_name.append(al_artist_name_each_album)
        al_artist_link.append(al_artist_link_each_album)

        al_dict = {'album': 'Album: ' + str(al_album_name[albums]),
                   'artist': 'Artist: ' + str(al_artist_name[albums]),
                   }

        album_info = str(albums + 1) + ' ' + al_dict['album'] + '\n  ' + al_dict['artist']
        print(album_info)


    # Iterate search
    search_again = input('\nDo you want to search another keyword? [y/n] ').lower()
    while not(search_again == 'y' or search_again == 'n'):
        search_again = input('Do you want to search another keyword? [y/n] ').lower()


    # Search details?
    if search_again == 'n':
        know_more = input('\nDo you want to know more about a track/artist/album? [y/n] ').lower()
        while not(know_more == 'y' or know_more == 'n'):
            know_more = input('Do you want to know more about a track/artist/album? [y/n] ').lower()
        if know_more == 'n':
            input('\nThank you for using our service! ')
            break


        # Search details
        know_more_details = input('\nWhich one do you want to know more about? [track/artist/album] ').lower()
        while not(know_more_details == 'track' or know_more_details == 'artist' or know_more_details == 'album'):
            know_more_details = input('Which one do you want to know more about? [track/artist/album] ').lower()


        # If all items have no results (REFER BACK TO THE BEGINNING)
        if query_info['tracks']['items'] == [] and query_info['artists']['items'] == [] and query_info['albums']['items'] == []:
            print('No results found. Please try another keyword.')


        # If not all items have no results (TOO MUCH ITERATION, TURN TO DEFs)
        if know_more_details == 'track':
            while query_info['tracks']['items'] == []:
                know_more_details = input('No results found. Please try another keyword. ').lower()
                while not(know_more_details == 'track' or know_more_details == 'artist' or know_more_details == 'album'):
                    know_more_details = input('Which one do you want to know more about? [track/artist/album] ').lower()

                # Track details
                if know_more_details == 'track':
                    know_more_details = input('\nWhich track do you want to know more about? [number] ').lower()
                    while not(know_more_details.strip().isdigit() == True):
                        know_more_details = input('Which track do you want to know more about? [number] ').lower()
                    num = int(know_more_details) - 1
                    tracks = len(query_info['tracks']['items'])
                    while not(0 <= num <= tracks):
                        know_more_details = input('Which track do you want to know more about? [number] ').lower()
                        num = int(know_more_details) - 1
                        tracks = len(query_info['tracks']['items'])

                    t_dict = {'track': 'Track: ' + str(t_track_name[num]),
                              'track_popularity': 'Popularity: ' + str(t_track_popularity[num]),
                              'track_num': 'Track Number: ' + str(t_track_track_number[num]),
                              'track_link': 'Spotify: ' + str(t_track_link[num]),
                              'album': 'Album: ' + str(t_album_name[num]),
                              'album_tracks': 'Total Tracks: '  + str(t_album_total_tracks[num]),
                              'album_release': 'Release Date: ' + str(t_album_release_date[num]),
                              'album_link': 'Spotify: ' + str(t_album_link[num]),
                              'artist': 'Artist: ' + str(t_artist_name[num]),
                              'artist_link': 'Spotify: ' + str(t_artist_link[num]),
                              }

                    track_details = '\n' + t_dict['track'] + '\n' + t_dict['track_popularity'] + '\n' + t_dict['track_num'] + '\n' + t_dict['track_link'] + '\n---\n' + t_dict['album'] + '\n' + t_dict['album_tracks'] + '\n' + t_dict['album_release'] + '\n' + t_dict['album_link'] + '\n---\n' + t_dict['artist'] + '\n' + t_dict['artist_link']
                    print(track_details)

                    # Iterate search
                    search_again = input('\nDo you want to search again? [y/n] ').lower()
                    while not(search_again == 'y' or search_again == 'n'):
                        search_again = input('Do you want to search again? [y/n] ').lower()
                    if search_again == 'n':
                        input('\nThank you for using our service! ')
                        break

                # Artist details
                elif know_more_details == 'artist':
                    know_more_details = input('\nWhich artist do you want to know more about? [number] ').lower()
                    while not(know_more_details.strip().isdigit() == True):
                        know_more_details = input('Which artist do you want to know more about? [number] ').lower()
                    num = int(know_more_details) - 1
                    artists = len(query_info['artists']['items'])
                    while not(0 <= num <= artists):
                        know_more_details = input('Which artist do you want to know more about? [number] ').lower()
                        num = int(know_more_details) - 1
                        artists = len(query_info['artists']['items'])

                    a_dict = {'artist': 'Artist: ' + str(a_artist_name[num]),
                              'artist_genre': 'Genre: ' + str(a_artist_genre[num]),
                              'artist_followers': 'Followers: ' + str(a_artist_followers[num]),
                              'artist_popularity': 'Popularity: ' + str(a_artist_popularity[num]),
                              'artist_link': 'Spotify: ' + str(a_artist_link[num]),
                              }

                    artist_details = '\n' + a_dict['artist'] + '\n' + a_dict['artist_genre'] + '\n' + a_dict['artist_followers'] + '\n' + a_dict['artist_popularity'] + '\n' + a_dict['artist_link']
                    print(artist_details)

                    # Iterate search
                    search_again = input('\nDo you want to search again? [y/n] ').lower()
                    while not(search_again == 'y' or search_again == 'n'):
                        search_again = input('Do you want to search again? [y/n] ').lower()
                    if search_again == 'n':
                        input('\nThank you for using our service! ')
                        break

                # Album details
                else:
                    know_more_details = input('\nWhich album do you want to know more about? [number] ').lower()
                    while not(know_more_details.strip().isdigit() == True):
                        know_more_details = input('Which album do you want to know more about? [number] ').lower()
                    num = int(know_more_details) - 1
                    albums = len(query_info['albums']['items'])
                    while not(0 <= num <= albums):
                        know_more_details = input('Which album do you want to know more about? [number] ').lower()
                        num = int(know_more_details) - 1
                        albums = len(query_info['albums']['items'])

                    al_dict = {'album': 'Album: ' + str(al_album_name[num]),
                               'album_tracks': 'Total Tracks: ' + str(al_album_total_tracks[num]),
                               'album_release': 'Release Date: ' + str(al_album_release_date[num]),
                               'album_link': 'Spotify: ' + str(al_album_link[num]),
                               'artist': 'Artist: ' + str(al_artist_name[num]),
                               'artist_link': 'Spotify: ' + str(al_artist_link[num]),
                               }

                    album_details = '\n' + al_dict['album'] + '\n' + al_dict['album_tracks'] + '\n' + al_dict['album_release'] + '\n' + al_dict['album_link'] + '\n---\n' + al_dict['artist'] + '\n' + al_dict['artist_link']
                    print(album_details)

                    # Iterate search
                    search_again = input('\nDo you want to search again? [y/n] ').lower()
                    while not(search_again == 'y' or search_again == 'n'):
                        search_again = input('Do you want to search again? [y/n] ').lower()
                    if search_again == 'n':
                        input('\nThank you for using our service! ')
                        break

            # Track details
            if know_more_details == 'track':
                know_more_details = input('\nWhich track do you want to know more about? [number] ').lower()
                while not(know_more_details.strip().isdigit() == True):
                    know_more_details = input('Which track do you want to know more about? [number] ').lower()
                num = int(know_more_details) - 1
                tracks = len(query_info['tracks']['items'])
                while not(0 <= num <= tracks):
                    know_more_details = input('Which track do you want to know more about? [number] ').lower()
                    num = int(know_more_details) - 1
                    tracks = len(query_info['tracks']['items'])

                t_dict = {'track': 'Track: ' + str(t_track_name[num]),
                          'track_popularity': 'Popularity: ' + str(t_track_popularity[num]),
                          'track_num': 'Track Number: ' + str(t_track_track_number[num]),
                          'track_link': 'Spotify: ' + str(t_track_link[num]),
                          'album': 'Album: ' + str(t_album_name[num]),
                          'album_tracks': 'Total Tracks: '  + str(t_album_total_tracks[num]),
                          'album_release': 'Release Date: ' + str(t_album_release_date[num]),
                          'album_link': 'Spotify: ' + str(t_album_link[num]),
                          'artist': 'Artist: ' + str(t_artist_name[num]),
                          'artist_link': 'Spotify: ' + str(t_artist_link[num]),
                          }

                track_details = '\n' + t_dict['track'] + '\n' + t_dict['track_popularity'] + '\n' + t_dict['track_num'] + '\n' + t_dict['track_link'] + '\n---\n' + t_dict['album'] + '\n' + t_dict['album_tracks'] + '\n' + t_dict['album_release'] + '\n' + t_dict['album_link'] + '\n---\n' + t_dict['artist'] + '\n' + t_dict['artist_link']
                print(track_details)

                # Iterate search
                search_again = input('\nDo you want to search again? [y/n] ').lower()
                while not(search_again == 'y' or search_again == 'n'):
                    search_again = input('Do you want to search again? [y/n] ').lower()
                if search_again == 'n':
                    input('\nThank you for using our service! ')
                    break

        elif know_more_details == 'artist':
            while query_info['artists']['items'] == []:
                know_more_details = input('No results found. Please try another keyword. ').lower()
                while not(know_more_details == 'track' or know_more_details == 'artist' or know_more_details == 'album'):
                    know_more_details = input('Which one do you want to know more about? [track/artist/album] ').lower()

                # Track details
                if know_more_details == 'track':
                    know_more_details = input('\nWhich track do you want to know more about? [number] ').lower()
                    while not(know_more_details.strip().isdigit() == True):
                        know_more_details = input('Which track do you want to know more about? [number] ').lower()
                    num = int(know_more_details) - 1
                    tracks = len(query_info['tracks']['items'])
                    while not(0 <= num <= tracks):
                        know_more_details = input('Which track do you want to know more about? [number] ').lower()
                        num = int(know_more_details) - 1
                        tracks = len(query_info['tracks']['items'])

                    t_dict = {'track': 'Track: ' + str(t_track_name[num]),
                              'track_popularity': 'Popularity: ' + str(t_track_popularity[num]),
                              'track_num': 'Track Number: ' + str(t_track_track_number[num]),
                              'track_link': 'Spotify: ' + str(t_track_link[num]),
                              'album': 'Album: ' + str(t_album_name[num]),
                              'album_tracks': 'Total Tracks: '  + str(t_album_total_tracks[num]),
                              'album_release': 'Release Date: ' + str(t_album_release_date[num]),
                              'album_link': 'Spotify: ' + str(t_album_link[num]),
                              'artist': 'Artist: ' + str(t_artist_name[num]),
                              'artist_link': 'Spotify: ' + str(t_artist_link[num]),
                              }

                    track_details = '\n' + t_dict['track'] + '\n' + t_dict['track_popularity'] + '\n' + t_dict['track_num'] + '\n' + t_dict['track_link'] + '\n---\n' + t_dict['album'] + '\n' + t_dict['album_tracks'] + '\n' + t_dict['album_release'] + '\n' + t_dict['album_link'] + '\n---\n' + t_dict['artist'] + '\n' + t_dict['artist_link']
                    print(track_details)

                    # Iterate search
                    search_again = input('\nDo you want to search again? [y/n] ').lower()
                    while not(search_again == 'y' or search_again == 'n'):
                        search_again = input('Do you want to search again? [y/n] ').lower()
                    if search_again == 'n':
                        input('\nThank you for using our service! ')
                        break

                # Artist details
                elif know_more_details == 'artist':
                    know_more_details = input('\nWhich artist do you want to know more about? [number] ').lower()
                    while not(know_more_details.strip().isdigit() == True):
                        know_more_details = input('Which artist do you want to know more about? [number] ').lower()
                    num = int(know_more_details) - 1
                    artists = len(query_info['artists']['items'])
                    while not(0 <= num <= artists):
                        know_more_details = input('Which artist do you want to know more about? [number] ').lower()
                        num = int(know_more_details) - 1
                        artists = len(query_info['artists']['items'])

                    a_dict = {'artist': 'Artist: ' + str(a_artist_name[num]),
                              'artist_genre': 'Genre: ' + str(a_artist_genre[num]),
                              'artist_followers': 'Followers: ' + str(a_artist_followers[num]),
                              'artist_popularity': 'Popularity: ' + str(a_artist_popularity[num]),
                              'artist_link': 'Spotify: ' + str(a_artist_link[num]),
                              }

                    artist_details = '\n' + a_dict['artist'] + '\n' + a_dict['artist_genre'] + '\n' + a_dict['artist_followers'] + '\n' + a_dict['artist_popularity'] + '\n' + a_dict['artist_link']
                    print(artist_details)

                    # Iterate search
                    search_again = input('\nDo you want to search again? [y/n] ').lower()
                    while not(search_again == 'y' or search_again == 'n'):
                        search_again = input('Do you want to search again? [y/n] ').lower()
                    if search_again == 'n':
                        input('\nThank you for using our service! ')
                        break

                # Album details
                else:
                    know_more_details = input('\nWhich album do you want to know more about? [number] ').lower()
                    while not(know_more_details.strip().isdigit() == True):
                        know_more_details = input('Which album do you want to know more about? [number] ').lower()
                    num = int(know_more_details) - 1
                    albums = len(query_info['albums']['items'])
                    while not(0 <= num <= albums):
                        know_more_details = input('Which album do you want to know more about? [number] ').lower()
                        num = int(know_more_details) - 1
                        albums = len(query_info['albums']['items'])

                    al_dict = {'album': 'Album: ' + str(al_album_name[num]),
                               'album_tracks': 'Total Tracks: ' + str(al_album_total_tracks[num]),
                               'album_release': 'Release Date: ' + str(al_album_release_date[num]),
                               'album_link': 'Spotify: ' + str(al_album_link[num]),
                               'artist': 'Artist: ' + str(al_artist_name[num]),
                               'artist_link': 'Spotify: ' + str(al_artist_link[num]),
                               }

                    album_details = '\n' + al_dict['album'] + '\n' + al_dict['album_tracks'] + '\n' + al_dict['album_release'] + '\n' + al_dict['album_link'] + '\n---\n' + al_dict['artist'] + '\n' + al_dict['artist_link']
                    print(album_details)

                    # Iterate search
                    search_again = input('\nDo you want to search again? [y/n] ').lower()
                    while not(search_again == 'y' or search_again == 'n'):
                        search_again = input('Do you want to search again? [y/n] ').lower()
                    if search_again == 'n':
                        input('\nThank you for using our service! ')
                        break

            # Artist details
            if know_more_details == 'artist':
                know_more_details = input('\nWhich artist do you want to know more about? [number] ').lower()
                while not(know_more_details.strip().isdigit() == True):
                    know_more_details = input('Which artist do you want to know more about? [number] ').lower()
                num = int(know_more_details) - 1
                artists = len(query_info['artists']['items'])
                while not(0 <= num <= artists):
                    know_more_details = input('Which artist do you want to know more about? [number] ').lower()
                    num = int(know_more_details) - 1
                    artists = len(query_info['artists']['items'])

                a_dict = {'artist': 'Artist: ' + str(a_artist_name[num]),
                          'artist_genre': 'Genre: ' + str(a_artist_genre[num]),
                          'artist_followers': 'Followers: ' + str(a_artist_followers[num]),
                          'artist_popularity': 'Popularity: ' + str(a_artist_popularity[num]),
                          'artist_link': 'Spotify: ' + str(a_artist_link[num]),
                          }

                artist_details = '\n' + a_dict['artist'] + '\n' + a_dict['artist_genre'] + '\n' + a_dict['artist_followers'] + '\n' + a_dict['artist_popularity'] + '\n' + a_dict['artist_link']
                print(artist_details)

                # Iterate search
                search_again = input('\nDo you want to search again? [y/n] ').lower()
                while not(search_again == 'y' or search_again == 'n'):
                    search_again = input('Do you want to search again? [y/n] ').lower()
                if search_again == 'n':
                    input('\nThank you for using our service! ')
                    break

        elif know_more_details == 'album':
            while query_info['albums']['items'] == []:
                know_more_details = input('No results found. Please try another keyword. ').lower()
                while not(know_more_details == 'track' or know_more_details == 'artist' or know_more_details == 'album'):
                    know_more_details = input('Which one do you want to know more about? [track/artist/album] ').lower()

                # Track details
                if know_more_details == 'track':
                    know_more_details = input('\nWhich track do you want to know more about? [number] ').lower()
                    while not(know_more_details.strip().isdigit() == True):
                        know_more_details = input('Which track do you want to know more about? [number] ').lower()
                    num = int(know_more_details) - 1
                    tracks = len(query_info['tracks']['items'])
                    while not(0 <= num <= tracks):
                        know_more_details = input('Which track do you want to know more about? [number] ').lower()
                        num = int(know_more_details) - 1
                        tracks = len(query_info['tracks']['items'])

                    t_dict = {'track': 'Track: ' + str(t_track_name[num]),
                              'track_popularity': 'Popularity: ' + str(t_track_popularity[num]),
                              'track_num': 'Track Number: ' + str(t_track_track_number[num]),
                              'track_link': 'Spotify: ' + str(t_track_link[num]),
                              'album': 'Album: ' + str(t_album_name[num]),
                              'album_tracks': 'Total Tracks: '  + str(t_album_total_tracks[num]),
                              'album_release': 'Release Date: ' + str(t_album_release_date[num]),
                              'album_link': 'Spotify: ' + str(t_album_link[num]),
                              'artist': 'Artist: ' + str(t_artist_name[num]),
                              'artist_link': 'Spotify: ' + str(t_artist_link[num]),
                              }

                    track_details = '\n' + t_dict['track'] + '\n' + t_dict['track_popularity'] + '\n' + t_dict['track_num'] + '\n' + t_dict['track_link'] + '\n---\n' + t_dict['album'] + '\n' + t_dict['album_tracks'] + '\n' + t_dict['album_release'] + '\n' + t_dict['album_link'] + '\n---\n' + t_dict['artist'] + '\n' + t_dict['artist_link']
                    print(track_details)

                    # Iterate search
                    search_again = input('\nDo you want to search again? [y/n] ').lower()
                    while not(search_again == 'y' or search_again == 'n'):
                        search_again = input('Do you want to search again? [y/n] ').lower()
                    if search_again == 'n':
                        input('\nThank you for using our service! ')
                        break

                # Artist details
                elif know_more_details == 'artist':
                    know_more_details = input('\nWhich artist do you want to know more about? [number] ').lower()
                    while not(know_more_details.strip().isdigit() == True):
                        know_more_details = input('Which artist do you want to know more about? [number] ').lower()
                    num = int(know_more_details) - 1
                    artists = len(query_info['artists']['items'])
                    while not(0 <= num <= artists):
                        know_more_details = input('Which artist do you want to know more about? [number] ').lower()
                        num = int(know_more_details) - 1
                        artists = len(query_info['artists']['items'])

                    a_dict = {'artist': 'Artist: ' + str(a_artist_name[num]),
                              'artist_genre': 'Genre: ' + str(a_artist_genre[num]),
                              'artist_followers': 'Followers: ' + str(a_artist_followers[num]),
                              'artist_popularity': 'Popularity: ' + str(a_artist_popularity[num]),
                              'artist_link': 'Spotify: ' + str(a_artist_link[num]),
                              }

                    artist_details = '\n' + a_dict['artist'] + '\n' + a_dict['artist_genre'] + '\n' + a_dict['artist_followers'] + '\n' + a_dict['artist_popularity'] + '\n' + a_dict['artist_link']
                    print(artist_details)

                    # Iterate search
                    search_again = input('\nDo you want to search again? [y/n] ').lower()
                    while not(search_again == 'y' or search_again == 'n'):
                        search_again = input('Do you want to search again? [y/n] ').lower()
                    if search_again == 'n':
                        input('\nThank you for using our service! ')
                        break

                # Album details
                else:
                    know_more_details = input('\nWhich album do you want to know more about? [number] ').lower()
                    while not(know_more_details.strip().isdigit() == True):
                        know_more_details = input('Which album do you want to know more about? [number] ').lower()
                    num = int(know_more_details) - 1
                    albums = len(query_info['albums']['items'])
                    while not(0 <= num <= albums):
                        know_more_details = input('Which album do you want to know more about? [number] ').lower()
                        num = int(know_more_details) - 1
                        albums = len(query_info['albums']['items'])

                    al_dict = {'album': 'Album: ' + str(al_album_name[num]),
                               'album_tracks': 'Total Tracks: ' + str(al_album_total_tracks[num]),
                               'album_release': 'Release Date: ' + str(al_album_release_date[num]),
                               'album_link': 'Spotify: ' + str(al_album_link[num]),
                               'artist': 'Artist: ' + str(al_artist_name[num]),
                               'artist_link': 'Spotify: ' + str(al_artist_link[num]),
                               }

                    album_details = '\n' + al_dict['album'] + '\n' + al_dict['album_tracks'] + '\n' + al_dict['album_release'] + '\n' + al_dict['album_link'] + '\n---\n' + al_dict['artist'] + '\n' + al_dict['artist_link']
                    print(album_details)

                    # Iterate search
                    search_again = input('\nDo you want to search again? [y/n] ').lower()
                    while not(search_again == 'y' or search_again == 'n'):
                        search_again = input('Do you want to search again? [y/n] ').lower()
                    if search_again == 'n':
                        input('\nThank you for using our service! ')
                        break
            # Album details
            if know_more_details == 'album':
                know_more_details = input('\nWhich album do you want to know more about? [number] ').lower()
                while not(know_more_details.strip().isdigit() == True):
                    know_more_details = input('Which album do you want to know more about? [number] ').lower()
                num = int(know_more_details) - 1
                albums = len(query_info['albums']['items'])
                while not(0 <= num <= albums):
                    know_more_details = input('Which album do you want to know more about? [number] ').lower()
                    num = int(know_more_details) - 1
                    albums = len(query_info['albums']['items'])

                al_dict = {'album': 'Album: ' + str(al_album_name[num]),
                           'album_tracks': 'Total Tracks: ' + str(al_album_total_tracks[num]),
                           'album_release': 'Release Date: ' + str(al_album_release_date[num]),
                           'album_link': 'Spotify: ' + str(al_album_link[num]),
                           'artist': 'Artist: ' + str(al_artist_name[num]),
                           'artist_link': 'Spotify: ' + str(al_artist_link[num]),
                           }

                album_details = '\n' + al_dict['album'] + '\n' + al_dict['album_tracks'] + '\n' + al_dict['album_release'] + '\n' + al_dict['album_link'] + '\n---\n' + al_dict['artist'] + '\n' + al_dict['artist_link']
                print(album_details)

                # Iterate search
                search_again = input('\nDo you want to search again? [y/n] ').lower()
                while not(search_again == 'y' or search_again == 'n'):
                    search_again = input('Do you want to search again? [y/n] ').lower()
                if search_again == 'n':
                    input('\nThank you for using our service! ')
                    break