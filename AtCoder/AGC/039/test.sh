while true; do
    ./test > input.txt
    ans1=$(./a < input.txt)
    ans2=$(./aa < input.txt)
    echo ${ans1}
    echo ${ans2}
    if [ ${ans1} != ${ans2} ]; then
        echo "Wrong Answer"
        echo $ans1
        echo $ans2
        exit
    fi
done
