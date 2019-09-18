while true; do
    ./make > input
    echo "r" & lldb ./c < input & sleep 100 & echo "q" & echo "y"
    
done
