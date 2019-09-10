while true; do
    echo "make"
    ./make_random.out > input.txt
    echo "check"
    ans1=$(./c < input.txt)
    ans2=$(./c2 < input.txt)
    if [ "$ans1" != "$ans2" ]; then
        echo "Wrong Answer"
        echo $ans1
        echo $ans2
        exit
    fi
done
