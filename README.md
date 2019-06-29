# audio-streamer
a sync audio player

## dependencies

`boost-1.65(tested only on this version)`
`pyglet`
`libavbin`
`picoSHA2`

## compile instructions

`cd src`

`g++ -o server test_server.cpp test_filetransfer.cpp utils.cpp network_manager.cpp client_handler.cpp thread_handler.cpp -lboost_system -lboost_thread -lpthread`

`g++ -o client client.cpp network_manager.cpp -lboost_system`

## usage

`./test_server`
`./client`

type "play" and press enter twice in the server console to start playing audio on all clients once all of them are connected and file is transferred
