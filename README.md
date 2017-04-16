# weather_notifier
Weather notifier based on client-server model.
The server uses the wundergroung_wrapper to contact the wunderground server for the weather updates.
Clients communicate over TCP with the server. 
Server can send updates to each client if there is any notification.
Server multithreaded in the sense that it creates new thread for each client connection accepted.


Makefile : for client, server on ./
Makefile for wunderground api: on ./wunderground_api
