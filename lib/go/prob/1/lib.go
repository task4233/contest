package main

import (
	"bufio"
	"io"
	"os"
	"strconv"
)

// ----------------------------------------
// Util
//-----------------------------------------

// mod returns an integer = val (mod m)
func mod(val, m int) (int, error) {
	if m == 0 {
		return -1, zeroDivErr
	}

	res := val % m
	if res < 0 {
		res += m
	}
	return res, nil
}

// chmin adapts targetVal as updatedVal if updatedVal > target
func chmin(updatedVal *int, targetVal int) (bool, error) {
	if updatedVal == nil {
		return false, nilErr
	}

	if *updatedVal > targetVal {
		*updatedVal = targetVal
		return true, nil
	}
	return false, nil
}

// chmax adapts targetVal as updatedVal if updateVal < target
func chmax(updatedVal *int, targetVal int) (bool, error) {
	if updatedVal == nil {
		return false, nilErr
	}

	if *updatedVal < targetVal {
		*updatedVal = targetVal
		return true, nil
	}
	return false, nil
}

// sum returns sum of integers
func sum(integers ...int) int {
	var s int = 0
	for _, i := range integers {
		s += i
	}
	return s
}

// abs returns absolute value for integer
func abs(val int) int {
	if val < 0 {
		return -val
	}
	return val
}

// pow returns a^e with O(log_2^e)
func pow(a, e int) (int, error) {
	if a < 0 || e < 0 {
		return -1, negativeValErr
	}

	if e == 0 {
		return 1, nil
	}

	if e%2 == 0 {
		halfE := e / 2
		half, err := pow(a, halfE)
		if err != nil {
			return -1, err
		}
		return half * half, nil
	}

	if val, err := pow(a, e-1); err != nil {
		return -1, err
	} else {
		return a * val, nil
	}
}

// ----------------------------------------
// I/O
//-----------------------------------------

var (
	// READString
	reads  func() string
	stdout *bufio.Writer
)

// init inits I/O
func init() {
	reads = newReadString(os.Stdin, bufio.ScanWords)
	stdout = bufio.NewWriter(os.Stdout)
}

// newReadString returns func for reading
func newReadString(ior io.Reader, sf bufio.SplitFunc) func() string {
	r := bufio.NewScanner(ior)
	r.Buffer(make([]byte, 1024), int(1e9+7))
	r.Split(sf)

	return func() string {
		if !r.Scan() {
			panic("scan failed")
		}
		return r.Text()
	}
}

// readi returns an interger
func readi() int {
	return int(_readInt64())
}

// _readInt64 returns int64 with parsing strconv.ParseInt
func _readInt64() int64 {
	i, err := strconv.ParseInt(reads(), 0, 64)
	if err != nil {
		panic(err.Error())
	}
	return i
}

// readis returns an integer slice which has n integers
func readis(n int) []int {
	b := make([]int, n)
	for i := 0; i < n; i++ {
		b[i] = readi()
	}
	return b
}

// readf returns an float64
func readf() float64 {
	return float64(_readFloat64())
}

// _readFloat64 returns float64 with parsing strconv.ParseFloat
func _readFloat64() float64 {
	f, err := strconv.ParseFloat(reads(), 64)
	if err != nil {
		panic(err.Error())
	}
	return f
}

// readfs returns an float64 slice which has n float64
func readfs(n int) []float64 {
	b := make([]float64, n)
	for i := 0; i < n; i++ {
		b[i] = readf()
	}
	return b
}
