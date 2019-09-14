while true; do
    ./rnd > input.txt
    echo "makeRnd"
    ans1=$(./c < input.txt)
    ans2=$(./c2 < input.txt)
    if [ "$ans1" != "$ans2" ]; then
        echo "Wrong Answer"
        echo $ans1
        echo $ans2
        cat input.txt
        exit
    fi
    echo "ok"
done
