nohup raspivid -o - -t 0 -n -w 600 -h 400 -fps 24 | cvlc -vvv stream:///dev/stdin --sout '#rtp{sdp=rtsp://:8554/}' :demux=h264 &
nohup python ~/TrafficNetPeons/TrafficNetWebInterface/TrafficNet.py &
